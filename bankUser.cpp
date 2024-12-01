#include <iostream>
#include <string>
#include "bankUser.h"

using namespace std;

BankUser::BankUser(string userName) : ID{to_string((rand() % 8999 + 1000))}, userName{userName}, balance{((rand() % 90001) + 10000) / 100.0}, wallet{0}, timeSpent{0} {}

void BankUser::takeMoney(double m)
{
    if (m > balance || balance <= 0)
    {
        cout << "Insufficient founds. The import could not be withdrowed.\n";
    }
    else
    {
        balance -= m;
        wallet += m;
    }
}

void BankUser::addMoney(double m)
{
    if (m > wallet)
    {
        cout << "Insufficient founds. The import could not be deposited.\n";
    }
    else
    {
        balance += m;
        wallet -= m;
    }
}

void BankUser::status()
{
    cout << "\nAvailable balance: " << balance << "€\n";
    cout << "Available wallet: " << wallet << "€\n";
    cout << "Time spent: " << timeSpent << '\n';
}

void BankUser::investment(double amount, char period, char risk)
{
    if (amount > balance || balance <= 0)
    {
        cout << "Insufficient founds.\n";
        return;
    }

    balance -= amount;

    int _period = 0;

    if (period == 's')
    {
        _period = 30;
    }
    else if (period == 'm')
    {
        _period = 180;
    }
    else if (period == 'l')
    {
        _period = 360;
    }
    else
    {
        cout << "Invalid period.\n";
        return;
    }

    int _risk = 0;

    if (risk == 'l')
    {
        _risk = amount + amount * 2;
    }
    else if (risk == 'm')
    {
        _risk = amount + amount * 5;
    }
    else if (risk == 'h')
    {
        _risk = amount + amount * 10;
    }
    else
    {
        cout << "Invalid risk.\n";
        return;
    }

    double _amount = amount;
    timeSpent += _period;

    for (int i{1}; i <= _period; i++)
    {
        _amount = rand() % _risk;

        srand(time(NULL));

        if (rand() % 2 != 0)
        {
            _amount *= -1;
        }

        if (i % 30 == 0)
        {
            this->monthBonus();
        }
    }

    if (risk == 'l' && (_amount < 0.7 * amount))
    {
        _amount = 0.7 * amount;
    }
    else if (risk == 'm' && (_amount < 0.4 * amount))
    {
        _amount = 0.4 * amount;
    }

    cout << "Initial amount invested: " << amount << "€\n";
    cout << "Final amount: " << _amount << "€\n";

    if (_amount > amount)
    {
        cout << "Earned amount: " << _amount - amount << "€\n";
    }
    else if (_amount < amount)
    {
        cout << "Lost amount: " << amount - _amount << "€\n";
    }
    else
    {
        cout << "No amount earned.\n";
    }

    balance += _amount;
}

string BankUser::getID()
{
    return ID;
}

string BankUser::getUserName()
{
    return userName;
}

void BankUser::monthBonus()
{
    wallet += 100;
    cout << "\nA month has passed, 100€ have been deposited in your wallet.\n";
}

void BankUser::moveForward(int t)
{
    timeSpent += t;

    for(int i{0}; i<t/30; i++){
        this->monthBonus();
    }
}