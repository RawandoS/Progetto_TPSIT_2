#include <iostream>
#include <cmath>
#include "customer.h"
#include <vector>

using namespace std;

#ifndef bank_h
#define bank_h

class Bank{
    private:
        vector <Customer> customerList;
        double amount;
        int days; //time in days
    public:
        Bank():amount{0}, days{0}{}
        ~Bank(){}
        void takeMoney(double m);
        void depositMoney(double m);
        void status();
        void investment(double m);
        vector <Customer> getList() {
            return customerList;
        }
        void addCustomer(Customer C);
};

#endif