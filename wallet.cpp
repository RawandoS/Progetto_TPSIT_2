#include "wallet.h"

void Wallet::setAmount(double m){
    amount = m;
}

void Wallet::addMoney(double m){
    amount += m;
}

void Wallet::status(){
    cout << "Available balance: " << amount << "€\n";
}

bool Wallet::getAmount() {
    return amount;
}