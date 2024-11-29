#include <iostream>
#include "customer.h"
#include "bank.h"
#include "wallet.h"
using namespace std;

int main()
{
    int bank_option{ -1 }; 
    double money{ 0 };
    Bank bank1;
    cout << "Enter the username of the account you want to create"<<endl;
    string name;
    cin >> name;
    cout << "Enter the amount of money you have in your wallet" << endl;
    cin >> money;

    Customer customer1{ name, money};
    bank1.addCustomer(customer1);
    while (bank_option==-1)
    {
        cout << endl;
        cout << "***************************************************" << endl;
        cout << "- - - - - - - What you want to do now? - - - - - -" << endl;
        cout << endl;
        cout << "             You have several options" << endl;
        cout << endl;
        cout << " - Deposit money                    (Digit 1)" << endl;
        cout << " - Take money                       (Digit 2)" << endl;
        cout << " - Invest an amount of money        (Digit 3)" << endl;
        cout << " - Watch your own wallet            (Digit 4)" << endl;
        cout << " - Watch your bank account status   (Digit 5)" << endl;
        cout << " - Exit                             (Digit 0)" << endl;
        cout << endl;
        cin >> bank_option;
        cout << endl;
        cout << "***************************************************" << endl;
        if (bank_option==1)
        {
            cout << "Enter the total amount to deposit " << endl;
            cout << endl;
            cin >> money;
            bank1.depositMoney(money);
            cout << endl;

        }
        else if (bank_option==2)
        {
            cout << "Enter the total amount of money to take" << endl;
            cout << endl;
            cin >> money;
            bank1.takeMoney(money);
            cout << endl;
        }
        else if (bank_option==3)
        {
            cout << "Enter the total amount to invest" << endl;
            cout << endl;
            cin >> money;
            bank1.investment(money);
            cout << endl;
        }
        else if (bank_option==4)
        {
            bank1.getList()[1].getWallet().status();
            cout << endl;
        }
        else if (bank_option==5)
        {
            bank1.status();
            cout << endl;
        }
        bank_option = -1;
    }

    
    return 0;
}

//aggiunto 100 al mese 
//aggiunti rischi
//aggiunta interfacci grafica
//fare controlli funzionamento codice per tutti i casi
//inserire do until per inserimento sbagliato nelle funzioni


