#include <iostream>
#include <string>
#include <fstream>
#include "Account.h"
#include "savingsAccount.h"
#include "currentAccount.h"

using namespace std;

// Function to check whether or not the user has logged in
bool is_logged_in() {

    string username; // users username
    string password; // users password
    string un; // shorthand username variable used in getline function and confitional check
    string pw; // shorthand password variable used in getline function and confitional check
    
    cout << "Enter username: ";
    cin >> username;

    cout << "Enter password: ";
    cin >> password;

    ifstream read(username + ".txt");
    getline(read, un); // checking the line in the text document and appending the string to varibale un
    getline(read, pw); // checking the line in the text document and appending the string to varibale pw


    if (un == username && pw == password) { // conditional to check if the credentials entered are the same as those entered upon registering
        return true;
    } else {
        return false;
    }
} // end of is_logged_in function

int main() {
    bool atm = true; // bool condition to allow the whole atm to run
    string name; // name of account owner
    int choice; // choice of the user at menu
    int withdrawlAmount; // ammount the user wishes to withdraw
    int depositAmount; // ammount the user wishes to deposit
    string un; // username variable
    string pw; // password variable
    string n; // name variable
    string username; // string containg the users username
    string password; // string containing the users password
    int loginChoice; // users choice regarding what they want to do
    bool loginPrompt = true; // a boolean used to allow the login screen to run


// ---------------------  CODE FOR LOGGING INTO THE PROGRAM AND SAVING CREDENTIALS UPON REGISTERING  -------------------------------------------------


    while (loginPrompt == true) { // running the login screen 
        cout << "1. Register / Open Account\n"
            << "2. Login\n"
            << "3. Exit\n"
            << "Choose an option: ";
        cin >> loginChoice;
        cout << endl;

        if (loginChoice == 1) {
            cout << "Enter an username: "; cin >> username;

            ifstream read(username + ".txt");
            getline(read, un); // reading the line in the text document and appending to un
            getline(read, pw); // " " " " " " " " " " pw
            getline(read, n); // " " " " " " " " " " n

            if (username == un) { // conditional checking if the username is already in use
                cout << "-------------------------------------------------\n\n"
                     << "Username already exists!\n\n"
                     << "-------------------------------------------------\n";
                loginPrompt = true;
            } else { // else create account
                cout << "Choose a password: "; cin >> password;
                cout << "Enter your name: "; cin >> name;
                cout << endl;

                ofstream file;
                file.open(username + ".txt");
                file << username << endl << password << endl << name << endl; // appends all of the variables to a seperate line in the txt doc
                file.close();

                cout << "-------------------------------------------------\n\n"
                     << "Account created.\n\n"
                     << "-------------------------------------------------\n";
                loginPrompt = true; // repeat the while loop (to continue with login or exit)
            }
            
        } else if (loginChoice == 2) {
            bool status = is_logged_in();
            if (!status) {
                cout << "-------------------------------------------------\n\n"
                     << "incorrect login!\n\n"
                     << "-------------------------------------------------\n";
                loginPrompt = true; // repeat the while loop (to try again or exit)
            
            } else {
                cout << "-------------------------------------------------\n\n"
                     << "Successful login.\n\n"
                     << "-------------------------------------------------\n";
                loginPrompt = false; // break the while loop and continue with the banking system
            }

        } else if (loginChoice == 3) {
            cout << "Have a nice day.\n";
            exit(0); // exiting the program

        } else if(!(cin)){ // if user inputs a character rather than an integer 
            cout << "-------------------------------------------------\n"
                 << "INCORRECT INPUT, TRY AGAIN\n";
            cin.clear();
            cin.ignore(1);
            loginPrompt = true;
            cout << "-------------------------------------------------\n\n";

        } else { // if user enters incorrect integer option
            cout << "-------------------------------------------------\n"
                 << "INCORRECT INPUT, TRY AGAIN" << endl;
            loginPrompt = true;
            cout << "-------------------------------------------------\n\n";
            
        }
    } // end of loginPrompt while loop



// ---------------------  CODE THAT HAS THE FUNCTIONING OF THE ATM MACHINE AND USER BEHAVIOUR WITH MONEY  -------------------------------------------------



    // the accounts are created after a successful login is completed and the atm is now able to be used on these accounts
    savingsAccount* savAcc = new savingsAccount(name); // instance of savings account created upon logging in
    currentAccount* currAcc = new currentAccount(name); // instance of current account created upon logging in

    while (atm == true) { // running the atm screen 
        cout << "\nWhat would you like to do:\n\n"
             << "1. Withdraw Money\n"
             << "2. Deposit Money\n"
             << "3. Transfer Money\n"
             << "4. View Balance\n"
             << "5. View Account Report\n"
             << "6. Exit\n\n"
             << "ENTER: "; cin >> choice;
        cout << "-------------------------------------------------\n";


        switch (choice) { // use switch to enter choice of withdrawl, deposit, veiwing of balances, viewing or reports or exiting

            case 1: // WITHDRAWING MONEY
                int accountSelector1; // a variable to check which account the user selects to withdraw from for case 1
                cout << "Which account would you like to withdraw from? \n\n"
                     << "1. Savings Account\n"
                     << "2. Current account\n\n"
                     << "3. Go Back\n\n"
                     << "ENTER: "; cin >> accountSelector1;
                     cout << "-------------------------------------------------\n";
                
                if (accountSelector1 == 1) { // withdraw ammounts affect the savings account
                    cout <<  "How much would you like to withdraw? $";
                    cin >> withdrawlAmount;

                    if (withdrawlAmount < 0 || !(cin)) { // if incorrect input then invalid
                        cout << "INCORRECT INPUT, TRY AGAIN\n";
                        cin.clear();
                        cin.ignore(1);
                        atm = true;
                        cout << "-------------------------------------------------\n\n";
                        break;

                    } else { // else work
                        savAcc->Withdraw(withdrawlAmount);
                        cout << "-------------------------------------------------\n\n";
                        atm = true;
                        break;

                    }
                } else if (accountSelector1 == 2) { // withdraw ammounts affect the current account
                    cout <<  "How much would you like to withdraw? $";
                    cin >> withdrawlAmount;

                    if (withdrawlAmount < 0 || !(cin)) { // if incorrect input then invalid
                        cout << "INCORRECT INPUT, TRY AGAIN\n";
                        cin.clear();
                        cin.ignore(1);
                        atm = true;
                        cout << "-------------------------------------------------\n\n";
                        break;

                    } else { // else work
                        currAcc->Withdraw(withdrawlAmount);
                        cout << "-------------------------------------------------\n\n";
                        atm = true;
                        break;

                    }
                } else if (accountSelector1 == 3) { // user wishes to go back to main screen
                    atm = true;
                    break;

                } else { // when user inputs incorrect value or char
                    cout << "INCORRECT INPUT, TRY AGAIN\n";
                    cin.clear();
                    cin.ignore(1);
                    atm = true;
                    cout << "-------------------------------------------------\n\n";
                    break;
                }
                
            case 2: // DEPOSITING MONEY
                int accountSelector2; // a variable to check which account the user selects to withdraw from for case 2
                cout << "Which account would you like to deposit to? \n\n";
                cout << "1. Savings Account\n"
                     << "2. Current account\n\n";
                cout << "3. Go Back\n\n";
                cout << "ENTER: "; cin >> accountSelector2;
                cout << "-------------------------------------------------\n";
                
                if (accountSelector2 == 1) { // withdraw ammounts affect the savings account
                    cout << "How much would you like to deposit? $";
                    cin >> depositAmount;

                    if (depositAmount < 0 || !(cin)) { // if incorrect input then invalid
                        cout << "INCORRECT INPUT, TRY AGAIN\n";
                        cin.clear();
                        cin.ignore(1);
                        atm = true;
                        cout << "-------------------------------------------------\n\n";
                        break;

                    } else { // else work
                        savAcc->Deposit(depositAmount);
                        cout << "-------------------------------------------------\n\n";
                        atm = true;
                        break;
                    } 
                } else if (accountSelector2 == 2) { // withdraw ammounts affect the current account
                    cout <<  "How much would you like to deposit? $";
                    cin >> depositAmount;

                    if (depositAmount < 0 || !(cin)) { // if incorrect input then invalid
                        cout << "INCORRECT INPUT, TRY AGAIN\n";
                        cin.clear();
                        cin.ignore(1);
                        atm = true;
                        cout << "-------------------------------------------------\n\n";
                        break;

                    } else { // else work
                        currAcc->Deposit(depositAmount);
                        cout << "-------------------------------------------------\n\n";
                        atm = true;
                        break;

                    }
                } else if (accountSelector2 == 3) { // user wishes to go back to main screen
                    atm = true;
                    break;
                    
                } else { // when user inputs incorrect value or char
                    cout << "INCORRECT INPUT, TRY AGAIN\n";
                    cin.clear();
                    cin.ignore(1);
                    atm = true;
                    cout << "-------------------------------------------------\n\n";
                    break;
                }

            case 3: // TRANSFERRING MONEY
                int accountSelector3; // a variable to check which account the user selects to withdraw from for case 3
                cout << "Which transfer would you like? \n\n"
                     << "1. From Savings Account to Current Account\n"
                     << "2. From Current Account to Savings Account\n\n"
                     << "3. Go Back\n\n"
                     << "ENTER: "; cin >> accountSelector3;
                cout << "-------------------------------------------------\n";

                if (accountSelector3 == 1) { // transferring from savings to current acc
                    int transAmmount;
                    cout << "How much would you like to transfer? $";
                    cin >> transAmmount;

                    if (transAmmount < 0 || !(cin)) { // if incorrect input then invalid
                        cout << "INCORRECT INPUT, TRY AGAIN\n";
                        cin.clear();
                        cin.ignore(1);
                        atm = true;
                        cout << "-------------------------------------------------\n\n";
                        break;
                        
                    } else { // else work
                        if (savAcc->balance < transAmmount) { // checks if the savings account balance has the funds or not
                            cout << "Transfer Failed: Insufficient Funds\n";
                            cout << "Savings Account Balance: $" << savAcc->getBalance() << endl;
                            cout << "-------------------------------------------------\n";
                            atm = true;
                            break;

                        } else { // transfers the money from one account to the other
                            savAcc->balance -= transAmmount; // deducting ammount out of savings
                            currAcc->balance += transAmmount; // transferring to curr acc
                            cout << "Transfer Complete.\n"
                                 << "-------------------------------------------------\n";
                            savAcc->transactionSummary += "\n Transfer - Savings Acc to Current Acc: -$" + to_string(transAmmount); // reporting the transfer
                            currAcc->transactionSummary += "\n Transfer - Savings Acc to Current Acc: +$" + to_string(transAmmount); // reporting the transfer
                            atm = true;
                            break;
                        }
                        cout << "-------------------------------------------------\n\n";
                        atm = true;
                        break;

                    }
                } else if (accountSelector3 == 2) { // transferring from current to savings acc
                    int transAmmount;
                    cout << "How much would you like to transfer? $";
                    cin >> transAmmount;

                    if (transAmmount < 0 || !(cin)) { // if incorrect input then invalid
                        cout << "INCORRECT INPUT, TRY AGAIN\n";
                        cin.clear();
                        cin.ignore(1);
                        atm = true;
                        cout << "-------------------------------------------------\n\n";
                        break;
                        
                    } else { // else work
                        if (currAcc->balance < transAmmount) { // checks if the current account balance has the funds or not
                            cout << "Transfer Failed: Insufficient Funds\n"
                                 << "Current Account Balance: $" << currAcc->getBalance() << endl;
                            cout << "-------------------------------------------------\n";
                            atm = true;
                            break;

                        } else {
                            currAcc->balance -= transAmmount; // deducting ammount out of curr acc
                            savAcc->balance += transAmmount; // transferring to savings acc
                            currAcc->transactionSummary += "\n Transfer - Current Acc to Savings Acc: -$" + to_string(transAmmount); // reporting the transfer
                            savAcc->transactionSummary += "\n Transfer - Current Acc to Savings Acc: +$" + to_string(transAmmount); // reporting the transfer
                            cout << "Transfer Complete.\n";
                            cout << "-------------------------------------------------\n";
                            atm = true;
                            break;
                        }
                        cout << "-------------------------------------------------\n\n";
                        atm = true;
                        break;

                    }
                } else if (accountSelector3 == 3) { // user wishes to go back to main screen
                    atm = true;
                    break;

                } else { // when user inputs incorrect value
                    cout << "INCORRECT INPUT, TRY AGAIN\n";
                    cin.clear();
                    cin.ignore(1);
                    atm = true;
                    cout << "-------------------------------------------------\n\n";
                    break;
                }

            case 4: // VIEWING BALANCES
                int accountSelector4; // a variable to check which account the user selects to withdraw from for case 3
                cout << "Which account would you like to view the balance of? \n\n"
                     << "1. Savings Account\n"
                     << "2. Current account\n\n"

                     << "3. Go Back\n\n"
                     << "ENTER: "; cin >> accountSelector4;
                cout << "-------------------------------------------------\n";
                
                if (accountSelector4 == 1) { // withdraw ammounts affect the savings account
                    cout << "Savings Balance: $" << savAcc->getBalance() << endl;
                    atm = true;
                    cout << "-------------------------------------------------\n\n";
                    break;

                } else if (accountSelector4 == 2) { // withdraw ammounts affect the current account
                    cout << "Current Account Balance: $" << currAcc->getBalance() << endl;
                    atm = true;
                    cout << "-------------------------------------------------\n\n";
                    break;

                } else if (accountSelector4 == 3) { // user wishes to go back to main screen
                    atm = true;
                    break;   
                    
                } else { // when user inputs incorrect value
                    cout << "INCORRECT INPUT, TRY AGAIN\n";
                    cin.clear();
                    cin.ignore(1);
                    atm = true;
                    cout << "-------------------------------------------------\n\n";
                    break;
                }

            case 5: // VIEWING REPORTS
                int accountSelector5; // a variable to check which account the user selects to withdraw from for case 4
                cout << "Which account would you like to view the report of? \n\n"
                     << "1. Savings Account\n"
                     << "2. Current account\n\n"
                     << "3. Go Back\n\n"
                     << "ENTER: "; cin >> accountSelector5;
                cout << "-------------------------------------------------\n";
                
                if (accountSelector5 == 1) { // withdraw ammounts affect the savings account
                    savAcc->generateReportSummary();
                    break;

                } else if (accountSelector5 == 2) { // withdraw ammounts affect the current account
                    currAcc->generateReportSummary();
                    break;

                } else if (accountSelector5 == 3) { // user wishes to go back to main screen
                    atm = true;
                    break;

                } else { // when user inputs incorrect value
                    cout << "INCORRECT INPUT, TRY AGAIN\n";
                    cin.clear();
                    cin.ignore(1);
                    atm = true;
                    cout << "-------------------------------------------------\n\n";
                    break;
                }

            case 6: // EXITING PROGRAM
                cout << "Shutting down... ";
                cout << "\nHave a nice day.\n\n";
                
                delete savAcc;
                delete currAcc;

                atm = false;
                break;

            default: // USER ENTERS INCORRECT INPUT OR CHAR
                cout << "INCORRECT INPUT, TRY AGAIN\n";
                cin.clear();
                cin.ignore(1);
                atm = true;
                cout << "-------------------------------------------------\n\n";
                break;
        } // switch cases end
    } // atm while loop end
    return 0;
} // main function end