#ifndef CURRENTACCOUNT_H
#define CURRENTACCOUNT_H

#include <iostream>
#include <string>
#include "Account.h"
#include "savingsAccount.h"

using namespace std;

class currentAccount : public Account {

    public:
        currentAccount(string accOwner);
        void Deposit(int depAmmount) override;
        void Withdraw(int wdAmmount) override;
        void generateReportSummary() override;
        ~currentAccount();
};

#endif