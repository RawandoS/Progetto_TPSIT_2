#include "wallet.h"

void Wallet::takeMoney(double m){
    amount -= m;
}

void Wallet::addMoney(double m){
    amount += m;
}

void Wallet::status(){
    cout << "Available balance: " << amount << "€\n";
}