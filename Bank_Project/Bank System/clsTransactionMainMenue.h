#pragma once
#include<iostream>
#include"clsScrean.h"
#include"clsDepositClient.h"
#include"clsInputValidate.h"
#include "clsMainScrean.h"
#include"clsWithDrawScreen.h"
#include"clsTotalBalancesScreen.h"
#include"clsTransferScreen.h"
#include"clsTransferLoginScreen.h"

using namespace std;

class clsTransactionMainMenue :protected clsScrean
{

private:

    enum enTransaction
    {
        eDeposit = 1, eWithDraw = 2, eTotalBalances = 3,
        eTransfer = 4, eTransferlog = 5, eMainMenue = 6
    };

    static short _ReadTransactionOption()
    {
        short choose = 0;

        cout << setw(37) << left << "" << "Choose What do you want to do? [1 to 6]? ";
        choose = clsInputValidate::ReadShortNumberBetween(1, 6, "Enter Number between 1 to 6? ");

        return choose;
    }

    static void _GoBackToTransaction()
    {

        cout << "\n\nPress any Key to go back to Transaction...";
        system("pause>0");

        TransactionMainMenu();
    }

    static void _ShowDepositScreen()
    {
        clsDepositClient::ShowDepositScreen();
    }

    static void _ShowWithDrawScreen()
    {
        clsWithDrawScreen::ShowWithDrawScreen();
    }

    static void _ShowTotalBalancesScreen()
    {
        clsTotalBalancesScreen::ShowTotalBalancesScreen();
    }

    static void _ShowTransferScreen()
    {
        clsTransferScreen::ShowTransferScreen();
    }

    static void _ShowTransferLoginScreen()
    {
        clsTransferLoginScreen::ShowTransferLoginListScreen();
    }

    static void _PerfomTransactionOption(enTransaction TransactionChoose)
    {

      switch (TransactionChoose)
      {
        case enTransaction::eDeposit:
        {
            system("cls");
            _ShowDepositScreen();
            _GoBackToTransaction();
            break;
        }

        case enTransaction::eWithDraw:
        {
            system("cls");
            _ShowWithDrawScreen();
            _GoBackToTransaction();
            break;
        }

        case enTransaction::eTotalBalances:
        {
            system("cls");
            _ShowTotalBalancesScreen();
            _GoBackToTransaction();
            break;
        }

        case enTransaction::eTransfer:
        {
            system("cls");
            _ShowTransferScreen();
            _GoBackToTransaction();
            break;
        }
        case enTransaction::eTransferlog:
        {
            system("cls");
            _ShowTransferLoginScreen();
            _GoBackToTransaction();
            break;
        }

        case enTransaction::eMainMenue:
        {

        }

      }

    }

public:

    static void TransactionMainMenu()
    {

        if (!CheckAccessRights(clsUser::enPermission::eTransaction))
        {
            return;
        }

        system("cls");

        _DrawScreenHeader("Transaction Screen");

        cout << "\t\t\t\t   ===============================================\n";
        cout << "\t\t\t\t\t\tTransaction Menu Screen";
        cout << "\n\t\t\t\t   ===============================================\n";
        cout << "\t\t\t\t   [1] Deposit.\n";
        cout << "\t\t\t\t   [2] Whit draw.\n";
        cout << "\t\t\t\t   [3] Total Balances.\n";
        cout << "\t\t\t\t   [4] Transfer.\n";
        cout << "\t\t\t\t   [5] Transfer log.\n";
        cout << "\t\t\t\t   [6] Main Menu.\n";
        cout << "\t\t\t\t   ===============================================\n";

        _PerfomTransactionOption((enTransaction)_ReadTransactionOption());
    }

};