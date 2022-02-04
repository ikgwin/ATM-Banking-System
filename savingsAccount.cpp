#include <iostream>
#include <string>
#include "Account.h"
#include "savingsAccount.h"

using namespace std;

savingsAccount::savingsAccount(string accOwner) : Account(accOwner) {
    interestRate = 3.5;
    this->maxDepositAmmount = 50000;
    this->maxWithdrawlAmmount = 10000;
}

void savingsAccount::Deposit(int depAmmount) {
    depositAmmount = depAmmount;
    if (depositAmmount > maxDepositAmmount) {
        cout << "You cannot deposit more than $" << maxDepositAmmount << endl;
    } else {
        balance += depAmmount;
        cout << "Deposit Accepted" << endl;
        cout << "Balance: $" << balance << endl;
        transactionSummary += "\n Deposit: +$" + to_string(depositAmmount);
    }
}

void savingsAccount::Withdraw(int wdAmmount) {
    withdrawAmmount = wdAmmount;
    if (balance >= withdrawAmmount && withdrawAmmount <= maxWithdrawlAmmount) {
        balance -= wdAmmount;
        cout << "Withdrawl Accepeted." << endl;
        cout << "Balance: $" << balance << endl;
        transactionSummary += + "\n Withdraw: -$" + to_string(withdrawAmmount);
    } else if (balance <= withdrawAmmount && withdrawAmmount <= maxWithdrawlAmmount) {
        cout << "Withdraw Failed: Insufficient funds." << endl;
        cout << "Balance: $" << balance << endl;
    } else {
        cout << "Withdraw Failed: Maximum withdraw ammount exceeded" << endl;
    }
}

void savingsAccount::generateReportSummary() {
    cout << "Savings Account Report: " << endl << endl;
    Account::generateReportSummary();
}


savingsAccount::~savingsAccount() {}