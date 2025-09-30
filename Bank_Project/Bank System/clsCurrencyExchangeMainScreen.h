#pragma once

#include <iostream>
#include<iomanip>
#include"clsScrean.h"
#include"clsInputValidate.h"
#include"clsListCurrenciesScrean.h"
#include"clsFindCurrencyScrean.h"
#include"clsUpdateRateScrean.h"
#include"clsCurrencyCalculator.h"

using namespace std;

class clsCurrencyExchangeMainScreen :protected clsScrean
{

private:
 
    enum enMainOption
    {
        eCurrenciesList  = 1,  eFindCurrency  = 2, eUpdateRate = 3,
        
        eCurrencyCalculator = 4,  eMaineMenue = 5
    };

    static short _ReadCurrienciesMainMenueOption()
    {
        short choose = 0;

        cout << setw(37) << left << "" << "Choose What do you want to do? [1 to 5]? ";
        choose = clsInputValidate::ReadShortNumberBetween(1, 5, "Enter Number between 1 to 5? ");

        return choose;
    }

    static void _GoBackToCurrienciesMenue()
    {
        cout << "\nPress any Key to go back to Curriencies Menue...";
        system("pause>0");

        ShowCurrienciesMenue();
    }

    static void _ShowCurrenciesListScrean()
    {
        clsListCurrenciesScrean::ShowListCurrenciesScreen();
    }

    static void _ShowFindCurrencyScrean()
    {
        clsFindCurrencyScrean::_ShowFindCurrencyScrean();
    }

    static void _ShowUpdateRateScrean()
    {
        clsUpdateRateScrean::_ShowUpdateCurrencyScrean();
    }

    static void _ShowCurrencyCalculatorScrean()
    {
        clsCurrencyCalculator::_ShowCurrencyCalculatorScrean();
    }

    static void _PerfomCurrienciesMainMenueOption(enMainOption Choose)
    {
      
        switch (Choose)
        {

          case enMainOption::eCurrenciesList:
          {
              system("cls");
              _ShowCurrenciesListScrean();
              _GoBackToCurrienciesMenue();
              break;
          }

          case enMainOption::eFindCurrency:
          {
              system("cls");
              _ShowFindCurrencyScrean();
              _GoBackToCurrienciesMenue();
              break;
          }

          case enMainOption::eUpdateRate:
          {
              system("cls");
              _ShowUpdateRateScrean();
              _GoBackToCurrienciesMenue();
              break;
          }

          case enMainOption::eCurrencyCalculator:
          {
              system("cls");
              _ShowCurrencyCalculatorScrean();
              _GoBackToCurrienciesMenue();
              break;
          }

          case enMainOption::eMaineMenue:
          {

          }

        }
      
    }

public:

	static void ShowCurrienciesMenue()
	{
        system("cls");

		_DrawScreenHeader("Currency Exchange Main Screen");

        cout << setw(37) << left << "" << "==========================================\n";
        cout << setw(50) << left << "" << "Currency Exchange Menue\n";
        cout << setw(37) << left << "" << "==========================================\n";

        cout << setw(37) << left << "" << "[1] List Currencies.\n";
        cout << setw(37) << left << "" << "[2] Find Currency.\n";
        cout << setw(37) << left << "" << "[3] Update Rate.\n";
        cout << setw(37) << left << "" << "[4] Currency Calculator.\n";
        cout << setw(37) << left << "" << "[5] Main Menue.\n";
       
        cout << setw(37) << left << "" << "===========================================\n";

        _PerfomCurrienciesMainMenueOption((enMainOption)_ReadCurrienciesMainMenueOption());

	}
 
};