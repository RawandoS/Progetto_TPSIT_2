#include "account.h"

void Account::takeMoney(double m){
    amount -= m;
}

void Account::addMoney(double m){
    amount += m;
}

void Account::status(){
    cout << "Available balance: " << amount << "€\n";
    cout << "Invested amount: " << invested_amount << "€\n";
}

void Account::shortTermInvestment(double m){ //30 days
    if(m > amount){
        cout << "Invalid input\n";
    }else{
        amount -= m;
        invested_amount += m;
        days += 30;

        double increment{0};

        for(int i{0}; i<30; i++){
            if((rand() % 101) % 2 == 0){
                increment += ((rand() % 1001)/100)*m;
            }else{
                increment -= ((rand() % 1001)/100)*m;
            }
        }

        if(increment < 0){
            cout << "You have lost " << (increment/m)*100 << "'%' of your investment\n";
        }else{
            cout << "You have earned " << (increment/m)*100 << "'%' of your investment\n";
        }

        cout << "Your current balance is: " << amount << "€\n";
    }
}