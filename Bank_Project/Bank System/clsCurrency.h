#pragma once
#include<iostream>
#include<vector>
#include<string>
#include<fstream>
#include"clsString.h"

using namespace std;

class clsCurrency
{

private:

	enum enMode { EmptyMode = 0, UpdateMode = 1 };

	enMode _Mode;
	string _Country;
	string _CurrencyCode;
	string _CurrencyName;
	float  _Rate;

	static clsCurrency _ConvertLinetoCurencyObject(string Line, string dilim = "#//#")
	{
		vector<string>vCurrencyData = clsString::Split(Line, dilim);

		return clsCurrency(enMode::UpdateMode, vCurrencyData[0], vCurrencyData[1], vCurrencyData[2], stof(vCurrencyData[3]));
	}
	
	static string _ConverCurrencyObjectToLine(clsCurrency Currency1, string dilim = "#//#")
	{
		string CurrencyRecord;

		CurrencyRecord = Currency1._Country + dilim;
		CurrencyRecord += Currency1._CurrencyCode + dilim;
		CurrencyRecord += Currency1._CurrencyName + dilim;
		CurrencyRecord += to_string(Currency1._Rate);

		return CurrencyRecord;
	}

	static vector<clsCurrency>_LoadCurrencyDataFromFile()
	{
		fstream file;

		vector<clsCurrency>vCurrencyData;

		file.open("Currencies.txt", ios::in);

		if (file.is_open())
		{
			string line;
		

			while (getline(file, line))
			{
				clsCurrency Currency = _ConvertLinetoCurencyObject(line);

				vCurrencyData.push_back(Currency);
			}

			file.close();
		}

		return vCurrencyData;
	}

	static void _SaveCurrencyDataToFile(vector <clsCurrency> vUsers)
	{

		fstream MyFile;
		MyFile.open("Currencies.txt", ios::out);

		string DataLine;

		if (MyFile.is_open())
		{

			for (clsCurrency U : vUsers)
			{
				DataLine = _ConverCurrencyObjectToLine(U);
				MyFile << DataLine << endl;

			}

		}

		MyFile.close();

	}

	void _Update()
	{
		vector <clsCurrency> _vUsers = _LoadCurrencyDataFromFile();

		for (clsCurrency& U : _vUsers)
		{
			if (U.CurrencyCode() == CurrencyCode())
			{
				U = *this;
				break;
			}

		}

		_SaveCurrencyDataToFile(_vUsers);

	}

	static clsCurrency  _GetEmptyCurrencyObject()
	{
		return clsCurrency(enMode::EmptyMode, "", "", "", 0);
	}

public:

	clsCurrency(enMode Mode,string Country, string CurrencyCode, string CurrencyName, float Rate)
	{
		_Mode = Mode;
		_Country = Country;
		_CurrencyCode = CurrencyCode;
		_CurrencyName = CurrencyName;
		_Rate = Rate;
	}

	bool IsEmpty()
	{
		return _Mode == enMode::EmptyMode;
	}

	string Country()
	{
		 return _Country;
	}

	string CurrencyCode()
	{
		return _CurrencyCode;
	}

	string CurrencyName()
	{
		return _CurrencyName;
	}

	void UpdateRate(float NewRate)
	{
		_Rate = NewRate;
		_Update();
	}

	float Rate()
	{
		return _Rate;
	}
	
	static clsCurrency FindByCode(string CurrencyCode)
	{
		CurrencyCode = clsString::UpperCaseAllLetter(CurrencyCode);

		fstream file;

		vector<clsCurrency>vCurrencyData;

		file.open("Currencies.txt", ios::in);

		if (file.is_open())
		{
			string line;
		
			while(getline(file, line))
			{ 
				clsCurrency Currency = _ConvertLinetoCurencyObject(line);
				if (clsString::UpperCaseAllLetter(Currency.CurrencyCode()) == CurrencyCode)
				{
					file.close();
					return Currency;
				}
			}

		}

		return _GetEmptyCurrencyObject();
	}
	
	static clsCurrency FindByCountry(string Country)
	{
		
		Country = clsString::UpperCaseAllLetter(Country);

		fstream file;
		vector<clsCurrency>vCurrencyData;

		file.open("Currencies.txt", ios::in);

		if (file.is_open())
		{
			string line;
		 
			while (getline(file, line))
			{
				clsCurrency Currency = _ConvertLinetoCurencyObject(line);

				if (clsString::UpperCaseAllLetter(Currency.Country()) == Country)
				{
					file.close();
					return Currency;
				}
			}

		}

		return _GetEmptyCurrencyObject();
		
	}

	static bool IsCurrencyExit(string CurrencyCode)
	{
		clsCurrency C1 = clsCurrency::FindByCode(CurrencyCode);

		return (!C1.IsEmpty());
	}

	static vector<clsCurrency>GetCurrencyList()
	{
		return _LoadCurrencyDataFromFile();
	}

	float ConvertToUsd(float Amount)
	{	
		return (float)(Amount / Rate());
	}

	float ConvertToOtherCurrency(float Amount,clsCurrency CurrencyTo)
	{
		float AmountInUsd = ConvertToUsd(Amount);

		if (clsString::UpperCaseAllLetter(CurrencyTo.CurrencyCode()) == "USD")
		{
			return AmountInUsd;
		}

			return (float)(AmountInUsd * CurrencyTo.Rate());
	}

};