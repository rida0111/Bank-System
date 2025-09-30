#pragma once
#include <iostream>
#include<iomanip>
#include"clsScrean.h"
#include"clsUser.h"

class clsLoginRegisterScreen :protected clsScrean
{

private:

    static void _PrintLoginRegisterRecordLine(clsUser::stloginRegisterRecord LoginRegisterRecord)
    {
        cout << "\t";
        cout << "| " << left << setw(30) << LoginRegisterRecord.DateTime;
        cout << "| " << left << setw(22) << LoginRegisterRecord.UserName;
        cout << "| " << left << setw(28) << LoginRegisterRecord.Password;
        cout << "| " << LoginRegisterRecord.Permissions;
    }

public:

    static void ShowLoginRegisterScreen()
    {

        if (!CheckAccessRights(clsUser::enPermission::eLoginRegister))
        {
            return;
        }

        vector <clsUser::stloginRegisterRecord> vLoginRegisterRecord = clsUser::GetLoginRegisterRecord();
      
        string Title = "login Register List Screen";

        string SubTitle = "\t   (" + to_string(vLoginRegisterRecord.size()) + ") " + "Record(s).";

        _DrawScreenHeader(Title, SubTitle);

        cout << "\n\t_________________________________________________";
        cout << "____________________________________________________\n\n";

        cout << "\t" << left;
        cout << setw(32) << "| Date/Time  " << setw(24) << "| UserName";
        cout << setw(30) << "| Password" << "| Permissions";
        cout << "\n\t_________________________________________________";
        cout << "____________________________________________________\n\n";

        if (vLoginRegisterRecord.size() == 0)
        {
            cout << "\t\t\tNo login Register Available In the system";
        }

        else

            for (clsUser::stloginRegisterRecord& S : vLoginRegisterRecord)
            {
                _PrintLoginRegisterRecordLine(S);
                cout << endl;
            }

        cout << "\n\t_________________________________________________";
        cout << "____________________________________________________\n";
    }


};

