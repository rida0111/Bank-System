#pragma once

#include<iostream>
#include<fstream>
#include "clsScrean.h"
#include "clsUser.h"
#include "clsInputValidate.h"
#include "clsMainScrean.h"
#include "All.h"
#include"clsDate.h"

using namespace std;

class ClsLoginScreen :protected clsScrean
{

private:
	
	static bool _Login()
	{
		string UserName, Password;

		bool FailLogin = false;
		short FaildLoginCount = 0;

		do
		{

			if (FailLogin)
			{
				cout << "\nInvalid UserName/Password!\n";

				FaildLoginCount++;
				cout << "You have " << (3 - FaildLoginCount) << " Trial(s) to login.\n";

			}

			if (FaildLoginCount == 3)
			{
				cout << "\nYour are Locked after 3 faild trials\n";
				
				return false;
			}
			
			cout << "\nEnter User Name? ";
			UserName = clsInputValidate::ReadString();

			cout << "Enter Password? ";
			Password = clsInputValidate::ReadString();

			CurrentUser = clsUser::Find(UserName, Password);
			FailLogin = CurrentUser.IsEmpty();
		
		} while (FailLogin);

		CurrentUser.RegisterLogIn();
		clsMainScrean::ShowMainMenue();

		return true;

	}

public:

	static bool ShowLoginScreen()
	{
		_DrawScreenHeader("Login Screen");

		return _Login();
	}

};