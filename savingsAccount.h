#ifndef SAVINGSACCOUNT_H
#define SAVINGSACCOUNT_H

#include <iostream>
#include <string>
#include "Account.h"

using namespace std;

class savingsAccount : public Account {

    public:
        savingsAccount(string accOwner);
        void Deposit(int depAmmount) override;
        void Withdraw(int wdAmmount) override;
        void generateReportSummary() override;
        ~savingsAccount();
};

#endif