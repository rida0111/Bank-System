#pragma once

#include <iostream>
#include"clsInputValidate.h"
#include"clsBankClient.h"
#include"clsScrean.h"

using namespace std;

class clsFindClientScreen :protected clsScrean
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

public:

	static void ShowFindClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermission::eFind))
		{
			return;
		}

		_DrawScreenHeader("Find Client Screen");

		string AccountNumber;

		cout << "Please Enter Account Number ? ";

		AccountNumber = clsInputValidate::ReadString();

		while (!clsBankClient::IsClientExist(AccountNumber))
		{
			cout << "\nClient is Not Found ,Enter anther one : ";
			AccountNumber = clsInputValidate::ReadString();

		}

		clsBankClient Client = clsBankClient::Find(AccountNumber);

		if (!Client.IsEmpty())
		{
			cout << "\nClient Found :-)\n";
		}
		else
		{
			cout << "\nClient Was Not Found :-(\n";
		}
		Print(Client);

	}

};

