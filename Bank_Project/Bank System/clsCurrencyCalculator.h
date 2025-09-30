#pragma once
#include <iostream>
#include"clsScrean.h"
#include"clsCurrency.h"
#include"clsInputValidate.h"
#include"clsString.h"

using namespace std;

class clsCurrencyCalculator :protected clsScrean
{

private:

	static void _PrintCurrency(clsCurrency Currency, string Title)
	{
		cout << Title << endl;
		cout << "_____________________\n";
		cout << "\nCountry  :" << Currency.Country();
		cout << "\nCode     :" << Currency.CurrencyCode();
		cout << "\nName     :" << Currency.CurrencyName();
		cout << "\nRate(1$) :" << Currency.Rate();
		cout << "\n_____________________\n\n";
	}

	static clsCurrency _GetCurrency(string Message)
	{
		string CurrencyCode;

		cout << Message << endl;

		CurrencyCode = clsInputValidate::ReadString();

		while (!clsCurrency::IsCurrencyExit(CurrencyCode))
		{
			cout << "\nCurrency is not found,choose another one:";
			CurrencyCode = clsInputValidate::ReadString();
		}

		clsCurrency Currency = clsCurrency::FindByCode(CurrencyCode);

		return Currency;
	}

	static void _PrintCalculationsResults(float Amount, clsCurrency CurrencyFrom, clsCurrency CurrencyTo)
	{
		float AmountInUSD = CurrencyFrom.ConvertToUsd(Amount);

		_PrintCurrency(CurrencyFrom, "\nConvert From:");

		cout << Amount << " " << CurrencyFrom.CurrencyCode() << " = "
			<< to_string(AmountInUSD) << " USD";

		if ((clsString::UpperCaseAllLetter(CurrencyTo.CurrencyCode()) == "USD"))
		{
			return;
		}

		_PrintCurrency(CurrencyTo, "\n\nConvert From USD to:\n\nTo:");

		float AmountInCurrency2 = CurrencyFrom.ConvertToOtherCurrency(Amount, CurrencyTo);

		cout << Amount << " " << CurrencyFrom.CurrencyCode() << " = "
			<< AmountInCurrency2 << CurrencyTo.CurrencyCode();

	}

	static float _ReadAmount()
	{
		float Amount;
		cout << "\nEnter Amount to Exchange: ";
		cin >> Amount;

		return Amount;
	}

public:

	static void _ShowCurrencyCalculatorScrean()
	{
		char Answer = 'Y';

		while (Answer == 'Y' || Answer == 'y')
		{
			system("cls");

			_DrawScreenHeader("Currency Calculator Screan");

			clsCurrency CurrencyFrom = _GetCurrency("\nPlease Enter Currency1 Code:");
			clsCurrency CurrencyTo = _GetCurrency("\nPlease Enter Currency2 Code:");
			float Amount = _ReadAmount();

			_PrintCalculationsResults(Amount, CurrencyFrom, CurrencyTo);

			cout << "\n\nDo you want to perform another calculation? y/n ? ";
			cin >> Answer;
		} 

	}

};