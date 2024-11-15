#include "account.h"
#include "wallet.h"

#ifndef customer_H
#define customer_H

class Customer
{
private:
	Account bank;
	Wallet wallet;

public:
	~Customer() {};

	Account getBankAccount(){
		return bank;
	}

	Wallet getWallet(){
		return wallet;
	}
};

#endif