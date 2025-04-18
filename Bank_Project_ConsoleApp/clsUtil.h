#pragma once

#include <iostream>
#include <string>
#include <cmath>
#include "clsDate.h"

using namespace std;

class clsUtil
{
public:
    enum enCharType
    {
        SamallLetter = 1,
        CapitalLetter = 2,
        Digit = 3,
        MixChars = 4,
        SpecialCharacter = 5
    };

    short SumFrom1toN(short Number)
    {
        return Number * (Number + 1) / 2;
    }

    static void Srand()
    {
        srand((unsigned)time(NULL));
    }

    static int RandomNumber(int From, int To)
    {
        return rand() % (To - From + 1) + From;
    }

    short RandomShort(short From, short To)
    {
        return rand() % (To - From + 1) + From;
    }

    static char GetRandomCharacter(enCharType CharType)
    {
        if (CharType == MixChars)
        {
            CharType = (enCharType)RandomNumber(1, 3);
        }
        switch (CharType)
        {
        case enCharType::SamallLetter:
        {
            return char(RandomNumber(97, 122));
        }
        case enCharType::CapitalLetter:
        {
            return char(RandomNumber(65, 90));
        }
        case enCharType::SpecialCharacter:
        {
            return char(RandomNumber(33, 47));
        }
        case enCharType::Digit:
        {
            return char(RandomNumber(48, 57));
        }
        default:
        {
            return char(RandomNumber(65, 90));
        }
        }
    }

    static string GenerateWord(enCharType CharType, short Length)
    {
        string Word;
        for (int i = 1; i <= Length; i++)
        {
            Word = Word + GetRandomCharacter(CharType);
        }
        return Word;
    }

    static string GenerateKey(enCharType CharType = CapitalLetter)
    {
        string Key = "";
        Key = GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4) + "-";
        Key = Key + GenerateWord(CharType, 4);
        return Key;
    }

    static void GenerateKeys(short NumberOfKeys, enCharType CharType)
    {
        for (int i = 1; i <= NumberOfKeys; i++)
        {
            cout << "Key [" << i << "] : ";
            cout << GenerateKey(CharType) << endl;
        }
    }

    static void FillArrayWithRandomNumbers(int Arr[100], int ArrLength, int From, int To)
    {
        for (int i = 0; i < ArrLength; i++)
        {
            Arr[i] = RandomNumber(From, To);
        }
    }

    static void FillArrayWithRandomWords(string Arr[100], int ArrLength, enCharType CharType, short Wordlength)
    {
        for (int i = 0; i < ArrLength; i++)
            Arr[i] = GenerateWord(CharType, Wordlength);
    }

    static void FillArrayWithRandomKeys(string Arr[100], int ArrLength, enCharType CharType)
    {
        for (int i = 0; i < ArrLength; i++)
            Arr[i] = GenerateKey(CharType);
    }

    static void Swap(int &A, int &B)
    {
        int Temp;
        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(double &A, double &B)
    {
        double Temp;
        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(bool &A, bool &B)
    {
        bool Temp;
        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(char &A, char &B)
    {
        char Temp;
        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(string &A, string &B)
    {
        string Temp;
        Temp = A;
        A = B;
        B = Temp;
    }

    static void Swap(clsDate &A, clsDate &B)
    {
        clsDate::SwapDates(A, B);
    }

    static void ShuffleArray(int Arr[100], int ArrLength)
    {
        for (int i = 0; i < ArrLength; i++)
        {
            Swap(Arr[RandomNumber(1, ArrLength) - 1], Arr[RandomNumber(1, ArrLength) - 1]);
        }
    }

    static void ShuffleArray(string Arr[100], int ArrLength)
    {
        for (int i = 0; i < ArrLength; i++)
        {
            Swap(Arr[RandomNumber(1, ArrLength) - 1], Arr[RandomNumber(1, ArrLength) - 1]);
        }
    }

    static string Tabs(short NumberOfTabs)
    {
        string t = "";
        for (int i = 1; i < NumberOfTabs; i++)
        {
            t = t + "\t";
            cout << t;
        }
        return t;
    }

    static string EncryptText(string Text, short EncryptionKey = 2)
    {
        for (int i = 0; i <= Text.length(); i++)
        {
            Text[i] = char((int)Text[i] + EncryptionKey);
        }
        return Text;
    }

    static string DecryptText(string Text, short EncryptionKey = 2)
    {
        for (int i = 0; i <= Text.length(); i++)
        {
            Text[i] = char((int)Text[i] - EncryptionKey);
        }
        return Text;
    }

    static void ClearScreen()
    {
        system("clear"); // For linux
        system("CLS");   // For windows
    }

    static void ResetColorsToDefult()
    {
        system("echo -e \"\\033[0m\""); // for linux
        system("color 0f");             // for windows
    }

    static void TurnBackgroundToBlack()
    {
        system("echo -e \"\\033[40;37m\""); // for linux
        system("color 0f");                 // for windows
    }

    static void TurnBackgroundToGreen()
    {
        system("echo -e \"\\033[42m\""); // for linux
        system("color 2F");              // for windows
    }

    static void TurnBackgroundToRed()
    {
        system("echo -e \"\\033[41;37m\""); // for linux
        system("color 4F");                 // for windows
    }

    static void TurnBackgroundToYellow()
    {
        system("echo -e \"\\033[43;30m\""); // for linux
        system("color 6F");                 // for windows
    }

    int MyRound(float Number)
    {
        int IntPart = (int)Number;
        float FractionPart = Number - (int)Number; //= GetFractionPart(Number);
        if (abs(FractionPart) >= 0.5)
        {
            if (Number > 0)
            {
                return ++IntPart;
            }
            else
            {
                return --IntPart;
            }
        }
        else
        {
            return IntPart;
        }
    }

    int MyFloor(float Number)
    {
        if (Number > 0)
        {
            return (int)Number;
        }
        else
        {
            return (int)Number - 1;
        }
    }

    int MyCeil(float Number)
    {
        if (Number > 0)
        {
            return (int)Number + 1;
        }
        else
        {
            return (int)Number;
        }
    }

    int MySqrt(float Number)
    {
        return pow(Number, 0.5);
    }

    float MyAbs(float Number)
    {
        if (Number >= 0)
        {
            return Number;
        }
        else
        {
            return Number * -1;
        }
    }

    static string NumberToText(int Number)
    {
        if (Number == 0)
        {
            return "";
        }

        else if (Number >= 1 && Number <= 19)
        {
            string Arr[] = {"", "One", "Two", "Three", "Four", "Five", "Six", "Seven", "Eight", "Nine", "Ten", "Eleven", "Twelve", "Thirteen", "Fourteen", "Fifteen", "Sixteen", "Seventeen", "Eighteen", "Nineteen"};
            return Arr[Number] + " ";
        }

        else if (Number >= 20 && Number <= 99)
        {
            string Arr[] = {"", "", "Twenty", "Thirty", "Forty", "Fifty", "Sixty", "Seventy", "Eighty", "Ninety"};
            return Arr[Number / 10] + " " + NumberToText(Number % 10);
        }

        else if (Number >= 100 && Number <= 199)
        {
            return "One Hundred " + NumberToText(Number % 100);
        }

        else if (Number >= 200 && Number <= 999)
        {
            return NumberToText(Number / 100) + "Hundreds " + NumberToText(Number % 100);
        }

        else if (Number >= 1000 && Number <= 1999)
        {
            return "One Thousand " + NumberToText(Number % 1000);
        }

        else if (Number >= 2000 && Number <= 999999)
        {
            return NumberToText(Number / 1000) + "Thousands " + NumberToText(Number % 1000);
        }

        else if (Number >= 1000000 && Number <= 1999999)
        {
            return "One Million " + NumberToText(Number % 1000000);
        }

        else if (Number >= 2000000 && Number <= 999999999)
        {
            return NumberToText(Number / 1000000) + "Millions " + NumberToText(Number % 1000000);
        }

        else if (Number >= 1000000000 && Number <= 1999999999)
        {
            return "One Billion " + NumberToText(Number % 1000000000);
        }

        else
        {
            return NumberToText(Number / 1000000000) + "Billions " + NumberToText(Number % 1000000000);
        }
    }
};