#pragma once

#include <iostream>
#include "clsScrean.h"
#include "clsBankClient.h"

using namespace std;

class clsDepositClient :protected clsScrean
{

private:

	static void Print(clsBankClient Client)
	{
		cout << "\nClient Card:" << endl;
		cout << "_________________________";

		cout << "\nFirstName : " << Client.FirstName;
		cout << "\nLastName  : " << Client.LastName;
		cout << "\nFull Name : " << Client.FullName();
		cout << "\nEmail     : " << Client.Email;
		cout << "\nPhone     : " << Client.Phone;
		cout << "\nAcc.Number: " << Client.AccountNumber();
		cout << "\nPassword  : " << Client.PinCode;
		cout << "\nbalance   : " << Client.AccountBalance;

		cout << "\n_________________________\n";
	}

	static bool _DepositAccountBalance(int Deposit, vector<clsBankClient>& vClient, clsBankClient& Client)
	{
		for (clsBankClient& S : vClient)
		{
			if (S.AccountBalance == Client.AccountBalance)
			{
				S.AccountBalance += Deposit;
				Client.AccountBalance = S.AccountBalance;
				return true;
			}
		}
		return false;
	}

public:

	static void ShowDepositScreen()
	{
		_DrawScreenHeader("Deposit Screen");

		string AccountNumber;

		cout << "\nPlease Enter Account Number ? ";
		cin >> AccountNumber;


		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			cin >> AccountNumber;
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		Print(Client);

		int Amount = 0;

		cout << "\nPlease enter Deposit amount ? ";
		cin >> Amount;

		cout << "\nAre you Sure you Want perform this transaction ? ";
		char Answer = 'n';

		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			Client.Deposit(Amount);

			cout << "\nAmount Deposit Successfully.\n";
			cout << "\nNew Balance Is :" << Client.AccountBalance;
		}
		else
		{
			cout << "\nOperation was cancelled.\n";
		}

	}

};

