#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

using namespace std;

class Account {

    private:

    public:
        string owner; // name of account owner, common for all derived classes
        int maxDepositAmmount; // maximum ammount the user can deposit from selected account
        int maxWithdrawlAmmount; // maximum ammount the user can withdraw from selected account
        int balance = 0; // users account balance
        int depositAmmount; // ammount the user wishes to deposit
        int withdrawAmmount; // ammount the user wishes to withdraw
        float interestRate; // interest rate of selected account
        string transactionSummary; // summary/report of all of the transactions completed on selected account
        int accountNumber; // users unique account number
        int transferAmmount;

        Account(string accOwner); // account constructor
        virtual void Deposit(int depAmmount); // virtual method so that savings/current account must override it to give specific implementaiton 
        virtual void Withdraw(int wdAmmount); // virtual method so that savings/current account must override it to give specific implementaiton 
        virtual void generateReportSummary(); // virtual method so that savings/current account must override it to give specific implementaiton 
        float calculateInterest(); // calculates the interest of whichever account is selected
        int getBalance(); // returns the users account balance
        int getAccNum(); // returns the users account number
        string getOwner(); // returns the users name 
        ~Account(); // account deconstructor
};

#endif

