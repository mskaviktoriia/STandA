#include <iostream>
#include <string>
#include <cctype>

using namespace std;

string generateKey(string text, string key) {
    string newKey;
    int keyIndex = 0;

    for (char c : text) {
        if (isalpha((unsigned char)c)) {
            newKey += toupper(key[keyIndex % key.length()]);
            keyIndex++;
        } else {
            newKey += c;
        }
    }

    return newKey;
}

string encryptVigenere(string text, string key) {
    string result;
    key = generateKey(text, key);

    for (int i = 0; i < text.length(); i++) {

        if (isupper((unsigned char)text[i])) {
            result += char((text[i] - 'A' + key[i] - 'A') % 26 + 'A');
        }
        else if (islower((unsigned char)text[i])) {
            result += char((text[i] - 'a' + key[i] - 'A') % 26 + 'a');
        }
        else {
            result += text[i];
        }
    }

    return result;
}

string decryptVigenere(string text, string key) {
    string result;
    key = generateKey(text, key);

    for (int i = 0; i < text.length(); i++) {

        if (isupper((unsigned char)text[i])) {
            result += char((text[i] - 'A' - (key[i] - 'A') + 26) % 26 + 'A');
        }
        else if (islower((unsigned char)text[i])) {
            result += char((text[i] - 'a' - (key[i] - 'A') + 26) % 26 + 'a');
        }
        else {
            result += text[i];
        }
    }

    return result;
}

void printVigenereTable() {

    cout << "\n========== VIGENERE TABLE ==========\n\n";

    cout << "   ";
    for (char c = 'A'; c <= 'Z'; c++) {
        cout << c << " ";
    }

    cout << "\n";

    for (int i = 0; i < 26; i++) {

        cout << char('A' + i) << "  ";

        for (int j = 0; j < 26; j++) {
            cout << char((i + j) % 26 + 'A') << " ";
        }

        cout << "\n";
    }
}

int main() {

    string text;
    string key;
    int choice;

    while (true) {

        cout << "\n========== VIGENERE CIPHER ==========\n";

        cout << "1. Enter text\n";
        cout << "2. Encrypt text\n";
        cout << "3. Decrypt text\n";
        cout << "4. Show Vigenere table\n";
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

            cout << "Enter keyword: ";
            getline(cin, key);

            break;
        }

        case 2: {

            if (text.empty() || key.empty()) {
                cout << "Text or keyword is empty!\n";
                break;
            }

            string encrypted = encryptVigenere(text, key);

            cout << "\nEncrypted text:\n";
            cout << encrypted << endl;

            text = encrypted;

            break;
        }

        case 3: {

            if (text.empty() || key.empty()) {
                cout << "Text or keyword is empty!\n";
                break;
            }

            string decrypted = decryptVigenere(text, key);

            cout << "\nDecrypted text:\n";
            cout << decrypted << endl;

            text = decrypted;

            break;
        }

        case 4: {

            printVigenereTable();

            break;
        }

        default:
            cout << "Invalid option!\n";
        }
    }

    return 0;
}