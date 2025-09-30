#pragma once

#include <iostream>
#include "clsScrean.h"
#include"clsInputValidate.h"
#include "clsUser.h"

using namespace std;

class clsDeleteUserScreen :protected clsScrean

{

private:

	static void _PrintUser(clsUser User)
	{
		cout << "\nClient Card:" << endl;
		cout << "_________________________";

		cout << "\nFirstName : " << User.FirstName;
		cout << "\nLastName  : " << User.LastName;
		cout << "\nFull Name : " << User.FullName();
		cout << "\nEmail     : " << User.Email;
		cout << "\nPhone     : " << User.Phone;
		cout << "\nAcc.Number: " << User.UserName;
		cout << "\nPassword  : " << User.Password;
		cout << "\nbalance   : " << User.Permissions;

		cout << "\n_________________________\n";
	}

public:

	static void ShowDeleteUserScreen()
	{
		_DrawScreenHeader("Delete User Screen");

		string UserName;

		cout << "\nPlease Enter UserName : ";
		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser Name is not found , choose anther one :";
			UserName = clsInputValidate::ReadString();
		}

		clsUser User1 = clsUser::Find(UserName);

		_PrintUser(User1);

		cout << "\nAre you sure you want to delete this User y/n? ";
		char char1;
		cin >> char1;

		if (char1 == 'Y' || char1 == 'y')
		{

			if (User1.Delete())
			{
				cout << "\nUser Deleted Successfuly :-)\n";
				_PrintUser(User1);
			}

			else
			{
				cout << "\nError User Was not Deleted\n";
			}

		}

	}

};

