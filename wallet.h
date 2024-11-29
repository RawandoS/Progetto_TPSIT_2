#include <iostream>
using namespace std;

#ifndef wallet_h
#define wallet_h
class account;

class Wallet{
    private:
        double amount;



    public:
        Wallet() : amount{ rand() % 101+100.0} {};
        ~Wallet(){}
        void setAmount(double m);
        void addMoney(double m);
        void status();
        bool getAmount();
};

#endif