#pragma once
#include<iostream>
#include<iomanip>
#include"clsScrean.h"
#include"clsCurrency.h"

using namespace std;

class clsListCurrenciesScrean :protected clsScrean
{
private:

    static void PrintCurrencyRecordLine(clsCurrency Currency)
    {
        cout << "\t";
        cout << "| " << left << setw(30) << Currency.Country();
        cout << "| " << left << setw(7) << Currency.CurrencyCode();
        cout << "| " << left << setw(40) << Currency.CurrencyName();
        cout << "| " << Currency.Rate();
    }

public:

    static void ShowListCurrenciesScreen()
    {

        vector<clsCurrency>vCurrency = clsCurrency::GetCurrencyList();

        string Title = "Currencies List Screen";
        string SubTitle = "\t   (" + to_string(vCurrency.size()) + ") Currency(s)";

        _DrawScreenHeader(Title, SubTitle);

        cout << "\t____________________________________________";
        cout << "__________________________________________________\n\n";

        cout << "\t" << left;
        cout << setw(32) << "| Country  " << setw(9) << "| Code";
        cout << setw(42) << "| Name" << "| Rate/(1$)";
         
        cout << "\n\t___________________________________________";
        cout << "___________________________________________________\n\n";

        if (vCurrency.size() == 0)
        {
            cout << "\t\t\tNo Currencies Available In the system";
        }
        else

         for (clsCurrency& S : vCurrency)
         {
             PrintCurrencyRecordLine(S);
             cout << endl;
         }

        cout << "\t____________________________________________";
        cout << "__________________________________________________\n";
    }

};

