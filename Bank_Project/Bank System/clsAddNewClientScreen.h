#pragma once

#include <iostream>
#include "clsBankClient.h"
#include "clsInputValidate.h"
#include "clsScrean.h"

using namespace std;

class clsAddNewClientScreen :protected clsScrean

{

private:

	static void ReadClientInfo(clsBankClient& Client)
	{

		cout << "\nEnter FirstName: ";
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

	static void ShowAddNewClientScreen()
	{
		if (!CheckAccessRights(clsUser::enPermission::eAdd))
		{
			return;
		}

		_DrawScreenHeader("Add New Client Screen");
		string AccountNumber;

		cout << "Please Enter Account Number : ";
		AccountNumber = clsInputValidate::ReadString();

		while (clsBankClient::IsClientExist(AccountNumber))
		{

			cout << "\nClient Is already exists,Choose another one : ";
			AccountNumber = clsInputValidate::ReadString();

		}

		clsBankClient NewClient = clsBankClient::GetAddNewClientObject(AccountNumber);

		ReadClientInfo(NewClient);

		clsBankClient::enSaveResults SaveResults;

		SaveResults = NewClient.Save();

		switch (SaveResults)
		{
		case  clsBankClient::enSaveResults::svSucceeded:
		{
			cout << "\nAccount Addeded Successfuly :-)\n";
			_PrintClient(NewClient);
			break;
		}
		case clsBankClient::enSaveResults::svFaildEmptyObject:
		{
			cout << "\nError account was not saved because it's Empty";
			break;
		}

		}

	}
};
