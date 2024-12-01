#include <iostream>
#include <string>
#include "bank.h"
#include "bankUser.h"

using namespace std;

void welcomeMessage();
void userInterface();

int main()
{

    Bank B;
    int accountIndex = 0;

    cout << "\n" << B.getName() << " Group\n";
    welcomeMessage();

    char opt;
    cin >> opt;

    if (opt == 'n')
    {
        string userName;
        cout << "\nType your full name [Surname Name]: ";
        cin.ignore();
        getline(cin, userName);

        B.addBankUser(userName);
        accountIndex = B.getBankUserRecord().size() - 1;
    } // else if(opt == 'a'){  }

    cout << "\nWelcome " << B.getBankUser(accountIndex).getUserName() << '\n';

    do
    {
        userInterface();
        cin >> opt;

        switch (opt)
        {
        case 's':
        {
            B.getBankUser(accountIndex).status();
            break;
        }
        case 'd':
        {
            int m = 0;
            cout << "\nType the desired import: " << '\n';
            cin >> m;
            B.getBankUser(accountIndex).addMoney(m);
            break;
        }
        case 'w':
        {
            int m = 0;
            cout << "\nType the desired import: " << '\n';
            cin >> m;
            B.getBankUser(accountIndex).takeMoney(m);
            break;
        }
        case 'i':
        {
            int a = 0;
            cout << "\nType the desired import: ";
            cin >> a;

            char p;
            cout << "\nType the desired period: " << '\n';
            cout << "Type 's' for short period investment (30 days).\n";
            cout << "Type 'm' for medium period investment (180 days).\n";
            cout << "Type 'l' for long period investment (360 days).\n";
            cout << "Option: ";
            cin >> p;

            char r;
            cout << "\nType the desired risk: " << '\n';
            cout << "Type 'l' for low risk investment (up to +100%).\n";
            cout << "Type 'm' for medium risk investment (up to +500%).\n";
            cout << "Type 'h' for high risk investment (up to +1000%).\n";
            cout << "Option: ";
            cin >> r;

            B.getBankUser(accountIndex).investment(a, p, r);
            break;
        }
        case 't':
        {
            int t = 0;
            cout << "\nHow many days would you like to spend?: ";
            cin >> t;

            B.getBankUser(accountIndex).moveForward(t);
            break;
        }
        // case 'l':{
        //     cout << "\nLog out completed.\n";
        //     welcomeMessage();
        //     break;
        // }
        case 'e':
        {
            cout << "\nThanks for relying on us.\n";
            cout << '\n' << B.getName() << " Group\n";
            break;
        }
        default:
        {
            cout << "\nInvalid option.\n";
            break;
        }
        }
    } while (opt != 'e');

    return 0;
}

void welcomeMessage()
{
    cout << "\n***********************************************************\n";
    cout << "WELCOME TO THE BANK PORTAL\n";
    cout << "New Customer? Type 'n' to create a new Account.\n";
    // cout << "Already a Customer? Type 'a' to login.\n";
    cout << "***********************************************************\n";
    cout << "Option: ";
}

void userInterface()
{
    cout << "\n***********************************************************\n";
    cout << "Choose the desired option:\n";
    cout << "Type 's' to view your current balance.\n";
    cout << "Type 'd' to deposit founds.\n";
    cout << "Type 'w' to withdraw founds.\n";
    cout << "Type 'i' to invest founds.\n";
    cout << "Type 't' to move time forward.\n";
    // cout << "Type 'l' to log out.\n";
    cout << "Type 'e' to exit.\n";
    cout << "***********************************************************\n";
    cout << "Option: ";
}