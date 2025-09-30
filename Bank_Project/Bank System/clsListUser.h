#pragma once

#include<iostream>
#include<iomanip>
#include "clsUser.h"
#include"clsScrean.h"

using namespace std;

class clsListUser :protected clsScrean
{

private:

    static void PrintClientRecordLine(clsUser User)
    {
        cout << "\t";

        cout << "| " << left << setw(10) << User.UserName;
        cout << "| " << left << setw(23) << User.FullName();
        cout << "| " << left << setw(13) << User.Phone;
        cout << "| " << left << setw(20) << User.Email;
        cout << "| " << left << setw(11) << User.Password;
        cout << "| " << User.Permissions;
    }

public:

    static void ShowListUserScreen()
    {

        vector<clsUser>vUser = clsUser::GetUsersList();

        string Title = "Client List Screen";
        string SubTitle = "\t   (" + to_string(vUser.size()) + ") User(s)";

        _DrawScreenHeader(Title, SubTitle);

        cout << "\n\t_________________________________________________";
        cout << "____________________________________________________\n\n";

        cout << "\t" << left;
        cout << "| UserName  " << setw(25) << "| Full Name";

        cout << setw(15) << "| Phone";
        cout << setw(22) << "| Email";
        cout << setw(13) << "| Password" << "| Permissions";
        cout << "\n\t_________________________________________________";
        cout << "____________________________________________________\n\n";

        if (vUser.size() == 0)
        {
            cout << "\t\t\tNo Client Available In the system";
        }
        else

            for (clsUser& S : vUser)
            {
                PrintClientRecordLine(S);
                cout << endl;
            }

        cout << "\t_________________________________________________";
        cout << "____________________________________________________\n";


    }

};



