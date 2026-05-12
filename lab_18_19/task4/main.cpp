#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

vector<vector<char>> createPolybiusSquare() {

    vector<vector<char>> square = {
        {'A', 'B', 'C', 'D', 'E'},
        {'F', 'G', 'H', 'I', 'K'},
        {'L', 'M', 'N', 'O', 'P'},
        {'Q', 'R', 'S', 'T', 'U'},
        {'V', 'W', 'X', 'Y', 'Z'}
    };

    return square;
}

void printSquare(const vector<vector<char>>& square) {

    cout << "\n========== POLYBIUS SQUARE ==========\n\n";

    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {
            cout << square[i][j] << " ";
        }

        cout << endl;
    }
}

string encryptPolybius(string text, const vector<vector<char>>& square) {

    string result;

    for (char c : text) {

        c = toupper((unsigned char)c);

        if (c == 'J')
            c = 'I';

        bool found = false;

        for (int i = 0; i < 5 && !found; i++) {

            for (int j = 0; j < 5; j++) {

                if (square[i][j] == c) {

                    result += to_string(i + 1);
                    result += to_string(j + 1);
                    result += " ";

                    found = true;
                    break;
                }
            }
        }
    }

    return result;
}

string decryptPolybius(string code, const vector<vector<char>>& square) {

    string result;

    for (int i = 0; i < code.length(); i++) {

        if (isdigit(code[i]) && isdigit(code[i + 1])) {

            int row = code[i] - '0' - 1;
            int col = code[i + 1] - '0' - 1;

            result += square[row][col];

            i++;
        }
    }

    return result;
}

string readFromFile(const string& filename) {

    ifstream file(filename);

    if (!file) {
        return "";
    }

    string text, line;

    while (getline(file, line)) {
        text += line + '\n';
    }

    return text;
}

int main() {

    vector<vector<char>> square = createPolybiusSquare();

    string text;
    int choice;

    while (true) {

        cout << "\n========== POLYBIUS CIPHER ==========\n";

        cout << "Current text:\n";

        if (text.empty())
            cout << "[EMPTY]\n";
        else
            cout << text << endl;

        cout << "\nMenu:\n";
        cout << "1. Enter text\n";
        cout << "2. Load text from file\n";
        cout << "3. Encrypt text\n";
        cout << "4. Decrypt text\n";
        cout << "5. Show Polybius square\n";
        cout << "6. Clear text\n";
        cout << "0. Exit\n";

        cout << "\nChoose option: ";
        cin >> choice;
        cin.ignore();

        if (choice == 0) {
            cout << "Program ended.\n";
            break;
        }

        switch (choice) {

        case 1: {

            cout << "Enter text: ";
            getline(cin, text);

            break;
        }

        case 2: {

            string filename;

            cout << "Enter file name: ";
            getline(cin, filename);

            text = readFromFile(filename);

            cout << "File loaded successfully.\n";

            break;
        }

        case 3: {

            if (text.empty()) {
                cout << "Text is empty!\n";
                break;
            }

            string original = text;

            string encrypted = encryptPolybius(text, square);

            cout << "\nOriginal text:\n";
            cout << original << endl;

            cout << "\nEncrypted text:\n";
            cout << encrypted << endl;

            text = encrypted;

            break;
        }

        case 4: {

            if (text.empty()) {
                cout << "Text is empty!\n";
                break;
            }

            string encrypted = text;

            string decrypted = decryptPolybius(text, square);

            cout << "\nEncrypted text:\n";
            cout << encrypted << endl;

            cout << "\nDecrypted text:\n";
            cout << decrypted << endl;

            text = decrypted;

            break;
        }

        case 5: {

            printSquare(square);

            break;
        }

        case 6: {

            text.clear();

            cout << "Text cleared.\n";

            break;
        }

        default:
            cout << "Invalid option!\n";
        }
    }

    return 0;
}