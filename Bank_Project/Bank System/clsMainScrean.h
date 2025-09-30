#pragma once

#include <iostream>
#include"clsUtil.h"
#include"clsScrean.h"
#include"clsBankClient.h"
#include"clsClientList.h"
#include"clsAddNewClientScreen.h"
#include"clsDeleteClientScreen.h"
#include"clsUpdateClientScreen.h"
#include"clsFindClientScreen.h"
#include"clsTransactionMainMenue.h"
#include"clsManageUsers.h"
#include "All.h"
#include"clsLoginRegisterScreen.h"
#include"clsCurrencyExchangeMainScreen.h"

using namespace std;

class clsMainScrean :protected clsScrean
{

private:

    enum enMainOption
    {
        eClientList = 1, eAddNewClient = 2, eDeleteClient = 3,

        eUpdateClient = 4, eFindClient = 5, eShowTransactions = 6,

        enManageUsers = 7, eLoginRegister = 8, eCurrencyExchange = 9, eExit = 10
    };

    static short _ReadMainMenueOption()
    {
        short choose = 0;

        cout << setw(37) << left << "" << "Choose What do you want to do? [1 to 10]? ";
        choose = clsInputValidate::ReadShortNumberBetween(1, 10, "Enter Number between 1 to 10? ");

        return choose;
    }

    static void _GoBackToMainMenue()
    {
        cout << "\nPress any Key to go back to Main Menu...";
        system("pause>0");

        ShowMainMenue();
    }

    static void _ShowAllClientsScreen()
    {
        clsClientList::ShowClientList();
    }

    static void _ShowAddNewClientsScreen()
    {
        clsAddNewClientScreen::ShowAddNewClientScreen();
    }

    static void _ShowDeleteClientsScreen()
    {
        clsDeleteClientScreen::ShowDeleteClientScreen();
    }

    static void _ShowUpdateClientsScreen()
    {
        clsUpdateClientScreen::ShowUpdateClientScreen();
    }

    static void _ShowTransactionsMenue()
    {
        clsTransactionMainMenue::TransactionMainMenu();
    }

    static void  _ShowFindClientsScreen()
    {
        clsFindClientScreen::ShowFindClientScreen();
    }

    static void _ShowManageUsersMenue()
    {
        clsManageUsers::ShowManageUsersMenue();
    }

    static void _Logout()
    {
        CurrentUser = clsUser::Find("", "");
    }

    static void _ShowLoginRegisterScreen()
    {
        clsLoginRegisterScreen::ShowLoginRegisterScreen();
    }

    static void _ShowCurrencyExchangeScreen()
    {
        clsCurrencyExchangeMainScreen::ShowCurrienciesMenue();
    }

    static void _PerfomMainMenueOption(enMainOption Choose)
    {

      switch (Choose)
      {

        case enMainOption::eClientList:
        {
            system("cls");
            _ShowAllClientsScreen();
            _GoBackToMainMenue();
            break;
        }

        case enMainOption::eAddNewClient:
        {
            system("cls");
            _ShowAddNewClientsScreen();
            _GoBackToMainMenue();
            break;
        }

        case enMainOption::eDeleteClient:
        {
            system("cls");
            _ShowDeleteClientsScreen();
            _GoBackToMainMenue();
            break;
        }

        case enMainOption::eUpdateClient:
        {
            system("cls");
            _ShowUpdateClientsScreen();
            _GoBackToMainMenue();
            break;
        }

        case enMainOption::eFindClient:
        {
            system("cls");
            _ShowFindClientsScreen();
            _GoBackToMainMenue();
            break;
        }

        case enMainOption::eShowTransactions:
        {
            system("cls");
            _ShowTransactionsMenue();
            _GoBackToMainMenue();
            break;
        }

        case enMainOption::enManageUsers:
        {
            _ShowManageUsersMenue();
            _GoBackToMainMenue();
            break;
        }

        case enMainOption::eLoginRegister:
        {
            system("cls");
            _ShowLoginRegisterScreen();
            _GoBackToMainMenue();
            break;
        }

        case enMainOption::eCurrencyExchange:
        {
            system("cls");
            _ShowCurrencyExchangeScreen();
            _GoBackToMainMenue();
            break;
        }

        case enMainOption::eExit:
        {
            system("cls");
            _Logout();

            break;
        }

      }

    }

public:

    static void ShowMainMenue()
    {
        system("cls");

        _DrawScreenHeader("Main Screen");

        cout << setw(37) << left << "" << "==========================================\n";
        cout << setw(50) << left << "" << "Main Menue\n";
        cout << setw(37) << left << "" << "==========================================\n";

        cout << setw(37) << left << "" << "[1] Show Client List.\n";
        cout << setw(37) << left << "" << "[2] Add New Client.\n";
        cout << setw(37) << left << "" << "[3] Delete Client.\n";
        cout << setw(37) << left << "" << "[4] Update Client Info.\n";
        cout << setw(37) << left << "" << "[5] Find Client.\n";
        cout << setw(37) << left << "" << "[6] Transactions.\n";
        cout << setw(37) << left << "" << "[7] Manage Users.\n";
        cout << setw(37) << left << "" << "[8] LoginRegister.\n";
        cout << setw(37) << left << "" << "[9] Currency Exchange.\n";
        cout << setw(37) << left << "" << "[10] logout.\n";
        
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfomMainMenueOption((enMainOption)_ReadMainMenueOption());
    }

};

