#include "bank.h"
#include "customer.h"
#include "wallet.h"
using namespace std;

//double Bank::getAmount() {
//    return amount;
//}


void Bank::addCustomer(Customer C) {
    customerList.push_back(C);
}

void Bank::takeMoney(double m){
    if (amount-m>=0)
    {
        amount -= m;
        customerList[0].getWallet().setAmount(customerList[0].getWallet().getAmount() + m);
        cout << endl;
        cout << "the withdrawal was successful" << endl;
        cout << endl;
    }
    else
    {
        cout << "you don't have enough mony in the bank accoun.t" << endl;
    }

}

void Bank::depositMoney(double m){ 
    if ((customerList[0].getWallet().getAmount())-m>=0)
    {
        amount += m;
        customerList[0].getWallet().setAmount(customerList[0].getWallet().getAmount() - m);
        cout << "The deposit was successful" << endl;
        cout << endl;
    }
    else
    {
        cout<<"You don't have enough money in the wallet." << endl;
        return;
    }

}

void Bank::status(){
    cout << "Available balance: " << amount << "€\n";
}

void Bank::investment(double m){                    
    int term = 1;                                   // 1(default) -> short term(30d)
    if(amount == 0 || m > amount){                  // 2 -> medium term(180d)
        cout << "You don't have enough founds.\n";  // 3 -> long term(360d)
        return;
    }

    if(m < 100){
        cout << "Minimum import to invest is 100€.\n";
        return;
    }
    amount -= m;
    int period{0};


    cout << "***************************************************" << endl;
    cout << endl;
    cout << " - - - - - Enter the investment duration - - - - " << endl;
    cout << endl;
    cout << "                      Options                     " << endl;
    cout << endl;
    cout << " - short term      | 30  days |     (Digit 1)" << endl;
    cout << " - medium term     | 180 days |     (Digit 2)" << endl;
    cout << " - long term       | 360 days |     (Digit 3)" << endl;
    cout << endl;
    cin >> term;
    cout << "***************************************************" << endl;
    cout << endl;

    if(term == 1){
        period = 30;
        days = period;
    }else if(term == 2){
        period = 180;
        days = period;

    }else if(term == 3){
        period = 360;
        days = period;

    }else{
        cout << "Invalid option.\n";
        return;
    }

    int x{ 0 };
    int sign{ 0 };
    double initial_investment{ m };
    int risk{ 1 };
    int timeTravel{ 1 };

    cout << "**********************************************************" << endl;
    cout << endl;
    cout << " - - - - - Enter the different risk/profit margins - - - " << endl;
    cout << endl;
    cout << "                         Options                     " << endl;
    cout << endl;
    cout << " - low risk/profit     | 30  days |     (Digit 1)" << endl;
    cout << " - medium risk/profit  | 180 days |     (Digit 2)" << endl;
    cout << " - long risk/profit    | 360 days |     (Digit 3)" << endl;
    cout << endl;
    cin >> risk;
    cout << "**********************************************************" << endl;
    cout << endl;

    //1(default) ->low risk, low profit
    //2 ->medium risk, medium profit
    //3 ->high risk, high profit

    cout << "Amount invested: " << m << "€\n";

    if (risk == 1) {

        cout << "*********************************************" << endl;
        cout << endl;
        cout << " - - - - - - Move forward in time? - - - - " << endl;
        cout << endl;
        cout << "                 Options                     " << endl;
        cout << endl;
        cout << " - Default (end of duration)    (Digit 1)" << endl;
        cout << " - Move n days forward          (Digit 2)" << endl;
        cout << endl;
        cin >> timeTravel;
        cout << "*********************************************" << endl;
        cout << endl;
        //1->30 days(default) -> end of the month
//2->n(to select)-> every n da 
        if (timeTravel==1)                                  
        {
            timeTravel = -1;
        }
        else if (timeTravel==2)
        {
            cin >> timeTravel;
        }
        else {
            cout << "Invalid option.\n";
            return;
        }

        for (int i{ 0 }; i < period; i++) {
            sign= rand() % 8 + 1;
            x = rand() % 25+1;
            if (sign == 8 ) x *= -1;
            m += (x / 100.0) * initial_investment;
            if (m+(x / 100.0) * initial_investment<0)
            {
                m = 0;
            }
            else
            {
                m += (x / 100.0) * initial_investment;
            }
            if (i==timeTravel)
            {
                i = 0;
                period -= timeTravel;
                timeTravel = 1;
                cout << "*********************************************" << endl;
                cout << endl;
                cout << " - - - - Move forward in time again? - - - - " << endl;
                cout << endl;
                cout << "                 Options                     " << endl;
                cout << endl;
                cout << " - Default (end of duration)    (Digit 1)" << endl;
                cout << " - Move n days forward          (Digit 2)" << endl;
                cout << endl;
                cin >> timeTravel;
                cout << "*********************************************" << endl;
                cout << endl;              //1(default) -> end of the period
                if (timeTravel == 1)                                    //2->n(to select)-> every n day
                {
                    timeTravel = -1;
                }
                else if (timeTravel == 2)                                
                {
                    cin >> timeTravel;
                }
                else {
                    cout << "Invalid option.\n";
                    return;
                }
            }
        }
        if (m - initial_investment > 0) {
            cout << "You have earned " << m - initial_investment << "€, +" << ((m - initial_investment) / initial_investment) * 100 << "% of your investment.\n";
        }
        else {
            cout << "You have lost " << m - initial_investment << "€, " << ((m - initial_investment) / initial_investment) * 100 << "% of your investment.\n";
        }
    }
    else if (risk == 2) {

        cout << "*********************************************" << endl;
        cout << endl;
        cout << " - - - - - - Move forward in time? - - - - " << endl;
        cout << endl;
        cout << "                 Options                     " << endl;
        cout << endl;
        cout << " - Default (end of duration)    (Digit 1)" << endl;
        cout << " - Move one month forward       (Digit 2)" << endl;
        cout << " - Move n days forward          (Digit 3)" << endl;
        cout << endl;
        cin >> timeTravel;
        cout << "*********************************************" << endl;
        cout << endl;                                   //1->30 days(default) -> end of the month
        if (timeTravel==1)                              //2->n(to select)-> every n day
        {                                               //3-> end of the period
            timeTravel = -1;
        }
        else if (timeTravel == 2)                                                                            
        {
            timeTravel = 30;
        }
        else if (timeTravel==3)
        {
            cin >> timeTravel;
        }
        else {
            cout << "Invalid option.\n";
            return;
        }

        for (int i{ 0 }; i < period; i++) {
            sign= rand() % 4 + 1;
            x = rand() % 50 + 1;
            if (x == 4) x *= -1;
            m += (x / 100.0) * initial_investment;
            if (m + (x / 100.0) * initial_investment < 0)
            {
                m = 0;
            }
            else
            {
                m += (x / 100.0) * initial_investment;
            }
            if (i == timeTravel)
            {
                i = 0;
                period -= timeTravel;
                timeTravel = 1;

                cout << "*********************************************" << endl;
                cout << endl;
                cout << " - - - - Move forward in time again? - - - - " << endl;
                cout << endl;
                cout << "                 Options                     " << endl;
                cout << endl;
                cout << " - Default (end of duration)    (Digit 1)" << endl;
                cout << " - Move one month forward       (Digit 2)" << endl;
                cout << " - Move n days forward          (Digit 3)" << endl;
                cout << endl;
                cin >> timeTravel;
                cout << "*********************************************" << endl;
                cout << endl;            //1->30 days(default) -> end of the month
                if (timeTravel==1)
                {
                    timeTravel = -1;
                }
                else if (timeTravel == 2)                                //2->n(to select)-> every n day
                {                                                   //3-> end of the period
                   timeTravel=30;
                }
                else if(timeTravel==3)
                {
                    cin >> timeTravel;
                }
                else {
                    cout << "Invalid option.\n";
                    return;
                }

            }
        }
        if (m - initial_investment > 0) {
            cout << "You have earned " << m - initial_investment << "€, +" << ((m - initial_investment) / initial_investment) * 100 << "% of your investment.\n";
        }
        else {
            cout << "You have lost " << m - initial_investment << "€, " << ((m - initial_investment) / initial_investment) * 100 << "% of your investment.\n";
        }

    }
    else if (risk == 3) {


        cout << "*********************************************" << endl;
        cout << endl;
        cout << " - - - - - - Move forward in time? - - - - " << endl;
        cout << endl;
        cout << "                 Options                     " << endl;
        cout << endl;
        cout << " - Default (end of duration)    (Digit 1)" << endl;
        cout << " - Move one month forward       (Digit 2)" << endl;
        cout << " - Move n days forward          (Digit 3)" << endl;
        cout << endl;
        cin >> timeTravel;
        cout << "*********************************************" << endl;
        cout << endl;                                   //1->30 days(default) -> end of the month
        if (timeTravel == 1)                            //2->n(to select)-> every n day
        {                                               //3-> end of the period
            timeTravel = -1;
        }
        else if (timeTravel == 2)
        {
            timeTravel = 30;
        }
        else if (timeTravel == 3)
        {
            cin >> timeTravel;
        }
        else {
            cout << "Invalid option.\n";
            return;
        }

        for (int i{ 0 }; i < period; i++) {
            sign= rand() % 2 + 1;
            x = rand() % 110 + 1;
            if (x == 2) x *= -1;
            m += (x / 100.0) * initial_investment;
            if (m + (x / 100.0) * initial_investment < 0)
            {
                m = 0;
            }
            else
            {
                m += (x / 100.0) * initial_investment;
            }
            if (i == timeTravel)
            {
                i = 0;
                period -= timeTravel;
                timeTravel = 1;

                cout << "*********************************************" << endl;
                cout << endl;
                cout << " - - - - - - Move forward in time? - - - - " << endl;
                cout << endl;
                cout << "                 Options                     " << endl;
                cout << endl;
                cout << " - Default (end of duration)    (Digit 1)" << endl;
                cout << " - Move one month forward       (Digit 2)" << endl;
                cout << " - Move n days forward          (Digit 3)" << endl;
                cout << endl;
                cin >> timeTravel;
                cout << "*********************************************" << endl;
                cout << endl;            //1->30 days(default) -> end of the month
                if (timeTravel == 1)                                //2->n(to select)-> every n day
                {                                                   //3-> end of the period
                    timeTravel = -1;
                }
                else if (timeTravel == 2)                                
                {                                                  
                    timeTravel = 30;
                }
                else if (timeTravel == 3)
                {
                    cin >> timeTravel;
                }
                else {
                    cout << "Invalid option.\n";
                    return;
                }
            }
        }
        if (m - initial_investment > 0) {
            cout << "You have earned " << m - initial_investment << "€, +" << ((m - initial_investment) / initial_investment) * 100 << "% of your investment.\n";
        }
        else {
            cout << "You have lost " << m - initial_investment << "€, " << ((m - initial_investment) / initial_investment) * 100 << "% of your investment.\n";
        }

        }
    else {
        cout << "Invalid option.\n";
        return;
    }


     amount += m;
     if (amount<0)
     {
         cout << "You have a debt equal to " << amount << ".\n";

     }
     else
     {
         cout << "Your current balance is: " << amount << ".\n";

     }
     
     for (size_t i = 0; i < days/30; i++)
     {
         takeMoney(100);
         amount += 100;
     }
}