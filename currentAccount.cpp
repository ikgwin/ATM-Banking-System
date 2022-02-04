#include <iostream>
#include <string>
#include "Account.h"
#include "savingsAccount.h"
#include "currentAccount.h"

using namespace std;

currentAccount::currentAccount(string accOwner) : Account(accOwner) {
    interestRate = 0.25;
    this->maxDepositAmmount = 100000000;
    this->maxWithdrawlAmmount = 5000;
}

void currentAccount::Deposit(int depAmmount) {
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

void currentAccount::Withdraw(int wdAmmount) {
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

void currentAccount::generateReportSummary() {
    cout << "Current Account Report: " << endl << endl;
    Account::generateReportSummary();
}

currentAccount::~currentAccount() {}
