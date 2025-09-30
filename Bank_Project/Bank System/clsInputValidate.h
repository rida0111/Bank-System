#pragma once

#include <iostream>
#include"clsDate.h"

using namespace std;

class clsInputValidate
{
public:

    static bool IsNumberBetween(int number, int From, int To)
    {
        return number >= From && number <= To;
    }

    static bool IsNumberBetween(double number, double From, double To)
    {
        return number >= From && number <= To;
    }

    static bool IsNumberBetween(float number, float From, float To)
    {
        return number >= From && number <= To;
    }

    static bool IsDateBetween(clsDate Date, clsDate Date1, clsDate Date2)
    {

        return  clsDate::IsDateAfterDate(Date, Date1) && clsDate::IsDateAfterDate(Date, Date2);

    }

    static int ReadIntNumber(string Message)
    {
        int number;

        cin >> number;

        while (cin.fail())
        {
            cin.clear();

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << Message;

            cin >> number;

        }

        return number;
    }

    static int ReadDblNumber(string Message)
    {
        double number;

        cin >> number;

        while (cin.fail())
        {
            cin.clear();

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << Message;

            cin >> number;

        }

        return number;
    }

    static int ReadIntNumberBetween(int From, int To, string Message)
    {
        int number;

        cin >> number;

        while (!IsNumberBetween(number, From, To))
        {
            cin.clear();

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << Message;

            cin >> number;

        }

        return number;

    }

    static short ReadShortNumberBetween(short From, short To, string Message)
    {
        short number;

        cin >> number;

        while (!IsNumberBetween(number, From, To))
        {
            cin.clear();

            cin.ignore(numeric_limits<streamsize>::max(), '\n');

            cout << Message;
            cin >> number;

            if (!IsNumberBetween(number, From, To))

            {
                cout << "Invalid Number ,Enter again\n";
                cin >> number;
            }
            else
                break;

        }

        return number;

    }

    static double ReadDblNumberBetween(double From, double To, string Message)
    {
        double number;

        cin >> number;

        while (!IsNumberBetween(number, From, To))
        {
            cin.clear();

            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            cout << Message;

            cin >> number;

        }

        return number;

    }

    static bool IsValideDate(clsDate Date)
    {
        return clsDate::IsValidDate(Date);
    }

    static string ReadString()
    {
        string  S1 = "";
        getline(cin >> ws, S1);


        return S1;
    }


};


