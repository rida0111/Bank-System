#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScrean.h"

using namespace std;

class clsDeleteClientScreen :protected clsScrean
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

public:

	static void ShowDeleteClientScreen()
	{

		if (!CheckAccessRights(clsUser::enPermission::eDelete))
		{
			return;
		}

		_DrawScreenHeader("Delete Client Screen");

		string AccountNumber;
		char char1;

		cout << "\nPlease Enter  Account Number : ";
		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nAccount Number is not found , choose anther one :";
			AccountNumber = clsInputValidate::ReadString();
		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		_PrintClient(Client);

		cout << "\nAre you sure you want to delete this client y/n? ";
		cin >> char1;

		if (char1 == 'Y' || char1 == 'y')
		{

			if (Client.Delete())
			{
				cout << "\nClient Deleted Successfuly :-)\n";
				_PrintClient(Client);
			}

			else
			{
				cout << "\nError Client Was not Deleted\n";
			}

		}

	}

};
