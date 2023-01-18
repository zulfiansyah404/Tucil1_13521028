// Penyelesaian Permainan Kartu 24 dengan Algoritma Brute Force
#include "splash.h"
#include "bruteforce.h"
using namespace std;

typedef long long ll;

int main()
{
    splash();

    cout << "Masukkan input 4 kartu yang dipisahkan dengan spasi/enter : " << endl;
    cout << "-----------------------------------------------------------" << endl;
    cout << "Input : " << endl;
    string input[4];
    cin >> input[0] >> input[1] >> input[2] >> input[3];
    float execution_time = clock();
    int output[4];
    cardToInt(input, output);

    // cout << output[0] << " " << output[1] << " " << output[2] << " " << output[3] << endl;

    vector<int> card(4);
    for (int i = 0; i < 4; i++)
    {
        card[i] = output[i];
    }

    do
    {
        // cout << "card = ";
        // for (int i = 0; i < 4; i++)
        // {
        //     cout << card[i] << " ";
        // }
        // cout << endl;
        bfFirst(card);
    } while (next_permutation(card.begin(), card.end()));

    execution_time = clock() - execution_time;
    // Output jawaban
    cout << endl << "Output : " << endl;

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
    for (int i = 0; i < time.length()+4; i++)
    {
        cout << "-";
    }
    cout << endl;
    cout << "| " << time << " |" << endl;
    for (int i = 0; i < time.length()+4; i++)
    {
        cout << "-";
    }
}