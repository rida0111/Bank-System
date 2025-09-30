#pragma once
#include<iostream>
#include"clsScrean.h"
#include"clsBankClient.h"
#include"clsInputValidate.h"

using namespace std;

class clsTransferScreen :protected clsScrean
{

private:
 
	static string _ReadAccountNumber()
	{
		string AccountNumber;

		cout << "\nPlease enter Account Number to Transfer From:";

		AccountNumber = clsInputValidate::ReadString();
		
		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount with [" << AccountNumber << "] is Not Found,";

			cout << "Please enter Account Number to Transfer From:";
			AccountNumber = clsInputValidate::ReadString();
		}

		return AccountNumber;
	}

	static void _PrintClient(clsBankClient& Client)
	{
		cout << "\nClient Card:";
		cout << "\n___________________";
		cout << "\nFull Name  : " << Client.FullName();
		cout << "\nAcc.Number : " << Client.AccountNumber();
		cout << "\nBalance    : " << Client.AccountBalance;
		cout << "\n___________________\n";

	}


public:

	static void ShowTransferScreen()
	{
		_DrawScreenHeader("Transfer Screen");

		clsBankClient SourceClient = clsBankClient::Find(_ReadAccountNumber());

		_PrintClient(SourceClient);

		clsBankClient DestinationClient = clsBankClient::Find(_ReadAccountNumber());

		_PrintClient(DestinationClient);

		int Amount;
		cout << "\nEnter Transfer Amount ? ";
		cin >> Amount;

		while (Amount> SourceClient.AccountBalance)
		{
			cout << "\nAmount Exceeds the available balance, ";
			cout << "Enter another Amount ? ";
			cin >> Amount;
		}

		char answer;
		cout << "\nAre you sure you want to perform this operation? ";
		cin >> answer;

		if (answer == 'y' || answer == 'Y')
		{
			if (SourceClient.Transfer(Amount, DestinationClient))
			{

				cout << "\nTransfer done successfully\n";
			}

			else
				cout << "\nTransfer Faild \n";
		}

		_PrintClient(SourceClient);
		_PrintClient(DestinationClient);

	}

};
