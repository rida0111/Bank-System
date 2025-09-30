#pragma once
#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScrean.h"

using namespace std;

class clsUpdateClientScreen :protected clsScrean

{

private:

	static void ReadClientInfo(clsBankClient& Client)
	{

		cout << "Enter FirstName: ";
		Client.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName: ";
		Client.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email: ";
		Client.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		Client.Phone = clsInputValidate::ReadString();

		cout << "\nEnter PinCode: ";
		Client.PinCode = clsInputValidate::ReadString();

		cout << "\nEnter BalanceAccount: ";
		Client.AccountBalance = stod(clsInputValidate::ReadString());

	}

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


public:

	static void ShowUpdateClientScreen()
	{

		if (!CheckAccessRights(clsUser::enPermission::eUpdate))
		{
			return;
		}

		_DrawScreenHeader("Update Client Screen");

		string AccountNumber;

		cout << "\nPlease Enter Client Account Number : ";
		cin >> AccountNumber;

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount number is not found, choose another one: ";
			cin >> AccountNumber;
		}

		clsBankClient Client1 = clsBankClient::Find(AccountNumber);
		Print(Client1);

		cout << "\nAre you Sure you want to Update this Client ? ";
		char Answer = ' ';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			cout << "\n\nUpdate Client Info :" << endl;
			cout << "_________________________\n";

			ReadClientInfo(Client1);

			clsBankClient::enSaveResults SaveResults;

			SaveResults = Client1.Save();

			switch (SaveResults)
			{
			case clsBankClient::svSucceeded:
			{
				cout << "\nAccount Updated Successfully :-)\n";
				Print(Client1);

				break;
			}

			case clsBankClient::svFaildEmptyObject:
			{
				cout << "\nError Account was not saved beacause it's Empty";
				break;
			}
			}
		}

	}

};

