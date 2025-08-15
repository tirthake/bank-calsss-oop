#include <iostream>
#include <string>
using namespace std;




//finally done



class Bankaccount {
private:
    string accountNumber;
    string accountHolder;
    double balance;
    string accountType;
    int transactionCount;
    static int totalTransactions;

public:
    // Default constructor
    Bankaccount() {
        accountNumber = "unknown";
        accountHolder = "unknown";
        balance = 0.0;
        accountType = "unknown";
        transactionCount = 0;
    }

    // Parameterized constructor
    Bankaccount(string accN, string accH, double bl, string accT) {
        accountNumber = accN;
        accountHolder = accH;
        balance = bl;
        accountType = accT;
        transactionCount = 0;
    }

    // Copy constructor
    Bankaccount(const Bankaccount& other) {
        accountNumber = other.accountNumber;
        accountHolder = other.accountHolder;
        balance = other.balance;
        accountType = other.accountType;
        transactionCount = other.transactionCount;
    }

    void setaccountNumber(string accN) { accountNumber = accN; }
    void setaccountHolder(string accH) { accountHolder = accH; }
    void setbalance(double bl) { balance = bl; }
    void setaccountType(string accT) { accountType = accT; }
    void settranscationCount(int traC) { transactionCount = traC; }

    string getaccountNumber() { return accountNumber; }
    string getaccountHolder() { return accountHolder; }
    double getbalance() { return balance; }
    string getaccountType() { return accountType; }
    int gettranscationCount() { return transactionCount; }
    static int gettotalTransactions() { return totalTransactions; }

    double deposit(double Damount) {
        balance += Damount;
        transactionCount++;
        totalTransactions++;
        cout << "Your deposit tk" << Damount << " operation successful" << endl;
        return balance;
    }

    double withdraw(double amount) {
        if (balance >= amount) {
            balance -= amount;
            transactionCount++;
            totalTransactions++;
            cout << "Your withdraw tk" << amount << " operation successful" << endl;
        } else {
            cout << "Insufficient balance" << endl;
        }
        return balance;
    }

    void transfer(Bankaccount &recipient, double amount) {
        if (balance >= amount) {
            this->withdraw(amount);
            recipient.deposit(amount);
            cout << "Transfer of tk" << amount << " to account "
                 << recipient.getaccountNumber() << " successful" << endl;
        } else {
            cout << "Transfer failed: Insufficient balance" << endl;
        }
    }

    void displayinfo() {
        cout << "ACCOUNT NUMBER: " << accountNumber << endl;
        cout << "ACCOUNT HOLDER: " << accountHolder << endl;
        cout << "ACCOUNT BALANCE: " << balance << endl;
        cout << "ACCOUNT TYPE: " << accountType << endl;
        cout << "TRANSACTION COUNT: " << transactionCount << " TIMES" << endl;
    }

    void displayinfo(string copyTag) {
        cout << "COPY ACCOUNT INFO:" << endl;
        this->displayinfo();
    }

    // Overloaded deposit method (float version)
    double deposit(float Damount) {
        balance += Damount;
        transactionCount++;
        totalTransactions++;
        cout << "Your deposit tk" << Damount << " operation successful" << endl;
        return balance;
    }

    friend void compareAccounts(const Bankaccount& acc1, const Bankaccount& acc2);
};

int Bankaccount::totalTransactions = 0;

void compareAccounts(const Bankaccount& acc1, const Bankaccount& acc2) {
    if (acc1.balance > acc2.balance) {
        cout << acc1.accountHolder << " has higher balance (" << acc1.balance
             << ") than " << acc2.accountHolder << " (" << acc2.balance << ")" << endl;
    } else if (acc1.balance < acc2.balance) {
        cout << acc2.accountHolder << " has higher balance (" << acc2.balance
             << ") than " << acc1.accountHolder << " (" << acc1.balance << ")" << endl;
    } else {
        cout << "Both accounts have the same balance (" << acc1.balance << ")" << endl;
    }
}

int main() {
    Bankaccount acc1; // Calls default constructor
    Bankaccount acc2("1234", "alice", 5000.0, "savings"); // Calls parameterized constructor
    Bankaccount acc3("1256", "bob", 10000.0, "current");  // Parameterized
    Bankaccount acc4(acc2); // Copy constructor

    cout << "--- Transactions for Account 1 (Default Constructor) ---" << endl;
    cout<<" "<<endl;

    acc1.deposit(1000.0);
    acc1.deposit(500.0f);
    cout << endl;

    cout << "--- Transactions for Account 2 (Parameterized Constructor) ---" << endl;
    acc2.withdraw(1000.0);
    cout << endl;

    cout << "--- Transfer from Account 3 to Account 2 ---" << endl;
    cout << "Account 2 Balance (Before): " << acc2.getbalance() << endl;
    cout << "Account 3 Balance (Before): " << acc3.getbalance() << endl;
    cout<<endl;

    acc3.transfer(acc2, 2000.0);
    cout << "Account 2 Balance (After): " << acc2.getbalance() << endl;
    cout << "Account 3 Balance (After): " << acc3.getbalance() << endl;
    cout << endl;

    cout << "--- Comparing Accounts 2 and 3 ---" << endl;
    compareAccounts(acc2, acc3);
    cout << endl;

    cout << "--- Overall Statistics ---" << endl;
    cout << "Total transactions across all accounts: " << Bankaccount::gettotalTransactions() << endl;
    cout << "Account 1's transaction count: " << acc1.gettranscationCount() << endl;
    cout << "Account 2's transaction count: " << acc2.gettranscationCount() << endl;
    cout << "Account 3's transaction count: " << acc3.gettranscationCount() << endl;
    cout << endl;

    cout << "--- Copy Constructor Demo ---" << endl;
    acc4.displayinfo("copy");

    return 0;
}
