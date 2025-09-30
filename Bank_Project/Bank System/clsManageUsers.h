#pragma once

#include<iostream>
#include<iomanip>
#include"clsUtil.h"
#include"clsScrean.h"
#include"clsInputValidate.h"
#include"clsListUser.h"
#include"clsAddNewUserScreen.h"
#include"clsDeleteUserScreen.h"
#include"clsUpdateUserScreen.h"
#include"clsFindUserScreen.h"

using namespace std;

class clsManageUsers :protected clsScrean
{

private:

    enum enManage
    {
        eListClient = 1, eAddNewUser = 2, eDeleteUser = 3,

        eUpdateUser = 4, eFindUser = 5, eMainMenu = 6
    };

    static short _ReadManageOption()
    {
        short choose = 0;

        cout << setw(37) << left << "" << "Choose What do you want to do? [1 to 6]? ";
        choose = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");

        return  choose;
    }

    static void _BackToManageUsers()
    {
        cout << "\n\nPress any Key to go back to Manage User...";
        system("pause>0");

        ShowManageUsersMenue();
    }

    static void _ShowListUsersScreen()
    {
        clsListUser::ShowListUserScreen();
    }

    static void _ShowAddNewUserScreen()
    {
        clsAddNewUserScreen::ShowAddNewUserScreen();
    }

    static void  _ShowDeleteUsersScreen()
    {
        clsDeleteUserScreen::ShowDeleteUserScreen();
    }

    static void  _ShowUpdateUserScreen()
    {
        clsUpdateUserScreen::ShowUpdateUserScreen();
    }

    static void _ShowFindUserScreen()
    {
        clsFindUserScreen::ShowFindUserScreen();
    }

    static void _PerfomManageOption(enManage Manage)
    {

        switch (Manage)
        {

        case enManage::eListClient:
        {
            system("cls");
            _ShowListUsersScreen();
            _BackToManageUsers();
            break;
        }
        case enManage::eAddNewUser:
        {
            system("cls");
            _ShowAddNewUserScreen();
            _BackToManageUsers();
            break;
        }
        case enManage::eDeleteUser:
        {
            system("cls");
            _ShowDeleteUsersScreen();
            _BackToManageUsers();
            break;
        }
        case enManage::eUpdateUser:
        {
            system("cls");
            _ShowUpdateUserScreen();
            _BackToManageUsers();
            break;
        }
        case enManage::eFindUser:
        {
            system("cls");
            _ShowFindUserScreen();
            _BackToManageUsers();
            break;
        }
        case enManage::eMainMenu:
        {

        }

        }


    }

public:

    static void ShowManageUsersMenue()
    {

        if (!CheckAccessRights(clsUser::enPermission::eManage))
        {
            return;
        }

        system("cls");

        _DrawScreenHeader("Manage Screen");

        cout << setw(37) << left << "" << "==========================================\n";
        cout << setw(37) << left << "" << "\tManage Users Menu Screen\n";
        cout << setw(37) << left << "" << "==========================================\n";
        cout << setw(37) << left << "" << "[1] List Users." << "\n";
        cout << setw(37) << left << "" << "[2] Add New User." << "\n";
        cout << setw(37) << left << "" << "[3] Delete User." << "\n";
        cout << setw(37) << left << "" << "[4] Update User." << "\n";
        cout << setw(37) << left << "" << "[5] Find User." << "\n";
        cout << setw(37) << left << "" << "[6] Main Menu.\n";
        cout << setw(37) << left << "" << "==========================================\n";

        _PerfomManageOption((enManage)_ReadManageOption());
    }

};
