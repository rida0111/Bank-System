#pragma once
#include<iostream>
#include"clsScrean.h"

using namespace std;

class clsWithDrawScreen :protected clsScrean
{

private:

	static void _PrintClient(clsBankClient Client)
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

	static string _ReadAccountNumber()
	{
		string AccountNum;
		cout << "\nPlease Enter Account Number? ";
		cin >> AccountNum;

		return AccountNum;
	}

public:

	static void ShowWithDrawScreen()
	{
		_DrawScreenHeader("WithDraw Screen");

		string AccountNumber;

		AccountNumber = _ReadAccountNumber();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient With [" << AccountNumber << "] Not exists.\n";
			AccountNumber = _ReadAccountNumber();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);
		_PrintClient(Client);

		int Amount = 0;

		cout << "\nPlease enter WithDraw amount ? ";
		cin >> Amount;

		if (!Client.WithDraw(Amount))
		{
			do
			{
				cout << "\namount Exceeds the balance,you can  WithDraw up to:";
				cout << Client.AccountBalance;
				cout << "\n\nPlease enter anther amount?";
				cin >> Amount;

			} while (Amount > Client.AccountBalance);

		}

		Client.WithDraw(Amount);
		cout << "\nAmount WithDraw Successfully.\n";
		cout << "\nNew Balance Is : " << Client.AccountBalance;

	}

};