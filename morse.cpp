#include <iostream>
#include <string>

using namespace std;

char morseDecoder(string morse) {
    char tree[64] = {};

    tree[2] = 'E';  tree[3] = 'T';
    tree[4] = 'I';  tree[5] = 'A';
    tree[6] = 'N';  tree[7] = 'M';
    tree[8] = 'S';  tree[9] = 'U';
    tree[10] = 'R'; tree[11] = 'W';
    tree[12] = 'D'; tree[13] = 'K';
    tree[14] = 'G'; tree[15] = 'O';

    tree[16] = 'H'; tree[17] = 'V';
    tree[18] = 'F'; tree[20] = 'L';
    tree[22] = 'P'; tree[23] = 'J';
    tree[24] = 'B'; tree[25] = 'X';
    tree[26] = 'C'; tree[27] = 'Y';
    tree[28] = 'Z'; tree[29] = 'Q';

    int posisi = 1;

    for (int i = 0; i < morse.length(); i++) {
        if (morse[i] == '.') {
            posisi = posisi * 2;
        } else if (morse[i] == '-') {
            posisi = posisi * 2 + 1;
        }
    }

    if (posisi < 64 && tree[posisi] != '\0') {
        return tree[posisi];
    }

    return '?';
}

int main() {
    string input;
    string morseLetter = "";

    cout << "Masukkan kode morse : ";
    getline(cin, input);

    cout << "translasi : ";

    for (int i = 0; i < input.length(); i++) {
        if (input[i] == '.' || input[i] == '-') {
            morseLetter += input[i];
        } else if (input[i] == ' ') {
            if (morseLetter != "") {
                cout << morseDecoder(morseLetter);
                morseLetter = "";
            }
        } else if (input[i] == '/') {
            if (morseLetter != "") {
                cout << morseDecoder(morseLetter);
                morseLetter = "";
            }
            cout << " ";
        }
    }

    if (morseLetter != "") {
        cout << morseDecoder(morseLetter);
    }

    cout << endl;
    return 0;
}