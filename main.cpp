#include <iostream>
#include "customer.h"
#include "bank.h"
#include "wallet.h"
using namespace std;

int main()
{
    int bank_option{ 1 }; 
    int money{ 0 };
    Bank bank1;
    cout << "Inserire il nome dell'account su cui si vuole entrareche si vuole creare"<<endl;
    string name;
    cin >> name;
    Customer customer1{ name };
    while (bank_option==1)
    {
        cout << "***************************************************" << endl;

        cout << "You have different options:" << endl;
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
            cout << "***************************************************" << endl;
        }
        else if (bank_option==2)
        {
            cout << "Enter the total amount of money to take" << endl;
            cout << endl;
            cin >> money;
            bank1.takeMoney(money);
            cout << endl;
            cout << "***************************************************" << endl;
        }
        else if (bank_option==3)
        {
            cout << "Enter the total amount of money to take" << endl;
            cout << endl;
            cin >> money;
            bank1.takeMoney(money);
            cout << endl;
            cout << "***************************************************" << endl;
        }
    }

    
    return 0;
}

//aggiunto 100 al mese 
//aggiunti rischi
//da finire interfaccia grafica

