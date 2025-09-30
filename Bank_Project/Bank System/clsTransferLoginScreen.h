#pragma once
#include<iostream>
#include"clsScrean.h"
#include"clsBankClient.h"

using namespace std;

class clsTransferLoginScreen :protected clsScrean
{

private:

    static void PrintTransferLogRecordLine(clsBankClient::stTransferLoginRecord TransferLog)
    {
        cout << "\t";
        cout << "| " << left << setw(24) << TransferLog.DateTime;
        cout << "| " << left << setw(13) << TransferLog.SourceAccountNumber;
        cout << "| " << left << setw(13) << TransferLog.DestinationAccountNumber;
        cout << "| " << left << setw(13) << TransferLog.Amount;
        cout << "| " << left << setw(13) << TransferLog.SourceBalance;
        cout << "| " << left << setw(13) << TransferLog.DestinationBalance;
        cout << "| " << TransferLog.UserName;

    }

public:

	static void ShowTransferLoginListScreen()
	{
		vector<clsBankClient::stTransferLoginRecord>vTransfer = clsBankClient::GetTransferLoginList();

		string title = "Transfer Login List Screen";
		string Subtitle = "\t  (" + to_string(vTransfer.size()) + ") " + "Record (s).";

		_DrawScreenHeader(title, Subtitle);

        cout << "\n\t____________________________________________________";
        cout << "________________________________________________________\n\n";

        cout << "\t" << left;
        cout << setw(26) << "| Date/Time  " << setw(15) << "| s.Acct";

        cout << setw(15) << "| d.Acct";
        cout << setw(15) << "| Amount";
        cout << setw(15) << "| s.Balance" << setw(15) << "| d.Balance";
        cout << "| User";

        cout << "\n\t____________________________________________________";
        cout << "________________________________________________________\n\n";
       
        if (vTransfer.size() == 0)
        {
            cout << "\t\t\tNo Transfers Available In the system";
        }
        else

           for (clsBankClient::stTransferLoginRecord& S : vTransfer)
           {
               PrintTransferLogRecordLine(S);
               cout << endl;
           }
       
        cout << "\n\t____________________________________________________";
        cout << "________________________________________________________\n";
    }

};

