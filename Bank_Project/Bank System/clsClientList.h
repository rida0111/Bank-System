#pragma once

#include <iostream>
#include <iomanip>
#include<vector>
#include"clsScrean.h"
#include "clsBankClient.h"
#include "clsUser.h"

using namespace std;

class clsClientList :protected clsScrean
{

private:

    static void PrintClientRecordLine(clsBankClient Clinet)
    {
        cout << "\t";
        cout << "| " << left << setw(15) << Clinet.AccountNumber();
        cout << "| " << left << setw(25) << Clinet.FullName();
        cout << "| " << left << setw(13) << Clinet.Phone;
        cout << "| " << left << setw(18) << Clinet.Email;
        cout << "| " << left << setw(11) << Clinet.PinCode;
        cout << "| " << Clinet.AccountBalance;
    }

public:

    static void ShowClientList()
    {
        if (!CheckAccessRights(clsUser::enPermission::eList))
        {
            return;
        }

        vector<clsBankClient>vClient = clsBankClient::GetClientList();

        string Title = "Client List Screen";
        string SubTitle = "\t    (" + to_string(vClient.size()) + ") Client(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << "\n\t_________________________________________________";
        cout << "____________________________________________________\n\n";

        cout << "\t" << left;
        cout << "| AccountNumber  " << setw(27) << "| Client Name";

        cout << setw(15) << "| Phone";
        cout << setw(20) << "| Email";
        cout << setw(13) << "| Pine Code" << "| Balance";
        cout << "\n\t_________________________________________________";
        cout << "____________________________________________________\n\n";

        if (vClient.size() == 0)
        {
            cout << "\t\t\tNo Client Available In the system";
        }
        else

            for (clsBankClient& Client : vClient)
            {
                PrintClientRecordLine(Client);
                cout << endl;
            }

        cout << "\n\t_________________________________________________";
        cout << "____________________________________________________\n";
    }

    bool operator==(const clsClientList& other) const
    {
        return false;
    }
};
