#include <iostream>
using namespace std;

#ifndef wallet_h
#define wallet_h
class account;

class Wallet{
    private:
        double amount;
    public:
        Wallet(double m) : amount{m} {};
        ~Wallet(){}
        void setAmount(double m);
        void status();
        double getAmount();
};

#endif