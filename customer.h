#include "account.h"
#include "wallet.h"

#ifndef customer_h
#define customer_h

class Customer{
	private:
		Account bank;
		Wallet wallet;

	public:
		~Customer() {};
		Account getBankAccount();
		Wallet getWallet();
};

#endif