#include <iostream>
#include <cmath>


using namespace std;

#ifndef account_h
#define account_h

class Account{
    private:
        double amount;
        double invested_amount;
        int days; //time
    public:
        Account():amount{((rand()%90001)+10000)/100.0}, invested_amount{0}, days{0}{}
        ~Account(){}
        void takeMoney(double m);
        void addMoney(double m);
        void status();
        void shortTermInvestment(double m);
};

#endif