#include "wallet.h"

#ifndef customer_h
#define customer_h

class Customer{
	private:
		string accountName{ " " };
		Wallet wallet;

	public:
		Customer(string n)
			:accountName{ n }{};
		~Customer() {};
		Wallet getWallet();
};

#endif