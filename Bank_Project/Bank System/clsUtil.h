#pragma once
#include <iostream>
#include "clsDate.h"

using namespace std;

class clsUtil
{

public:

    static int RandomNumber(int From, int To)
    {
        return  rand() % (To - From + 1) + From;
    }

    static void Srand()
    {
        srand((unsigned)time(NULL));
    }

    enum enCharType
    {
        SmallLetter = 1, CaPitalLetter = 2, Digit = 3, MixChars = 4,
        SpecialCharacter = 5
    };

    static char GetRandomCharacter(enCharType CharType)
    {

        if (CharType == enCharType::MixChars)
        {
            CharType = (enCharType)RandomNumber(1, 3);
        }

        switch (CharType)
        {

        case clsUtil::SmallLetter:
        {
            return char(RandomNumber(97, 122));
        }

        case clsUtil::CaPitalLetter:
        {
            return char(RandomNumber(65, 90));
        }

        case clsUtil::Digit:
        {
            return char(RandomNumber(48, 57));
        }

        case clsUtil::SpecialCharacter:
        {
            return char(RandomNumber(33, 47));
        }

        }

    }

    static string GenerateWorld(enCharType CharType, short  Number)
    {
        string World;

        for (int i = 1; i <= Number; i++)
        {
            World += GetRandomCharacter(CharType);
        }

        return World;
    }

    static string GenerateKey(enCharType CharType)
    {
        string Key;

        for (int i = 1; i <= 4; i++)
        {
            for (int j = 1; j <= 4; j++)
            {
                Key += GetRandomCharacter(CharType);

                if (j == 4 && i != 4)
                {
                    Key += '-';
                }
            }
        }

        return Key;
    }

    static void GenerateKeys(short NumberOfKey, enCharType CharType)
    {

        for (int i = 1; i <= NumberOfKey; i++)
        {
            cout << "Key [" << i << "] : ";

            for (int j = 0; j < 1; j++)
            {
                cout << GenerateKey(CharType) << endl;
            }
        }
    }

    static void Swap(double& num1, double& num2)
    {
        double num;

        num = num1;
        num1 = num2;
        num2 = num;
    }

    static void Swap(int& num1, int& num2)
    {
        int num;

        num = num1;
        num1 = num2;
        num2 = num;
    }

    static void Swap(string& str1, string& str2)
    {
        string str;

        str = str1;
        str1 = str2;
        str2 = str;
    }

    static void Swap(clsDate& D1, clsDate& D2)
    {
        clsDate Date;

        Date = D1;
        D1 = D2;
        D2 = Date;
    }

    static void ShuffleArray(int arr[], int size)
    {
        int temp = 0;

        for (int i = 0; i < size; i++)
        {

            int index = rand() % size;

            temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
        }

    }

    static void ShuffleArray(string arr[], int size)
    {
        string temp;

        for (int i = 0; i < size; i++)
        {
            int index = rand() % size;

            temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
        }

    }

    static void ShuffleArrayWithRandomNumbers(int arr[], int size, int From, int To)
    {
        int temp;

        for (int j = 0; j < size; j++)
        {
            arr[j] = RandomNumber(From, To);
        }

        for (int i = 0; i < size; i++)
        {
            int index = rand() % size;

            temp = arr[i];
            arr[i] = arr[index];
            arr[index] = temp;
        }

    }

    static void ShuffleArrayWithRandomWorlds(string arr[], int size, enCharType CharType, int NumberofWorld)
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = GenerateWorld(CharType, NumberofWorld);
        }
    }

    static void ShuffleArrayWithRandomKeys(string arr[], int size, enCharType CharType)
    {
        for (int i = 0; i < size; i++)
        {
            arr[i] = GenerateKey(CharType);
        }
    }

    static string Tabs(int num)
    {
        string str;

        for (int i = 0; i < num; i++)
        {
            str += '\t';
        }

        return str;
    }

    static string  EncryptText(string Text, short EncryptionKey=2)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] + EncryptionKey);

        }

        return Text;

    }

    static string  DecryptText(string Text, short EncryptionKey=2)
    {

        for (int i = 0; i <= Text.length(); i++)
        {

            Text[i] = char((int)Text[i] - EncryptionKey);

        }
        return Text;

    }

    static string NumberToText(int Number)
    {

        if (Number == 0)
        {
            return "";
        }

        if (Number >= 1 && Number <= 19)
        {
            string arr[] = { "", "One","Two","Three","Four","Five","Six","Seven",
        "Eight","Nine","Ten","Eleven","Twelve","Thirteen","Fourteen",
          "Fifteen","Sixteen","Seventeen","Eighteen","Nineteen" };

            return  arr[Number] + " ";

        }

        if (Number >= 20 && Number <= 99)
        {
            string arr[] = { "","","Twenty","Thirty","Forty","Fifty","Sixty","Seventy","Eighty","Ninety" };
            return  arr[Number / 10] + " " + NumberToText(Number % 10);
        }

        if (Number >= 100 && Number <= 199)
        {
            return  "One Hundred " + NumberToText(Number % 100);
        }

        if (Number >= 200 && Number <= 999)
        {
            return   NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
        }

        if (Number >= 1000 && Number <= 1999)
        {
            return  "One Thousand " + NumberToText(Number % 1000);
        }

        if (Number >= 2000 && Number <= 999999)
        {
            return   NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
        }

        if (Number >= 1000000 && Number <= 1999999)
        {
            return  "One Million " + NumberToText(Number % 1000000);
        }

        if (Number >= 2000000 && Number <= 999999999)
        {
            return   NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
        }

        if (Number >= 1000000000 && Number <= 1999999999)
        {
            return  "One Billion " + NumberToText(Number % 1000000000);
        }
        else
        {
            return   NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
        }

    }

    static string Space(int num)
    {
        string str;

        for (int i = 0; i < num; i++)
        {
            str += ' ';
        }

        return str;
    }

};