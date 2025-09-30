#pragma once

#include <iostream>
#include "clsScrean.h"
#include"clsInputValidate.h"
#include "clsUser.h"
#include"clsUtil.h"

using namespace std;

class clsUpdateUserScreen :protected clsScrean
{

private:

	static short GiveUserFullAccess()
	{
		short Permission = 0;

		cout << "\nDo you want to give full access ? y/n ? ";

		char character1 = 'n';
		cin >> character1;

		if (character1 == 'Y' || character1 == 'y')
		{
			return clsUser::enPermission::eAll;
		}

		cout << "\ndo you want to give access to :\n";

		cout << "\nShow client list ? y/n ? ";
		cin >> character1;

		if (character1 == 'Y' || character1 == 'y')
		{
			Permission += clsUser::enPermission::eList;
		}

		cout << "\nAdd New client ? y/n ? ";
		cin >> character1;

		if (character1 == 'Y' || character1 == 'y')
		{
			Permission += clsUser::enPermission::eAdd;
		}

		cout << "\nDelete client ? y/n ? ";
		cin >> character1;

		if (character1 == 'Y' || character1 == 'y')
		{
			Permission += clsUser::enPermission::eDelete;
		}

		cout << "\nUpdate client ? y/n ? ";
		cin >> character1;

		if (character1 == 'Y' || character1 == 'y')
		{
			Permission += clsUser::enPermission::eUpdate;
		}

		cout << "\nFind client ? y/n ? ";
		cin >> character1;

		if (character1 == 'Y' || character1 == 'y')
		{
			Permission += clsUser::enPermission::eFind;
		}

		cout << "\nTransactions? y/n ? ";
		cin >> character1;

		if (character1 == 'Y' || character1 == 'y')
		{
			Permission += clsUser::enPermission::eTransaction;
		}

		cout << "\nManage Users? y/n ? ";
		cin >> character1;

		if (character1 == 'Y' || character1 == 'y')
		{
			Permission += clsUser::enPermission::eManage;
		}

		cout << "\nShow Login Register? y/n ? ";
		cin >> character1;

		if (character1 == 'Y' || character1 == 'y')
		{
			Permission += clsUser::enPermission::eLoginRegister;
		}

		return Permission;
	}

	static void ReadUserInfo(clsUser& User)
	{

		cout << "Enter FirstName: ";
		User.FirstName = clsInputValidate::ReadString();

		cout << "\nEnter LastName: ";
		User.LastName = clsInputValidate::ReadString();

		cout << "\nEnter Email: ";
		User.Email = clsInputValidate::ReadString();

		cout << "\nEnter Phone: ";
		User.Phone = clsInputValidate::ReadString();

		cout << "\nEnter Password: ";
		User.Password = clsInputValidate::ReadString();

		User.Permissions = GiveUserFullAccess();

	}

	static void PrintUserInfo(clsUser Client)
	{
		cout << "\nUser Card:" << endl;
		cout << "_________________________";

		cout << "\nFirstName : " << Client.FirstName;
		cout << "\nLastName  : " << Client.LastName;
		cout << "\nFull Name : " << Client.FullName();
		cout << "\nEmail     : " << Client.Email;
		cout << "\nPhone     : " << Client.Phone;
		cout << "\nUser Name : " << Client.UserName;
		cout << "\nPassword  : " << Client.Password;
		cout << "\nPermissions: " << Client.Permissions;

		cout << "\n_________________________\n";
	}


public:

	static void ShowUpdateUserScreen()
	{
		_DrawScreenHeader("Update User Screen");

		string UserName;

		cout << "\nPlease Enter User Name: ";
		cin >> UserName;

		while (!clsUser::IsUserExist(UserName))
		{
			cout << "\nUser is not found, choose another one: ";
			cin >> UserName;
		}

		clsUser User1 = clsUser::Find(UserName);
		PrintUserInfo(User1);

		cout << "\nAre you Sure you want to Update this User ? ";
		char Answer = 'n';
		cin >> Answer;

		if (Answer == 'Y' || Answer == 'y')
		{
			cout << "\n\nUpdate User Info :" << endl;
			cout << "_________________________\n";

			ReadUserInfo(User1);

			clsUser::enSaveResults SaveResults;

			SaveResults = User1.Save();

		   switch (SaveResults)
		   {
			case clsUser::svSucceeded:
			{
				cout << "\nUser Updated Successfully :-)\n";
				PrintUserInfo(User1);
				break;
			}

			case clsUser::svFaildEmptyObject:
			{
				cout << "\nError User was not saved beacause it's Empty";
				break;
			}

		   }
		}

	}

};



