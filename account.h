#include <iostream>
#include <cmath>


using namespace std;

#ifndef account_h
#define account_h

class Account{
    private:
        double amount;
        double invested_amount;
        int days; //time
    public:
        Account():amount{((rand()%90001)+10000)/100.0}, invested_amount{0}, days{0}{}

        ~Account(){}

        void takeMoney(double money){
            amount -= money;
        }

        void addMoney(double money){
            amount += money;
        }

        void status(){
            cout << "Amount available: " << amount << "€\n";
            cout << "Amount invested: " << invested_amount << "€\n";
        }

        void shortTermInvestment(double money){ //30 days
            if(money > amount){
                cout << "Invalid input\n";
            }else{
                amount -= money;
                invested_amount += money;
                days += 30;

                double increment{0};

                for(int i{0}; i<30; i++){
                    if((rand() % 101) % 2 == 0){
                        increment += ((rand() % 1001)/100)*money;
                    }else{
                        increment -= ((rand() % 1001)/100)*money;
                    }
                }

                if(increment < 0){
                    cout << "You have lost " << (increment/money)*100 << "'%' of your investment\n";
                }else{
                    cout << "You have earned " << (increment/money)*100 << "'%' of your investment\n";
                }

                cout << "Your current balance is: " << amount << "€\n";
            }
        }
};

#endif