// Prosedur ketika kartu pertama dan kedua sudah dioperasikan
#include "fitur.h"

#ifndef _BRUTEFORCE_H_
#define _BRUTEFORCE_H_

void bfSecond_1(vector<bil> card, string s)
{
    // Buat string dan vector sementara
    string tempS = s;
    vector<bil> tempCard = card;

    for (int i = 0; i < 4; i++)
    {
        if (i == 3) {
            if (isDivisible(card[0].pembilang, card[1].pembilang) == false)
            {
                break;
            }
        }
        tempCard[1] = operasi(op[i], card[0], card[1]);

        tempCard.erase(tempCard.begin());
        tempS = "(" + s + op[i] + to_string(card[1].pembilang) + ")";

        vector<bil> tempCard2 = tempCard;

        // Sekarang operasikan kartu hasil operasi barusan dengan kartu keempat
        for (int j = 0; j < 4; j++)
        {
            if (j == 3)
            {
                if (isDivisible(tempCard[0].pembilang, card[2].pembilang) == false)
                {
                    break;
                }
            }

            tempCard[0] = operasi(op[j], tempCard[0] , card[2]);

            tempS = tempS + op[j] + to_string(card[2].pembilang);
            cekValid(tempCard[0].pembilang/tempCard[0].penyebut, tempS);

            // Kembalikan string dan tempCard ke semula
            tempS = "(" + s + op[i] + to_string(card[1].pembilang) + ")";
            tempCard = tempCard2;
        }

        // Kembalikan string dan tempCard ke semula
        tempS = s;
        tempCard = card;
    }
}

// Prosedur ketika kartu ketiga dan keempat sudah dioperasikan
void bfSecond_2(vector<bil> card, string s)
{
    // Buat string dan vector sementara
    string tempS;
    vector<bil> tempCard = card;

    for (int i = 0; i < 4; i++)
    {
        // Kemungkinan semua operator
        if (i == 3)
        {
            if (isDivisible(card[0].pembilang, card[1].pembilang) == false)
            {
                break;
            }
        }

        tempCard[1] = operasi(op[i], card[0], card[1]);

        tempCard.erase(tempCard.begin());
        tempS = "(" + to_string(card[0].pembilang) + op[i] + to_string(card[1].pembilang) + ")";
        vector<bil> tempCard2 = tempCard;

        for (int j = 0; j < 4; j++)
        {
            // cout << "\t\t\toperator = " << op[j] << endl;
            // cout << "\t\t\tcard[2] = " << card[2] << endl;
            if (j == 3)
            {
                if (isDivisible(tempCard[0].pembilang, card[2].pembilang) == false)
                {
                    break;
                }
                
            }

            tempCard[0] = operasi(op[j], tempCard[0], card[2]);

            tempS = tempS + op[j] + s;
            cekValid(tempCard[0].pembilang/tempCard[0].penyebut, tempS);

            // Kembalikan string dan tempCard ke semula
            tempS = "(" + to_string(card[0].pembilang) + op[i] + to_string(card[1].pembilang) + ")";
            tempCard = tempCard2;
        }

        // Kembalikan tempCard ke semula
        tempCard = card;
    }
}

void bfThird_1(vector<bil> card, string s)
{
    string tempS;
    vector<bil> tempCard = card;

    // Operasikan kartu pertama dengan hasil kartu dari operasi pertama lalu operasikan dengan kartu keempat
    for (int i = 0; i < 4; i++)
    {
        if (i == 3)
        {
            if (isDivisible(card[0].pembilang, card[1].pembilang) == false)
            {
                break;
            }
        }

        tempCard[1] = operasi(op[i], card[0], card[1]);

        tempCard.erase(tempCard.begin());
        tempS = "(" + to_string(card[0].pembilang) + op[i] + s + ")";
        // cout << "\t\t" + tempS << endl;
        vector<bil> tempCard2 = tempCard;

        // Sekarang operasikan kartu hasil operasi barusan dengan kartu keempat
        for (int j = 0; j < 4; j++)
        {
            if (j == 3)
            {
                if (isDivisible(tempCard[0].pembilang, card[2].pembilang) == false)
                {
                    break;
                }
                
            }
            tempCard[0] = operasi(op[j], tempCard[0] ,card[2]);

            tempS = tempS + op[j] + to_string(card[2].pembilang);
            cekValid(tempCard[0].pembilang/tempCard[0].penyebut, tempS);

            // Kembalikan string dan tempCard ke semula
            tempS = "(" + to_string(card[0].pembilang) + op[i] + s + ")";
            tempCard = tempCard2;
        }

        // Kembalikan string dan tempCard ke semula
        tempS = s;
        tempCard = card;
    }
}

void bfThird_2(vector<bil> card, string s)
{
    string tempS;
    vector<bil> tempCard = card;

    // Operasikan kartu keempat dengan hasil kartu dari operasi pertama lalu operasikan dengan kartu pertama
    for (int i = 0; i < 4; i++)
    {
        // Kemungkinan semua operator
        if (i == 3)
        {
            if (isDivisible(card[1].pembilang, card[2].pembilang) == false)
            {
                break;
            }
        }

        tempCard[1] = operasi(op[i], card[1], card[2]);

        tempCard.erase(tempCard.begin() + 2);
        tempS = "(" + s + op[i] + to_string(card[2].pembilang) + ")";
        // cout << "\t\t" + tempS << endl;
        vector<bil> tempCard2 = tempCard;

        // Sekarang operasikan kartu hasil operasi barusan dengan kartu pertama
        for (int j = 0; j < 4; j++)
        {
            if (j == 3)
            {
                if (isDivisible(card[0].pembilang, tempCard[1].pembilang) == false)
                {
                    break;
                }
            }
            tempCard[0] = operasi(op[j], card[0], tempCard[1]);

            tempS = to_string(card[0].pembilang) + op[j] + tempS;
            cekValid(tempCard[0].pembilang/tempCard[0].penyebut, tempS);

            // Kembalikan string dan tempCard ke semula
            tempS = "(" + s + op[i] + to_string(card[2].pembilang) + ")";
            tempCard = tempCard2;
        }

        // Kembalikan string dan tempCard ke semula
        tempS = s;
        tempCard = card;
    }
}

// Prosedur ketika kartu kedua dan ketiga sudah dioperasikan
void bfSecond_3(vector<bil> card, string s)
{
    // Ada dua cabang dalam operasi ini
    // 1. Operasikan kartu pertama dengan hasil kartu dari operasi pertama lalu operasikan dengan kartu keempat
    // 2. Operasikan kartu keempat dengan hasil kartu dari operasi pertama lalu operasikan dengan kartu pertama

    // Operasi 1
    bfThird_1(card, s);
    bfThird_2(card, s);
}

// Prosedur untuk menentukan kartu mana yang harus dioperasikan terlebih dahulu
void bfFirst(vector<int> c)
{
    vector<bil> card(4);
    for (int i = 0; i < 4; i++) {
        card[i].pembilang = c[i];
        card[i].penyebut = 1;
    }
    vector<bil> tempCard = card;
    string s;

    for (int i = 0; i < 3; i++)
    {

        int j = i + 1;

        for (int k = 0; k < 4; k++)
        {
            if (op[k] == '/') {
                if (isDivisible(card[i].pembilang, card[j].pembilang) == false)
                {
                    break;
                }
            }
            tempCard[j] = operasi(op[k], card[i], card[j]);

            // cout << "\t"
            //      << "operasi = " << op[k] << endl;
            tempCard.erase(tempCard.begin() + i);
            s = "(" + to_string(card[i].pembilang) + op[k] + to_string(card[j].pembilang) + ")";

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