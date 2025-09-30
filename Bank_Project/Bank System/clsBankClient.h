#pragma once

#include<iostream>
#include<string>
#include <vector>
#include<fstream>
#include"clsPerson.h"
#include"clsString.h"
#include"clsDate.h"
#include"All.h"

using namespace std;

class clsBankClient :public clsPerson

{

private:

	enum enMode { EmptyMode = 0, UpdateMode = 1, AddNewMode = 2, DeleteClientMode = 3 };

	enMode _Mode;

	string _AccountNumber;
	string _PinCode;
	float _AccountBalance;

	bool _MarkedForDelete = false;

	static clsBankClient _ConvertLineToClientObject(string Line, string Delim = "#//#")
	{
		vector<string>vClient = clsString::Split(Line, Delim);


		return clsBankClient(enMode::UpdateMode, vClient[0], vClient[1], vClient[2],
			vClient[3], vClient[4], vClient[5], stod(vClient[6]));

	}

	static clsBankClient _GetEmptyClientObject()
	{
		return clsBankClient(enMode::EmptyMode, "", "", "", "", "", "", 0);
	}

	static string _ConvertToString(clsBankClient& Client, string Delim = "#//#")
	{
		string Str = "";

		Str = Client.FirstName + Delim;
		Str += Client.LastName + Delim;
		Str += Client.Email + Delim;
		Str += Client.Phone + Delim;
		Str += Client._AccountNumber + Delim;
		Str += Client._PinCode + Delim;
		Str += to_string(Client._AccountBalance);

		return Str;

	}

	static vector<clsBankClient>_ConvertFilToVector(string FileUserName)
	{
		fstream File;

		vector<clsBankClient>vUser;

		File.open(FileUserName, ios::in);

		if (File.is_open())
		{
			string Element;

			while (getline(File, Element))
			{

				clsBankClient User = _ConvertLineToClientObject(Element);
				
				vUser.push_back(User);
			}

			File.close();
		}

		return vUser;
	}

	static void _SaveClientDataToFile(vector<clsBankClient>& vClient)
	{
		fstream File;

		File.open("Bank2.text", ios::out);

		if (File.is_open())
		{
			string Element;

			for (clsBankClient& S : vClient)
			{
				if (S._MarkedForDelete == false)
				{
					Element = _ConvertToString(S);
					File << Element << endl;
				}
			}

			File.close();
		}
	}

	void _Update()
	{
		vector<clsBankClient> vClient;

		vClient = _ConvertFilToVector("Bank2.text");

		for (clsBankClient& S : vClient)
		{
			if (S.AccountNumber() == AccountNumber())
			{
				S = *this;
				break;
			}

		}

		_SaveClientDataToFile(vClient);
	}

	void ConvertStringToFile(string str)
	{
		fstream File;

		File.open("Bank2.text", ios::out | ios::app);

		if (File.is_open())
		{
			File << str << endl;
		}
		File.close();

	}

	void _AddNew()
	{
		ConvertStringToFile(_ConvertToString(*this));
	}

	string _PrepareTransferLogRecord(int Amount, clsBankClient& DestinationClient)
	{
		string Delim = "#//#";
		string Str = "";

		Str = clsDate::GetSystemDateTimeString() + Delim;
		Str += AccountNumber() + Delim;
		Str += DestinationClient.AccountNumber() + Delim;
		Str += to_string(Amount) + Delim;
		Str += to_string(_AccountBalance) + Delim;
		Str += to_string(DestinationClient._AccountBalance) + Delim;
		Str += CurrentUser.UserName;

		return Str;
	}

	void _RegisterTransferLog(int Amount, clsBankClient& DestinationClient)
	{
		string stDataLine = _PrepareTransferLogRecord(Amount, DestinationClient);

		fstream file;
	
		file.open("TransferLog.text", ios::out | ios::app);

		if (file.is_open())
		{
			file << stDataLine << endl;
			file.close();
		}

	}

public:

	struct stTransferLoginRecord
	{
		string DateTime;
		string SourceAccountNumber;
		string DestinationAccountNumber;
		int Amount;
		int SourceBalance;
		int DestinationBalance;
		string UserName;
	};

	static stTransferLoginRecord _ConvertTransferLoginLineToRecord(string Line, string Delim = "#//#")
	{
		stTransferLoginRecord Transfer;

		vector<string> stData = clsString::Split(Line, Delim);

		Transfer.DateTime = stData[0];
		Transfer.DestinationAccountNumber = stData[1];
		Transfer.SourceAccountNumber = stData[2];
		Transfer.Amount = stoi(stData[3]);
		Transfer.SourceBalance = stoi(stData[4]);
		Transfer.DestinationBalance = stoi(stData[5]);
		Transfer.UserName = stData[6];

		return Transfer;
	}

	clsBankClient(enMode Mode, string FirstName, string LastName, string  Email, string  Phone, string AccountNumber, string PinCode, float AccountBalance)
		:clsPerson(FirstName, LastName, Email, Phone)

	{
		_Mode = Mode;
		_AccountNumber = AccountNumber;
		_PinCode = PinCode;
		_AccountBalance = AccountBalance;
	}

	bool IsEmpty()
	{
		return (_Mode == enMode::EmptyMode);
	}

	string AccountNumber()
	{
		return _AccountNumber;
	}

	void SetPinCode(string PinCode)
	{
		_PinCode = PinCode;
	}

	string GetPinCode()
	{
		return _PinCode;
	}

	__declspec(property(get = GetPinCode, put = SetPinCode)) string PinCode;

	void SetAccountBalance(float AccountBalance)
	{
		_AccountBalance = AccountBalance;
	}

	float GetAccountBalance()
	{
		return _AccountBalance;
	}

	__declspec(property(get = GetAccountBalance, put = SetAccountBalance)) float AccountBalance;

	static clsBankClient Find(string AccountNumber)
	{

		fstream File;

		File.open("Bank2.text", ios::in);

		if (File.is_open())
		{
			string Element;

			while (getline(File, Element))
			{
				clsBankClient Client = _ConvertLineToClientObject(Element);

				if (Client._AccountNumber == AccountNumber)
				{
					File.close();
					return Client;
				}

			}
			File.close();
		}

		return  _GetEmptyClientObject();
	}

	static clsBankClient Find(string AccountNumber, string PinCode)
	{

		fstream File;

		File.open("Bank2.text", ios::in);

		if (File.is_open())
		{
			string Element;

			while (getline(File, Element))
			{
				clsBankClient Client = _ConvertLineToClientObject(Element);

				if (Client._AccountNumber == AccountNumber && Client._PinCode == PinCode)
				{
					return Client;
					File.close();
				}
			}

			File.close();
		}

		return  _GetEmptyClientObject();

	}

	static bool IsClientExist(string AccountNumber)
	{
		clsBankClient Client1 = clsBankClient::Find(AccountNumber);

		return (!Client1.IsEmpty());
	}

	static clsBankClient GetAddNewClientObject(string AccountNumber)
	{
		return clsBankClient(enMode::AddNewMode, "", "", "", "", AccountNumber, "", 0);
	}

	bool Delete()
	{
		vector<clsBankClient>vClient = _ConvertFilToVector("Bank2.text");

		for (clsBankClient& C : vClient)
		{
			if (C.AccountNumber() == _AccountNumber)
			{
				C._MarkedForDelete = true;

				break;
			}

		}

		_SaveClientDataToFile(vClient);

		*this = _GetEmptyClientObject();

		return true;

	}

	enum enSaveResults { svFaildEmptyObject = 0, svSucceeded = 1, svFaildAccountNumberExists = 2 };

	enSaveResults Save()
	{
	  switch (_Mode)
	  {
		case enMode::EmptyMode:
		{
			return enSaveResults::svFaildEmptyObject;
		}

		case enMode::UpdateMode:
		{
			_Update();
			return enSaveResults::svSucceeded;

			break;
		}

		case enMode::AddNewMode:
		{
			if (clsBankClient::IsClientExist(_AccountNumber))
			{
				return enSaveResults::svFaildEmptyObject;
			}
			else
			{
				_AddNew();
				_Mode = enMode::UpdateMode;

				return enSaveResults::svSucceeded;
			}
		}

	  }
	  
	}

	static vector<clsBankClient>GetClientList()
	{
		return _ConvertFilToVector("Bank2.text");
	}

	static int GetTotalBalance()
	{
		int TotalBalance = 0;

		vector<clsBankClient>vClient = clsBankClient::GetClientList();

		for (clsBankClient& Client : vClient)
		{
			TotalBalance += Client._AccountBalance;
		}

		return TotalBalance;
	}

	void Deposit(double Amount)
	{
		_AccountBalance += Amount;
		Save();
	}

	bool WithDraw(double Amount)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}
		else
		{
			_AccountBalance -= Amount;
			Save();

			return true;
		}

	}

    bool Transfer(int Amount, clsBankClient& DestinationClient)
	{
		if (Amount > _AccountBalance)
		{
			return false;
		}

		WithDraw(Amount);
		DestinationClient.Deposit(Amount);
		_RegisterTransferLog(Amount, DestinationClient);

		return true;
	}

	static vector<stTransferLoginRecord> GetTransferLoginList()
	{
		fstream File;
		vector< stTransferLoginRecord> vTransferLogRecord;

		File.open("TransferLog.text", ios::in);

		if (File.is_open())
		{
			string Element;
			stTransferLoginRecord TransferRecord;

			while (getline(File, Element))
			{
				TransferRecord = _ConvertTransferLoginLineToRecord(Element);
				vTransferLogRecord.push_back(TransferRecord);
			}

			File.close();
		}

		return vTransferLogRecord;

	}


};


