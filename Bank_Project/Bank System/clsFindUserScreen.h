#pragma once

#include <iostream>
#include"clsInputValidate.h"
#include"clsUser.h"
#include"clsScrean.h"

using namespace std;

class clsFindUserScreen :protected clsScrean
{
private:

	static void _PrintUserInfo(clsUser User)
	{
		cout << "\nUser Card:" << endl;
		cout << "_________________________";

		cout << "\nFirstName : " << User.FirstName;
		cout << "\nLastName  : " << User.LastName;
		cout << "\nFull Name : " << User.FullName();
		cout << "\nEmail     : " << User.Email;
		cout << "\nPhone     : " << User.Phone;
		cout << "\nUser Name : " << User.UserName;
		cout << "\nPassword  : " << User.Password;
		cout << "\nPermissions: " << User.Permissions;

		cout << "\n_________________________\n";
	}

public:

	static void ShowFindUserScreen()
	{
		_DrawScreenHeader("Find User Screen");

		string UserName;

		cout << "Please Enter User Name ? ";

		UserName = clsInputValidate::ReadString();

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser is Not Found ,Enter anther one : ";
			UserName = clsInputValidate::ReadString();

		}

		clsUser User1 = clsUser::Find(UserName);

		if (!User1.IsEmpty())
		{
			cout << "\nUser Found :-)\n";
		}
		else
		{
			cout << "\nUser Was Not Found :-(\n";
		}

		_PrintUserInfo(User1);

	}

};



