#pragma once

#include <iostream>
#include <vector>

using namespace std;

class clsString

{
private:

    string _Value;

public:

    clsString()
    {
        _Value = "";

    }

    clsString(string Value)
    {
        _Value = Value;
    }

    void SetValue(string Value)
    {
        _Value = Value;
    }

    string GetValue()
    {
        return _Value;
    }

    __declspec(property(get = GetValue, put = SetValue)) string Value;


    static short CountWords(string S1)
    {
        string Delim = " ";
        short pos = 0;
        short Count = 0;

        while ((pos = S1.find(Delim)) != string::npos)
        {
            Count++;

            S1.erase(0, pos + Delim.length());
        }

        if (S1 != " ")
        {
            Count++;
        }

        return Count;
    }

    short CountWords()
    {
        return CountWords(_Value);
    }

    static vector<string> Split(string S1, string Delim)
    {
        string Word;
        short pos = 0;

        vector<string>vElement;

        while ((pos = S1.find(Delim)) != string::npos)
        {
            Word = S1.substr(0, pos);

            if (Word != " ")
            {
                vElement.push_back(Word);
            }

            S1.erase(0, pos + Delim.length());
        }

        if (S1 != " ")
        {
            vElement.push_back(S1);
        }

        return vElement;
    }

    static string SplitString(string S1)
    {
        string Delim = " ";
        string Word;
        short pos = 0;


        while ((pos = S1.find(Delim)) != string::npos)
        {
            Word += S1.substr(0, pos);

            if (Word != " ")
            {
                Word = Word + "";
            }

            S1.erase(0, pos + Delim.length());
        }

        if (S1 != " ")
        {
            Word += S1;
        }

        return Word;
    }

    string SplitString()
    {
        return SplitString(_Value);
    }

    __declspec(property(get = GetChar, put = SetChar)) char Word;


    static  bool isupper(char Char1)
    {
        return int(Char1) >= 65 && int(Char1) <= 90;
    }



    static  bool islower(char Char1)
    {
        return int(Char1) >= 97 && int(Char1) <= 122;
    }



    static char toupper(char Char1)
    {
        return char(int(Char1) - 32);
    }


    static char tolower(char Char1)
    {
        return char(int(Char1) + 32);
    }

    static bool isspace(char Char1)
    {
        return int(Char1) == 32;
    }


    static short size(string Value)
    {
        short i = 0;
        short size = 0;

        while (int(char(Value[i])) != 0)
        {
            size = ++i;
        }

        return size;
    }

    short size()
    {
        return  size(_Value);
    }

    static void FirstLetter(string S1)
    {
        bool IsFirstLetter = true;

        for (int i = 0; i < S1.size(); i++)
        {

            if (S1[i] != ' ' && IsFirstLetter)
            {
                cout << S1[i] << endl;
            }

            IsFirstLetter = (S1[i] == ' ' ? true : false);
        }

    }

    void FirstLetter()
    {
        FirstLetter(_Value);
    }

    static string UpperCaseFirstLetter(string str)
    {
        bool IsFirstLetter = true;


        for (int i = 0; i < str.size(); i++)
        {

            if (str[i] != ' ' && IsFirstLetter)
            {
                str[i] = toupper(str[i]);
            }

            IsFirstLetter = (str[i] == ' ' ? true : false);

        }

        return str;

    }

    void UpperCaseFirstLetter()
    {
        _Value = UpperCaseFirstLetter(_Value);
    }

    static string LowerCaseFirstLetter(string str)
    {

        bool IsFirstLetter = true;

        for (int i = 0; i < str.size(); i++)
        {

            if (str[i] != ' ' && IsFirstLetter)
            {
                if (isupper(str[i]))
                {
                    str[i] = tolower(str[i]);
                }

            }

            IsFirstLetter = (str[i] == ' ' ? true : false);

        }

        return str;
    }

    void LowerCaseFirstLetter()
    {
        _Value = LowerCaseFirstLetter(_Value);
    }

    static string UpperCaseAllLetter(string str)
    {
        for (int i = 0; i < str.size(); i++)
        {
            if (islower(str[i]))
            {
                str[i] = toupper(str[i]);
            }

        }
        return str;
    }

    void UpperCaseAllLetter()
    {
        _Value = UpperCaseAllLetter(_Value);
    }

    static string LowerAllstring(string str)
    {
        for (int i = 0; i < str.size(); i++)
        {
            if (isupper(str[i]))
            {
                str[i] = tolower(str[i]);
            }

        }

        return str;
    }

    void LowerAllstring()
    {
        _Value = LowerAllstring(_Value);
    }

    static char InvertLetterCase(char char1)
    {
        return islower(char1) ? toupper(char1) : tolower(char1);
    }



    static string InvertAllLetterCase(string str)
    {
        for (int i = 0; i < str.size(); i++)
        {
            if (!isspace(str[i]))
                str[i] = InvertLetterCase(str[i]);

        }

        return str;
    }

    string InvertAllLetterCase()
    {
        return InvertAllLetterCase(_Value);
    }

    static short CountCapitalLetter(string str)
    {
        short Count = 0;

        for (int i = 0; i < str.size(); i++)
        {
            if (isupper(str[i]))
            {
                Count++;
            }
        }
        return Count;
    }

    short CountCapitalLetter()
    {
        return CountCapitalLetter(_Value);
    }

    static short CountSmallLetter(string str)
    {
        short Count = 0;

        for (int i = 0; i < str.size(); i++)
        {
            if (islower(str[i]))
            {
                Count++;
            }
        }
        return Count;
    }

    short CountSmallLetter()
    {
        return CountSmallLetter(_Value);
    }


    short CountSpecificLetter(string str, char char1)
    {
        short Count = 0;

        for (int i = 0; i < str.size(); i++)
        {
            if (str[i] == char1)
                Count++;

        }

        return Count;
    }

    short CountSpecificLetter(char char1)
    {
        return CountSpecificLetter(_Value, char1);
    }

    static short CountVowels(string str)
    {
        string vowels = "aeiou";
        short Count = 0;

        for (int i = 0; i < str.size(); i++)
        {
            for (int j = 0; j < vowels.size(); j++)
            {
                if (str[i] == vowels[j])
                {
                    Count++;
                }
            }

        }
        return Count;

    }
    short CountVowels()
    {
        return CountVowels(_Value);
    }

    static bool IsVowel(char char1)
    {
        string vowels = "aeiou";

        for (int i = 0; i < vowels.size(); i++)
        {
            if (char1 == vowels[i])
            {
                return true;
            }
        }
        return false;
    }

    static string JoinString(string Arr[])
    {
        string str = "";



        return str;
    }

    static string JoinString(vector<string>vWorld)
    {
        string str = "";

        for (int i = 0; i < vWorld.size(); i++)
        {
            str += vWorld[i] + " ";
        }

        return str;
    }

    static short CountLetters(string str,short Letter)
    {
        return  Letter;
    }

};