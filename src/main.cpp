// Penyelesaian Permainan Kartu 24 dengan Algoritma Brute Force
#include "splash.h"
#include "bruteforce.h"
using namespace std;

typedef long long ll;

void process(string input[]) {
    // Konversi input ke bilangan
    int output[4];
    cardToInt(input, output);

    vector<int> card(4);
    for (int i = 0; i < 4; i++) {
        card[i] = output[i];
    }
    float execution_time = clock();

    // Lakukan permutasi dari card dan cek apakah ada solusi tanpa menggunakan STL
    for (int i = 0; i < 4; i++) {
        for (int j = 0; j < 4; j++) {
            if (j == i) {
                continue;
            }
            for (int k = 0; k < 4; k++) {
                if (k == i || k == j) {
                    continue;
                }
                for (int l = 0; l < 4; l++) {
                    if (l == i || l == j || l == k) {
                        continue;
                    }
                    vector<int> temp;
                    temp.push_back(card[i]);
                    temp.push_back(card[j]);
                    temp.push_back(card[k]);
                    temp.push_back(card[l]);
                    bfFirst(temp);
                }
            }
        }
    }

    execution_time = clock() - execution_time;

    // Output jawaban
    cout << endl << "Output : " << endl;
    if (cnt == 0) {
        cout << "No Solution!" << endl;
    } else {
        cout << cnt << " solution found!" << endl;
        for (int i = 0; i < jawaban.size(); i++) {
            cout << jawaban[i] << endl;
        }
    }

    cout << endl;
    string time = "Execution Time = " + to_string(execution_time) + " ms";
    for (int i = 0; i < time.length() + 4; i++) {
        cout << "-";
    }
    cout << endl;
    cout << "| " << time << " |" << endl;
    for (int i = 0; i < time.length() + 4; i++) {
        cout << "-";
    }

    // Cek apakah output ingin dieksport ke file
    cout << "\n\nApakah anda ingin mengeksport output ke file? (tekan y untuk YA) : ";
    string inp;
    cin >> inp;
    if (inp == "y") {
        exportAnswer(input);
    }
}

void Input(string pesan_kesalahan)
{
    while (true)
    {
        int output[100];
        string input[1000];
        clearScreen();
        splash();

        cout << pesan_kesalahan;

        cout << "Masukkan input 4 kartu yang dipisahkan dengan spasi/enter : " << endl;
        cout << "-----------------------------------------------------------" << endl;
        cout << "Input : " << endl;

        string inputWithSpace;
        getline(cin, inputWithSpace);

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

        // Jika salah dua kartu ada yang sama maka input tidak valid
        if (input[0] == input[1] || input[0] == input[2] || input[0] == input[3] || input[1] == input[2] || input[1] == input[3] || input[2] == input[3])
        {
            pesan_kesalahan = "Input tidak boleh sama! Silahkan coba lagi.\n\n";
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
            process(input);
            break;
        }
    }

    
}

void randomInput()
{

    string input[4];
    randomInput(input);

    clearScreen();
    splash();

    cout << "Random Input" << endl;
    cout << "------------" << endl;
    cout << "Input : " << endl;
    for (int i = 0; i < 4; i++)
    {
        cout << input[i] << " ";
    }
    cout << endl;

    process(input);
}

void chooseInput(string pesan_kesalahan)
{
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
int main()
{
    chooseInput("");
}