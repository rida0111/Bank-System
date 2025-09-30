#pragma once

#include<iostream>
#include <iomanip>
#include"clsScrean.h"
#include "clsUtil.h"

using namespace std;

class clsTotalBalancesScreen :protected clsScrean
{
    static void PrintClientRecordLine(clsBankClient Clinet)
    {
        cout << "\t\t";
        cout << "| " << left << setw(24) << Clinet.AccountNumber();
        cout << "| " << left << setw(26) << Clinet.FullName();
        cout << "| " << Clinet.AccountBalance;
    }

public:

    static void ShowTotalBalancesScreen()
    {
        vector<clsBankClient>vClient = clsBankClient::GetClientList();

        string Title = "Balances list Screen";
        string SubTitle = "\t   (" + to_string(vClient.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << "\t\t_______________________________";
        cout << "______________________________________\n\n";

        cout << "\t\t" << left;
        cout << setw(26) << "| AccountNumber  ";
        cout << setw(28) << "| Client Name";
        cout << "| Balance";

        cout << "\n\t\t_______________________________";
        cout << "______________________________________\n\n";

        int TotalBalance = clsBankClient::GetTotalBalance();

        if (vClient.size() == 0)
        {
            cout << "\t\t\t\tNo Client Available In the system";
        }
        else

            for (clsBankClient& Client : vClient)
            {
                PrintClientRecordLine(Client);

                cout << endl;
            }

        cout << "\t\t__________________________________";
        cout << "___________________________________\n\n";

        cout << "\t\t\t\t\tTotal Balances = " << TotalBalance << endl;

        cout << "\t\t\t ( " << clsUtil::NumberToText(TotalBalance) << " )";
    }

};



