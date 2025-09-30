#pragma once

#include <iostream>
#include"clsBankClient.h"
#include"clsUser.h"
#include"All.h"
#include"clsDate.h"

using namespace std;

class clsScrean
{

protected:

    static void _DrawScreenHeader(string Title, string SubTitle = "")
    {

        cout << "\t\t\t\t\t______________________________________";
        cout << "\n\n\t\t\t\t\t\t " << Title;

        if (SubTitle != "")
        {
            cout << "\n\t\t\t\t\t  " << SubTitle;
        }
        cout << "\n\t\t\t\t\t______________________________________\n\n";

        cout << "\t\t\t\t\tUser: " << CurrentUser.UserName << "\n";
        cout << "\t\t\t\t\tDate: " << clsDate::DateToString(clsDate())
            << "\n\n";

    }

    static bool CheckAccessRights(clsUser::enPermission Permission)
    {

        if (!(CurrentUser.clsUser::_CheckAccessPermission(Permission)))
        {
            system("cls");

            cout << "\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n";
            cout << "Access Denied,\n";
            cout << "You dont Have Permission To Do this,\n";
            cout << "Please Contact Your Admin";
            cout << "\n_ _ _ _ _ _ _ _ _ _ _ _ _ _ _ _\n";

            return false;
        }
        return true;
        
    }

};



