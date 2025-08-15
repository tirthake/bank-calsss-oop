
**Bank Account Management System in C++**
**This project implements a simple Bankaccount class in C++ to demonstrate fundamental object-oriented programming (OOP) concepts. The program showcases various features of C++ including classes, constructors, method overloading, static members, friend functions, and the copy constructor.**

**Features**
The program is designed to fulfill the following tasks:

**Complete Bankaccount Class:** A class to model a bank account, encapsulating data and operations.

**Multiple Constructors:** Creation of objects using default, parameterized, and copy constructors.

**Core Account Methods:**  Functions for depositing, withdrawing, and transferring funds between accounts.

**Function Overloading:** Demonstrating multiple functions with the same name but different parameters.

**Friend Function:** Using a non-member function to access private members of the class.

**Static Variable:** A shared variable to track a global state across all objects of the class.

**Copy Constructor:** Creating a new object as a copy of an existing one.

Program Description
1. **The Bankaccount Class**
The core of the program is the Bankaccount class, which has private members to store account details (accountNumber, accountHolder, balance, accountType) and a transaction count specific to each account (transactionCount). It also has a static member totalTransactions which is shared by all Bankaccount objects.

2. **Constructors and Object Creation**
The program creates four Bankaccount objects to demonstrate different constructor types:

Bankaccount acc1;: Uses the default constructor.

Bankaccount acc2(string("1234"), string("alice"), 5000.0, string("savings"));: Uses the parameterized constructor to initialize an account with specific values. Note the explicit string(...) usage to resolve a compilation ambiguity.

Bankaccount acc3(string("1256"), string("bob"), 10000.0, string("current"));: Another object created using the parameterized constructor.

Bankaccount acc4(acc2);: Uses the copy constructor to create acc4 as an exact replica of acc2 at the time of creation.

3. Method Demonstrations
The main function calls various methods to simulate banking operations:

acc1.deposit(...): Adds money to an account.

acc2.withdraw(...): Removes money from an account.

acc3.transfer(acc2, ...): Transfers a specified amount from acc3 to acc2. The transfer method internally calls the withdraw and deposit methods.

4. Function Overloading
The deposit method is overloaded. There are two versions:

**double deposit(double Damount): For depositing double-precision floating-point numbers.**

**double deposit(float Damount): For depositing single-precision floating-point numbers.**

5. Friend Function
The compareAccounts function is declared as a friend of the Bankaccount class. This allows it to directly access the private balance and accountHolder members of the two Bankaccount objects passed as arguments, enabling it to compare their balances without needing public getter methods.

6. Static Variable
The totalTransactions variable is a static member. **It is shared across all Bankaccount objects and is incremented every time a deposit or withdrawal occurs on any account.** This allows the program to track the total number of banking operations performed globally, which is then displayed at the end.

7. Copy Constructor Usage
The Bankaccount acc4(acc2); line demonstrates the copy constructor. **The acc4 object is created with the initial state of acc2. The program then calls acc4.displayinfo("copy")** to show that it holds the same information as acc2 before any transactions were made on acc2.
