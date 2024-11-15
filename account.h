#ifndef account_h
#define account_h

class Account{
    private:
        double amount;
    public:
        ~Account(){}
        void takeMoney(double money) {
            amount -= money;
        }
        void addMoney(double money) {
            amount += money;
        }
};

#endif