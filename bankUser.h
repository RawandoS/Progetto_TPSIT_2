#include <iostream>

using namespace std;

#ifndef bankUser_h
#define bankUser_h

class BankUser
{
private:
    string ID;
    string userName;
    double balance;
    double wallet;
    int timeSpent;

public:
    BankUser(string userName);
    ~BankUser() {};
    void takeMoney(double m);
    void addMoney(double m);
    void status();
    void investment(double amount, char period, char risk);
    string getID();
    string getUserName();
    void monthBonus();
    void moveForward(int t);
};

#endif