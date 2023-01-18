// Prosedur ketika kartu pertama dan kedua sudah dioperasikan
#include "fitur.h"

#ifndef _BRUTEFORCE_H_
#define _BRUTEFORCE_H_

void bfSecond_1(vector<int> card, string s)
{
    // Buat string dan vector sementara
    string tempS = s;
    vector<int> tempCard = card;

    // cout << "\tcard = ";
    // for (int i = 0; i < 3; i++)
    // {
    //     cout << card[i] << " ";
    // }
    // cout << endl;
    // Operasikan kartu hasil operasi pertama dengan kartu ketiga
    for (int i = 0; i < 4; i++)
    {
        // cout << "\t\t\t" << card[0] << op[i] << card[1] << endl;
        // Kemungkinan semua operator
        if (i == 0)
        {
            tempCard[1] = card[0] + card[1];
        }
        else if (i == 1)
        {
            tempCard[1] = card[0] - card[1];
        }
        else if (i == 2)
        {
            tempCard[1] = card[0] * card[1];
        }
        else if (i == 3)
        {
            if (isDivisible(card[0], card[1]) == false)
            {
                // cout << "\t\t\tGagal" << endl;
                break;
            }
            tempCard[1] = card[0] / card[1];
            // cout << "\t\t\tLolos" << endl;
        }

        tempCard.erase(tempCard.begin());
        tempS = "(" + s + op[i] + to_string(card[1]) + ")";

        vector<int> tempCard2 = tempCard;

        // Sekarang operasikan kartu hasil operasi barusan dengan kartu keempat
        for (int j = 0; j < 4; j++)
        {
            // cout << "\t\t\t\t" << tempCard[0] << op[j] << card[2] << endl;
            if (j == 0)
            {
                tempCard[0] = tempCard[0] + card[2];
            }
            else if (j == 1)
            {
                tempCard[0] = tempCard[0] - card[2];
            }
            else if (j == 2)
            {
                tempCard[0] = tempCard[0] * card[2];
            }
            else if (j == 3)
            {
                if (isDivisible(tempCard[0], card[2]) == false)
                {
                    break;
                }
                tempCard[0] = tempCard[0] / card[2];
            }

            tempS = tempS + op[j] + to_string(card[2]);
            cekValid(tempCard[0], tempS);

            // Kembalikan string dan tempCard ke semula
            tempS = "(" + s + op[i] + to_string(card[1]) + ")";
            tempCard = tempCard2;
        }

        // Kembalikan string dan tempCard ke semula
        tempS = s;
        tempCard = card;
    }
}

// Prosedur ketika kartu ketiga dan keempat sudah dioperasikan
void bfSecond_2(vector<int> card, string s)
{
    // Buat string dan vector sementara
    string tempS;
    vector<int> tempCard = card;
    // cout << "\tcard = ";
    // for (int i = 0; i < 3; i++)
    // {
    //     cout << card[i] << " ";
    // }
    // cout << endl;
    // cout << "\tstring = " << s << endl;
    // Operasikan kartu pertama dan kedua
    for (int i = 0; i < 4; i++)
    {
        // Kemungkinan semua operator
        if (i == 0)
        {
            tempCard[1] = card[0] + card[1];
        }
        else if (i == 1)
        {
            tempCard[1] = card[0] - card[1];
        }
        else if (i == 2)
        {
            tempCard[1] = card[0] * card[1];
        }
        else if (i == 3)
        {
            if (isDivisible(card[0], card[1]) == false)
            {
                break;
            }
            tempCard[1] = card[0] / card[1];
        }

        tempCard.erase(tempCard.begin());
        tempS = "(" + to_string(card[0]) + op[i] + to_string(card[1]) + ")";
        vector<int> tempCard2 = tempCard;

        // cout << "\t\tstring2 = " << tempS << endl;
        // cout << "\t\tcard2 = ";
        // for (int i = 0; i < 2; i++)
        // {
        //     cout << tempCard[i] << " ";
        // }
        // cout << endl;
        // Sekarang operasikan kartu hasil operasi barusan dengan operasi pertama
        for (int j = 0; j < 4; j++)
        {
            // cout << "\t\t\toperator = " << op[j] << endl;
            // cout << "\t\t\tcard[2] = " << card[2] << endl;
            if (j == 0)
            {
                tempCard[0] = tempCard[0] + card[2];
            }
            else if (j == 1)
            {
                tempCard[0] = tempCard[0] - card[2];
            }
            else if (j == 2)
            {
                tempCard[0] = tempCard[0] * card[2];
            }
            else if (j == 3)
            {
                if (isDivisible(tempCard[0], card[2]) == false)
                {
                    break;
                }
                tempCard[0] = tempCard[0] / card[2];
            }

            tempS = tempS + op[j] + s;
            cekValid(tempCard[0], tempS);

            // Kembalikan string dan tempCard ke semula
            tempS = "(" + to_string(card[0]) + op[i] + to_string(card[1]) + ")";
            tempCard = tempCard2;
        }

        // Kembalikan tempCard ke semula
        tempCard = card;
    }
}

void bfThird_1(vector<int> card, string s)
{
    string tempS;
    vector<int> tempCard = card;

    // Operasikan kartu pertama dengan hasil kartu dari operasi pertama lalu operasikan dengan kartu keempat
    for (int i = 0; i < 4; i++)
    {
        // Kemungkinan semua operator
        if (i == 0)
        {
            tempCard[1] = card[0] + card[1];
        }
        else if (i == 1)
        {
            tempCard[1] = card[0] - card[1];
        }
        else if (i == 2)
        {
            tempCard[1] = card[0] * card[1];
        }
        else if (i == 3)
        {
            if (isDivisible(card[0], card[1]) == false)
            {
                break;
            }
            tempCard[1] = card[0] / card[1];
        }
        // cout << "\t\toperator = " << op[i] << endl;
        tempCard.erase(tempCard.begin());
        tempS = "(" + to_string(card[0]) + op[i] + s + ")";
        // cout << "\t\t" + tempS << endl;
        vector<int> tempCard2 = tempCard;

        // Sekarang operasikan kartu hasil operasi barusan dengan kartu keempat
        for (int j = 0; j < 4; j++)
        {
            if (j == 0)
            {
                tempCard[0] = tempCard[0] + card[2];
            }
            else if (j == 1)
            {
                tempCard[0] = tempCard[0] - card[2];
            }
            else if (j == 2)
            {
                tempCard[0] = tempCard[0] * card[2];
            }
            else if (j == 3)
            {
                if (isDivisible(tempCard[0], card[2]) == false)
                {
                    break;
                }
                tempCard[0] = tempCard[0] / card[2];
            }

            tempS = tempS + op[j] + to_string(card[2]);
            cekValid(tempCard[0], tempS);

            // Kembalikan string dan tempCard ke semula
            tempS = "(" + to_string(card[0]) + op[i] + s + ")";
            tempCard = tempCard2;
        }

        // Kembalikan string dan tempCard ke semula
        tempS = s;
        tempCard = card;
    }
}

void bfThird_2(vector<int> card, string s)
{
    string tempS;
    vector<int> tempCard = card;

    // Operasikan kartu keempat dengan hasil kartu dari operasi pertama lalu operasikan dengan kartu pertama
    for (int i = 0; i < 4; i++)
    {
        // Kemungkinan semua operator
        if (i == 0)
        {
            tempCard[1] = card[1] + card[2];
        }
        else if (i == 1)
        {
            tempCard[1] = card[1] - card[2];
        }
        else if (i == 2)
        {
            tempCard[1] = card[1] * card[2];
        }
        else if (i == 3)
        {
            if (isDivisible(card[1], card[2]) == false)
            {
                break;
            }
            tempCard[1] = card[1] / card[2];
        }
        // cout << "\t\toperator = " << op[i] << endl;
        tempCard.erase(tempCard.begin() + 2);
        tempS = "(" + s + op[i] + to_string(card[2]) + ")";
        // cout << "\t\t" + tempS << endl;
        vector<int> tempCard2 = tempCard;

        // Sekarang operasikan kartu hasil operasi barusan dengan kartu pertama
        for (int j = 0; j < 4; j++)
        {
            if (j == 0)
            {
                tempCard[0] = tempCard[1] + card[0];
            }
            else if (j == 1)
            {
                tempCard[0] = card[0] - tempCard[1];
            }
            else if (j == 2)
            {
                tempCard[0] = tempCard[1] * card[0];
            }
            else if (j == 3)
            {
                if (isDivisible(card[0], tempCard[1]) == false)
                {
                    break;
                }
                tempCard[0] = card[0] / tempCard[1];
            }

            tempS = to_string(card[0]) + op[j] + tempS;
            cekValid(tempCard[0], tempS);

            // Kembalikan string dan tempCard ke semula
            tempS = "(" + s + op[i] + to_string(card[2]) + ")";
            tempCard = tempCard2;
        }

        // Kembalikan string dan tempCard ke semula
        tempS = s;
        tempCard = card;
    }
}

// Prosedur ketika kartu kedua dan ketiga sudah dioperasikan
void bfSecond_3(vector<int> card, string s)
{
    // Ada dua cabang dalam operasi ini
    // 1. Operasikan kartu pertama dengan hasil kartu dari operasi pertama lalu operasikan dengan kartu keempat
    // 2. Operasikan kartu keempat dengan hasil kartu dari operasi pertama lalu operasikan dengan kartu pertama

    // Operasi 1
    bfThird_1(card, s);
    bfThird_2(card, s);
}

// Prosedur untuk menentukan kartu mana yang harus dioperasikan terlebih dahulu
void bfFirst(vector<int> card)
{
    vector<int> tempCard = card;
    string s;

    for (int i = 0; i < 3; i++)
    {

        int j = i + 1;

        for (int k = 0; k < 4; k++)
        {

            if (op[k] == '+')
            {
                tempCard[j] = card[i] + card[j];
            }
            else if (op[k] == '-')
            {
                tempCard[j] = card[i] - card[j];
            }
            else if (op[k] == '*')
            {
                tempCard[j] = card[i] * card[j];
            }
            else if (op[k] == '/')
            {
                if (isDivisible(card[i], card[j]) == false)
                {

                    break;
                }
                tempCard[j] = card[i] / card[j];
            }
            // cout << "\t"
            //      << "operasi = " << op[k] << endl;
            tempCard.erase(tempCard.begin() + i);
            s = "(" + to_string(card[i]) + op[k] + to_string(card[j]) + ")";

            if (i == 0)
            {
                bfSecond_1(tempCard, s);
            }
            else if (i == 2)
            {
                bfSecond_2(tempCard, s);
            }
            else
            {
                bfSecond_3(tempCard, s);
            }

            // Kembalikan string dan tempCard ke semula
            s = "";
            tempCard = card;
        }
    }
}

#endif