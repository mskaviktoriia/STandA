#include <iostream>
#include <fstream>
#include <string>
#include <map>
#include <windows.h>

using namespace std;

map<char, string> morseCode = {
    {'A', ".-"}, {'B', "-..."}, {'C', "-.-."},
    {'D', "-.."}, {'E', "."}, {'F', "..-."},
    {'G', "--."}, {'H', "...."}, {'I', ".."},
    {'J', ".---"}, {'K', "-.-"}, {'L', ".-.."},
    {'M', "--"}, {'N', "-."}, {'O', "---"},
    {'P', ".--."}, {'Q', "--.-"}, {'R', ".-."},
    {'S', "..."}, {'T', "-"}, {'U', "..-"},
    {'V', "...-"}, {'W', ".--"}, {'X', "-..-"},
    {'Y', "-.--"}, {'Z', "--.."},
    {'0', "-----"}, {'1', ".----"}, {'2', "..---"},
    {'3', "...--"}, {'4', "....-"}, {'5', "....."},
    {'6', "-...."}, {'7', "--..."}, {'8', "---.."},
    {'9', "----."},
    {' ', "/"}
};

map<string, char> reverseMorse;

void createReverseMap() {
    for (auto pair : morseCode) {
        reverseMorse[pair.second] = pair.first;
    }
}

string encryptMorse(string text) {

    string result;

    for (char c : text) {

        c = toupper((unsigned char)c);

        if (morseCode.count(c)) {
            result += morseCode[c] + " ";
        }
    }

    return result;
}

string decryptMorse(string code) {

    string result;
    string current;

    for (char c : code) {

        if (c != ' ') {
            current += c;
        }
        else {
            if (!current.empty() && reverseMorse.count(current)) {
                result += reverseMorse[current];
            }
            current.clear();
        }
    }

    if (!current.empty() && reverseMorse.count(current)) {
        result += reverseMorse[current];
    }

    return result;
}

void playMorseSound(string code) {

    cout << "\nPlaying Morse code...\n";

    for (char c : code) {

        if (c == '.') {

            Beep(1000, 200);
            Sleep(250);
        }
        else if (c == '-') {

            Beep(1000, 800);
            Sleep(250);
        }
        else if (c == '/') {

            Sleep(1600);
        }
        else {

            Sleep(100);
        }
    }
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

void saveToFile(const string& filename, const string& text) {

    ofstream file(filename);

    if (!file) {
        cout << "Cannot create file!\n";
        return;
    }

    file << text;

    cout << "Saved to file: " << filename << endl;
}

int main() {

    createReverseMap();

    string text;
    int choice;

    while (true) {

        cout << "\n========== MORSE CODE ==========\n";

        cout << "Current text:\n";

        if (text.empty())
            cout << "[EMPTY]\n";
        else
            cout << text << endl;

        cout << "\nMenu:\n";
        cout << "1. Enter text\n";
        cout << "2. Load text from file\n";
        cout << "3. Encrypt to Morse code\n";
        cout << "4. Decrypt Morse code\n";
        cout << "5. Save text to file\n";
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

            if (text.empty())
                cout << "Error: file not found or empty.\n";
            else
                cout << "File loaded successfully.\n";

            break;
        }

        case 3: {

            if (text.empty()) {
                cout << "Text is empty!\n";
                break;
            }

            string original = text;
            string encrypted = encryptMorse(text);

            cout << "\nOriginal text:\n";
            cout << original << endl;

            cout << "\nMorse code:\n";
            cout << encrypted << endl;

            playMorseSound(encrypted);

            text = encrypted;

            break;
        }

        case 4: {

            if (text.empty()) {
                cout << "Text is empty!\n";
                break;
            }

            string encrypted = text;
            string decrypted = decryptMorse(text);

            cout << "\nMorse code:\n";
            cout << encrypted << endl;

            cout << "\nDecrypted text:\n";
            cout << decrypted << endl;

            text = decrypted;

            break;
        }

        case 5: {

            string filename;

            cout << "Enter file name: ";
            getline(cin, filename);

            saveToFile(filename, text);

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