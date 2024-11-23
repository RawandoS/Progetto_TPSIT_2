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

void Account::investment(double m, int term = 1){ // 1(default) -> short term(30d) | 2 -> medium term(180d) | 3 -> long term(360d)
    if(amount == 0 || m > amount){
        cout << "You don't have enough founds.\n";
        return;
    }

    if(m < 100){
        cout << "Minimum import to invest is 100€.\n";
        return;
    }

    int period{0};

    if(term == 1){
        period = 30;
    }else if(term == 2){
        period = 180;
    }else if(term == 3){
        period = 360;
    }else{
        cout << "Invalid option.\n";
        return;
    }

    amount -= m;
    invested_amount += m;
    days += period;

    double increment{0};
    int x{0};

    // for(int i{0}; i<period; i++){
    //     x = rand()%101;

    //     if(x % 2 == 0){
    //         increment += (x/100)*m;
    //     }else{                          //to fix
    //         increment -= (x/100)*m;
    //     }
        
    //     amount += increment;
    // }
    
    amount += increment;

    cout << period << " days have gone.\n";

    // if(increment == 0){
    //     cout << "You haven't earned any income.\n";
    // }else if(increment < 0){
    //     cout << "You have lost " << increment << "€ (" << (increment/m)*100 << "%) of your investment.\n"; //to fix
    // }else{
    //     cout << "You have earned " << increment << "€ (" << (increment/m)*100 << "%) of your investment.\n"; //to fix
    // }

    cout << "Your current balance is " << amount << "€\n";
}