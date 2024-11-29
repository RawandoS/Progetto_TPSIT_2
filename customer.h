#include "wallet.h"

#ifndef customer_h
#define customer_h

class Customer{
	private:
		string accountName{ " " };
		Wallet wallet;

	public:
		Customer(string n, double m)
			:accountName{ n }, wallet{m} {};
		~Customer() {};
		Wallet getWallet();
};

#endif