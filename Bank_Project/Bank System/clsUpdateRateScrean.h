#pragma once
#include <iostream>
#include"clsScrean.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"

using namespace std;

class clsUpdateRateScrean :protected clsScrean
{

private:

	static void _PrintCurrency(clsCurrency Currency)
	{
		cout << "\nCurrency Card:";
		cout << "\n_____________________\n";
		cout << "\nCountry  :" << Currency.Country();
		cout << "\nCode     :" << Currency.CurrencyCode();
		cout << "\nName     :" << Currency.CurrencyName();
		cout << "\nRate(1$) :" << Currency.Rate();
		cout << "\n_____________________\n";
	}

	static float _ReadRate()
	{
		float NewRate;
		cout << "\nEnter New Rate: ";
		cin >> NewRate;

		return NewRate;
	}

public:

	static void _ShowUpdateCurrencyScrean()
	{
		_DrawScreenHeader("Update Currency Screan");

		string CurrencyCode;
		cout << "\nPlease enter Currency Code: ";
		CurrencyCode = clsInputValidate::ReadString();
		
		while (!clsCurrency::IsCurrencyExit(CurrencyCode))
		{
			cout << "\nCurrency is not found,choose anther one:";

			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
		_PrintCurrency(Currency);

		char Answer;
		cout << "\nAre you sure you want to update the rate of this currency y/n? ";
		cin>> Answer;

		if (Answer == 'y' || Answer == 'Y')
		{
			cout << "\nUpdate Currency Rate:";
			cout << "\n_____________________\n";
 
			Currency.UpdateRate(_ReadRate());

			cout << "\nCurrency Rate Updated Successfully :-)\n";
			_PrintCurrency(Currency);
		}

	}


};

