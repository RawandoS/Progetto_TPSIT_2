#include "account.h"

void Account::takeMoney(double m){
    amount -= m;
}

void Account::addMoney(double m){
    amount += m;
}

void Account::status(){
    cout << "Available balance: " << amount << "€\n";
}

void Account::investment(double m, int term = 1){   // 1(default) -> short term(30d)
    if(amount == 0 || m > amount){                  // 2 -> medium term(180d)
        cout << "You don't have enough founds.\n";  // 3 -> long term(360d)
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

    int x{0};
    double initial_investment{m};

    cout << "Amount invested: " << m << "€\n";

    // for(int i{0}; i<period; i++){
    //     x = rand()%101;
    //     if(x%2 != 0) x *= -1;
    //     m = (x/100.0)*initial_investment;
    // }

    // if(m - initial_investment > 0){
    //     cout << "You have earned " << m - initial_investment << "€, +" << ((m - initial_investment)/initial_investment)*100 << "% of your investment.\n";
    // }else{
    //     cout << "You have lost " << m - initial_investment << "€, " << ((m - initial_investment)/initial_investment)*100 << "% of your investment.\n";
    // }

    // cout << "Your current balance is: " << amount << ".\n";

    //fix investment func
    //every month +100 feature to be added
}