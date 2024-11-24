#include <iostream>
#include <cmath>

using namespace std;

#ifndef account_h
#define account_h

class Account{
    private:
        double amount;
        int days; //time in days
    public:
        Account():amount{((rand()%90001)+10000)/100.0}, days{0}{}
        ~Account(){}
        void takeMoney(double m);
        void addMoney(double m);
        void status();
        void investment(double m, int term);
};

#endif