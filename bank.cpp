#include <iostream>
#include "bank.h"

using namespace std;

Bank::Bank() : name{"Volksbank"} {}

Bank::Bank(string &name) : name{name} {};

Bank::Bank(string &name, vector<BankUser> &bankUserRecord) : bankUserRecord{bankUserRecord}, name{name} {};

string Bank::getName()
{
    return name;
}

vector<BankUser> Bank::getBankUserRecord()
{
    return bankUserRecord;
}

BankUser &Bank::getBankUser(int index)
{
    return bankUserRecord[index];
}

void Bank::addBankUser(string &userName)
{
    bankUserRecord.push_back(userName);
}