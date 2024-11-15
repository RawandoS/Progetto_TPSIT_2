#include <iostream>

using namespace std;

#ifndef account_h
#define account_h

class Account{
    private:
        double amount;
        double invested_amount;
    public:
        ~Account(){}

        void takeMoney(double money){
            amount -= money;
        }

        void addMoney(double money){
            amount += money;
        }

        void status(){
            cout << "Amount available: " << amount << '\n';
            cout << "Amount invested: " << invested_amount << '\n';
        }
};

#endif