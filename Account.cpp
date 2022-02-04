#include <iostream>
#include <string>
#include "Account.h"

using namespace std;

Account::Account(string accOwner) {
    owner = accOwner;
    transactionSummary = "";
    accountNumber ++;
}

void Account::Deposit(int depAmmount) {}

void Account::Withdraw(int wdAmmount) {}

void Account::generateReportSummary() {
    cout << "Account Owner: " << owner << endl;
    cout << "Account Number: " << accountNumber << endl;
    cout << "Account Balance: " << balance << endl;
    cout << "Interest Amount: " << calculateInterest() << endl;
    cout << this->transactionSummary << endl << endl;
    cout << "---- END OF REPORT ----" << endl << endl;
}

float Account::calculateInterest() {
    return (balance * (this->interestRate)) / 100;
}

string Account::getOwner() {
    return owner;
}

int Account::getAccNum() {
    return accountNumber;
}

int Account::getBalance() {
    return balance;
}

Account::~Account() {

}