#include "wallet.h"

void Wallet::setAmount(double m){
    amount = m;
}

void Wallet::status(){
    cout << "Available balance: " << amount << "€\n";
}

double Wallet::getAmount() {
    return amount;
}