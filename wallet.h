#include <iostream>
using namespace std;

#ifndef wallet_h
#define wallet_h


class Wallet{
    private:
        double amount;
    public:
        Wallet(): amount{0}{}
        ~Wallet(){}
        void takeMoney(double m);
        void addMoney(double m);
        void status();
};

#endif