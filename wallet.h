#ifndef wallet_h
#define wallet_h

class Wallet{
    private:
        double amount;
    public:
        ~Wallet(){}

        void takeMoney(double money){
            amount -= money;
        }

        void addMoney(double money){
            amount += money;
        }
};

#endif