#pragma once

#include<iostream>
#include "clsScrean.h"
#include "clsUser.h"
#include "clsInputValidate.h"

using namespace std;

class clsAddNewUserScreen :protected clsScrean
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

    static void _ReadUserInfo(clsUser& User)
    {

        cout << "\nEnter FirstName: ";
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

    static void _PrintUserInfo(clsUser User)
    {
        cout << "\nUser Card:" << endl;
        cout << "_________________________";

        cout << "\nFirstName : " << User.FirstName;
        cout << "\nLastName  : " << User.LastName;
        cout << "\nFull Name : " << User.FullName();
        cout << "\nEmail     : " << User.Email;
        cout << "\nPhone     : " << User.Phone;
        cout << "\nUserName  : " << User.UserName;
        cout << "\nPassword  : " << User.Password;
        cout << "\nPermissions: " << User.Permissions;

        cout << "\n_________________________\n";
    }

public:

    static void ShowAddNewUserScreen()
    {
        _DrawScreenHeader("Add New User Screen");
        string UserName;

        cout << "Adding New User:\n";

        cout << "\nEnter User Name? ";
        UserName = clsInputValidate::ReadString();

        while (clsUser::IsUserExist(UserName))
        {
            cout << "\nUser With [" << UserName << "] already exists, Enter another Username? ";

            UserName = clsInputValidate::ReadString();
        }

        clsUser NewUser = clsUser::GetAddNewUserObject(UserName);

        _ReadUserInfo(NewUser);

        clsUser::enSaveResults SaveResult;

        SaveResult = NewUser.Save();

        switch(SaveResult)
        {
          case clsUser::enSaveResults::svSucceeded:
          {
              cout << "\nUser Addeded Successfuly :-)\n";
              _PrintUserInfo(NewUser);

              break;
          }

          case clsUser::enSaveResults::svFaildEmptyObject:
          {
              cout << "\nError User was not saved because it's Empty";
              break;
          }

        }


    }
};

