#ifndef _FITUR_H
#define _FITUR_H
#include "bilangan.h"

int cnt = 0;
vector<string> jawaban;

char op[4] = {'+', '-', '*', '/'};

void clearScreen() {
    cout << "\033[2J" << "\033[H";
}

// Fungsi mengekspor jawaban ke file
void exportAnswer(string input[]) {
    ofstream file;
    file.open("../test/answer_" + input[0] + "_" + input[1] + "_" + input[2] + "_" + input[3] + "_" + ".txt");
    if (cnt == 0) {
        file << "No Solution!" << endl;
    } else {
        file << cnt << " solution found!" << endl;
        for (int i = 0; i < jawaban.size(); i++) {
            file << jawaban[i] << endl;
        }
    }
    file.close();
    cout << endl;
    cout << "----------------------------------------" << endl;
    cout << "| Jawaban diexport ke file jawaban.txt |" << endl;
    cout << "----------------------------------------" << endl;
}

// Fungsi memilih kartu random
void randomInput(string input[])
{
    for (int i = 0; i < 4; i++)
    {
        int random = rand() % 13 + 1;
        if (random == 1)
        {
            input[i] = "A";
        }
        else if (random == 11)
        {
            input[i] = "J";
        }
        else if (random == 12)
        {
            input[i] = "Q";
        }
        else if (random == 13)
        {
            input[i] = "K";
        }
        else
        {
            input[i] = to_string(random);
        }
    }

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
        // Cek apakah input bukan merupakan angka
        if (input[i][0] >= '2' && input[i][0] <= '9' && input[i][1] == '\0')
        {
            output[i] = stoi(input[i]);
        }
        else
        if (input[i][0] == '1' && input[i][1] == '0')
        {
            output[i] = 10;
        }
        else
        {
            output[i] = -1;
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