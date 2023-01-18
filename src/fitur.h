#ifndef _FITUR_H
#define _FITUR_H
#include "bilangan.h"

int cnt = 0;
vector<string> jawaban;

char op[4] = {'+', '-', '*', '/'};

void clearScreen() {
    cout << "\033[2J" << "\033[H";
}

// Fungsi cek apakah bilangan bisa dibagi
bool isDivisible(int a, int b)
{
    if (b != 0)
    {
        return true;
    }
    return false;
}

// Mengubah kartu menjadi angka
void cardToInt(string input[4], int output[4])
{
    for (int i = 0; i < 4; i++)
    {
        if (input[i] == "A")
        {
            output[i] = 1;
        }
        else if (input[i] == "J")
        {
            output[i] = 11;
        }
        else if (input[i] == "Q")
        {
            output[i] = 12;
        }
        else if (input[i] == "K")
        {
            output[i] = 13;
        }
        else
        {
            output[i] = stoi(input[i]);
        }
    }
}

void cekValid(int ans, string s)
{
    if (ans == 24)
    {
        cnt++;
        jawaban.push_back(s);
        // cout << "\t\t\t" << s << endl;
    }
}

#endif