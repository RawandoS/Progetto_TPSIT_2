#include <iostream>
#include <vector>
#include "bankUser.h"

using namespace std;

#ifndef bank_h
#define bank_h

class Bank
{
private:
    vector<BankUser> bankUserRecord;
    string name;

public:
    Bank();
    Bank(string &name);
    Bank(string &name, vector<BankUser> &bankUserRecord);
    ~Bank() {};
    string getName();
    vector<BankUser> getBankUserRecord();
    BankUser &getBankUser(int index);
    void addBankUser(string &userName);
};

#endif