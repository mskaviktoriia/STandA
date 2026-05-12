#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <cctype>

using namespace std;

vector<vector<char>> matrix(5, vector<char>(5));

string prepareKey(string key) {

    string result;

    for (char c : key) {

        c = toupper((unsigned char)c);

        if (c == 'J')
            c = 'I';

        if (isalpha(c) && result.find(c) == string::npos) {
            result += c;
        }
    }

    return result;
}

void generateMatrix(string key) {

    string alphabet = "ABCDEFGHIKLMNOPQRSTUVWXYZ";

    key = prepareKey(key);

    string fullKey = key;

    for (char c : alphabet) {

        if (fullKey.find(c) == string::npos) {
            fullKey += c;
        }
    }

    int index = 0;

    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {

            matrix[i][j] = fullKey[index++];
        }
    }
}

void printMatrix() {

    cout << "\n========== PLAYFAIR MATRIX ==========\n\n";

    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {

            cout << matrix[i][j] << " ";
        }

        cout << endl;
    }
}

pair<int, int> findPosition(char c) {

    if (c == 'J')
        c = 'I';

    for (int i = 0; i < 5; i++) {

        for (int j = 0; j < 5; j++) {

            if (matrix[i][j] == c) {
                return {i, j};
            }
        }
    }

    return {-1, -1};
}

string prepareText(string text) {

    string result;

    for (char c : text) {

        c = toupper((unsigned char)c);

        if (isalpha(c)) {

            if (c == 'J')
                c = 'I';

            result += c;
        }
    }

    for (int i = 0; i < result.length(); i += 2) {

        if (i + 1 < result.length() && result[i] == result[i + 1]) {
            result.insert(i + 1, "X");
        }
    }

    if (result.length() % 2 != 0) {
        result += "X";
    }

    return result;
}

string encryptPlayfair(string text) {

    text = prepareText(text);

    string result;

    for (int i = 0; i < text.length(); i += 2) {

        char a = text[i];
        char b = text[i + 1];

        pair<int, int> pos1 = findPosition(a);
        pair<int, int> pos2 = findPosition(b);

        if (pos1.first == pos2.first) {

            result += matrix[pos1.first][(pos1.second + 1) % 5];
            result += matrix[pos2.first][(pos2.second + 1) % 5];
        }
        else if (pos1.second == pos2.second) {

            result += matrix[(pos1.first + 1) % 5][pos1.second];
            result += matrix[(pos2.first + 1) % 5][pos2.second];
        }
        else {

            result += matrix[pos1.first][pos2.second];
            result += matrix[pos2.first][pos1.second];
        }
    }

    return result;
}

string decryptPlayfair(string text) {

    string result;

    for (int i = 0; i < text.length(); i += 2) {

        char a = text[i];
        char b = text[i + 1];

        pair<int, int> pos1 = findPosition(a);
        pair<int, int> pos2 = findPosition(b);

        if (pos1.first == pos2.first) {

            result += matrix[pos1.first][(pos1.second + 4) % 5];
            result += matrix[pos2.first][(pos2.second + 4) % 5];
        }
        else if (pos1.second == pos2.second) {

            result += matrix[(pos1.first + 4) % 5][pos1.second];
            result += matrix[(pos2.first + 4) % 5][pos2.second];
        }
        else {

            result += matrix[pos1.first][pos2.second];
            result += matrix[pos2.first][pos1.second];
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

    string text;
    string key;
    int choice;

    while (true) {

        cout << "\n========== PLAYFAIR CIPHER ==========\n";

        cout << "Current text:\n";

        if (text.empty())
            cout << "[EMPTY]\n";
        else
            cout << text << endl;

        cout << "\nMenu:\n";
        cout << "1. Enter text and key\n";
        cout << "2. Load text from file\n";
        cout << "3. Encrypt text\n";
        cout << "4. Decrypt text\n";
        cout << "5. Show matrix\n";
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

            cout << "Enter key: ";
            getline(cin, key);

            generateMatrix(key);

            break;
        }

        case 2: {

            string filename;

            cout << "Enter file name: ";
            getline(cin, filename);

            text = readFromFile(filename);

            cout << "Enter key: ";
            getline(cin, key);

            generateMatrix(key);

            cout << "File loaded successfully.\n";

            break;
        }

        case 3: {

            if (text.empty()) {

                cout << "Text is empty!\n";
                break;
            }

            string original = text;

            string encrypted = encryptPlayfair(text);

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

            string decrypted = decryptPlayfair(text);

            cout << "\nEncrypted text:\n";
            cout << encrypted << endl;

            cout << "\nDecrypted text:\n";
            cout << decrypted << endl;

            text = decrypted;

            break;
        }

        case 5: {

            printMatrix();

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