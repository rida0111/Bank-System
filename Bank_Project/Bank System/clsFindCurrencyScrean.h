#pragma once
#include <iostream>
#include"clsScrean.h"
#include"clsInputValidate.h"
#include"clsCurrency.h"

using namespace std;

class clsFindCurrencyScrean :protected clsScrean
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

	static void _ShowResults(clsCurrency Currency)
	{
		if (!Currency.IsEmpty())
		{
			cout << "\nCurrency Found :-)\n";
			_PrintCurrency(Currency);
		}
		else
		{
			cout << "\nCurrency Not Found ):-\n";
		}
	}

public:

	static void _ShowFindCurrencyScrean()
	{
		_DrawScreenHeader("Find Currency Screan");

		short choose;

		cout << "Find By: [1] code or [2] country ? ";
		choose = clsInputValidate::ReadShortNumberBetween(1, 2, "\nFind By: [1] code or [2] country ?");

		if (choose == 1)
		{
			string CurrencyCode;
			cout << "\nPlease enter CurrencyCode: ";
			CurrencyCode = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);
			_ShowResults(Currency);
		}

		else
		{
			string Country;
			cout << "\nPlease enter Country: ";
			Country = clsInputValidate::ReadString();
			clsCurrency Currency = clsCurrency::FindByCountry(Country);
			_ShowResults(Currency);
		}

	}

};