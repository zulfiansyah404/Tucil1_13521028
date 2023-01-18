// Penyelesaian Permainan Kartu 24 dengan Algoritma Brute Force
#include "splash.h"
#include "bruteforce.h"
using namespace std;

typedef long long ll;

void Input(string pesan_kesalahan)
{   
    int output[100];
    while (true)
    {
        clearScreen();
        splash();

        cout << pesan_kesalahan;

        cout << "Masukkan input 4 kartu yang dipisahkan dengan spasi/enter : " << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "Input : " << endl;

        string inputWithSpace;
        getline(cin, inputWithSpace);

        string input[1000];
        int j = 0;
        int len = inputWithSpace.length();
        for (int i = 0; i < len; i++)
        {
            if (inputWithSpace[i] != ' ')
            {
                input[j] += inputWithSpace[i];
            }
            else
            {
                j++;
            }
        }

        if (j != 3)
        {
            pesan_kesalahan = "Input harus terdiri dari 4 karakter! Silahkan coba lagi.\n\n";
            continue;
        }

        cardToInt(input, output);

        if (output[0] == -1 || output[1] == -1 || output[2] == -1 || output[3] == -1)
        {
            pesan_kesalahan = "Input tidak valid! Silahkan coba lagi.\n\n";
            continue;
        }
        else
        {
            break;
        }
    }

    // cout << output[0] << " " << output[1] << " " << output[2] << " " << output[3] << endl;

    vector<int> card(4);

    for (int i = 0; i < 4; i++)
    {
        card[i] = output[i];
    }
    float execution_time = clock();
    do
    {
        bfFirst(card);
    } while (next_permutation(card.begin(), card.end()));

    execution_time = clock() - execution_time;

    // Output jawaban
    cout << endl
         << "Output : " << endl;

    if (cnt == 0)
    {
        cout << "No Solution!" << endl;
    }
    else
    {
        cout << cnt << " solution found!" << endl;
        for (int i = 0; i < jawaban.size(); i++)
        {
            cout << jawaban[i] << endl;
        }
    }

    cout << endl;
    string time = "Execution Time = " + to_string(execution_time) + " ms";
    for (int i = 0; i < time.length() + 4; i++)
    {
        cout << "-";
    }
    cout << endl;
    cout << "| " << time << " |" << endl;
    for (int i = 0; i < time.length() + 4; i++)
    {
        cout << "-";
    }
}

void randomInput() {
    int output[4];
    
    string input[4];
    randomInput(input);

    clearScreen();
    splash();

    cout << "Random Input" << endl;
    cout << "------------" << endl;
    cout << "Input : " << endl;
    for (int i = 0; i < 4; i++) {
        cout << input[i] << " ";
    }
    cout << endl;
    

    cardToInt(input, output);

    vector<int> card(4);

    for (int i = 0; i < 4; i++)
    {
        card[i] = output[i];
    }
    float execution_time = clock();
    do
    {
        bfFirst(card);
    } while (next_permutation(card.begin(), card.end()));

    execution_time = clock() - execution_time;

    // Output jawaban
    cout << endl
         << "Output : " << endl;

    if (cnt == 0)
    {
        cout << "No Solution!" << endl;
    }
    else
    {
        cout << cnt << " solution found!" << endl;
        for (int i = 0; i < jawaban.size(); i++)
        {
            cout << jawaban[i] << endl;
        }
    }

    cout << endl;
    string time = "Execution Time = " + to_string(execution_time) + " ms";
    for (int i = 0; i < time.length() + 4; i++)
    {
        cout << "-";
    }
    cout << endl;
    cout << "| " << time << " |" << endl;
    for (int i = 0; i < time.length() + 4; i++)
    {
        cout << "-";
    }

}

void chooseInput(string pesan_kesalahan) {
    while (true)
    {
        clearScreen();
        splash();

        cout << pesan_kesalahan;

        cout << "Pilih input : " << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "1. Input manual" << endl;
        cout << "2. Input Random" << endl;
        cout << "3. Keluar" << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "Input : " << endl;

        string input;
        getline(cin, input);

        if (input == "1")
        {
            Input("");
            break;
        }
        else if (input == "2")
        {
            randomInput();
            break;
        }
        else if (input == "3")
        {
            exit(0);
        }
        else
        {
            pesan_kesalahan = "Input tidak valid! Silahkan coba lagi.\n\n";
            continue;
        }
    }
}
int main() {
    chooseInput("");

    // Cek apakah output ingin dieksport ke file

    cout << "\n\nApakah anda ingin mengeksport output ke file? (tekan y untuk YA) : ";
    string input;
    cin >> input;
    if (input == "y") {
        exportAnswer();
    }


}