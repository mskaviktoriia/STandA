#include <iostream>
#include <fstream>
#include <string>
#include <cctype>

using namespace std;

string encrypt(const string& text, int shift) {
    string result = text;
    shift %= 26;

    for (char& c : result) {
        if (isupper((unsigned char)c)) {
            c = char((c - 'A' + shift + 26) % 26 + 'A');
        } else if (islower((unsigned char)c)) {
            c = char((c - 'a' + shift + 26) % 26 + 'a');
        }
    }

    return result;
}

int frequencyAnalysis(const string& text) {
    int freq[26] = {0};

    for (char c : text) {
        if (isalpha((unsigned char)c)) {
            c = char(toupper((unsigned char)c));
            freq[c - 'A']++;
        }
    }

    int maxIndex = 0;
    for (int i = 1; i < 26; i++) {
        if (freq[i] > freq[maxIndex]) {
            maxIndex = i;
        }
    }

    int shift = maxIndex - ('E' - 'A');
    if (shift < 0) shift += 26;

    return shift;
}

string readFromFile(const string& filename) {
    ifstream file(filename);
    if (!file) return "";

    string text, line;
    while (getline(file, line)) {
        text += line + '\n';
    }

    return text;
}

void saveToFile(const string& filename, const string& text) {
    ofstream file(filename);

    if (!file) {
        cout << "Error: cannot create file!\n";
        return;
    }

    file << text;
    cout << "Text saved successfully to " << filename << "\n";
}

int main() {
    string text;
    int choice;

    while (true) {
        cout << "\n========== SIMPLE SUBSTITUTION CIPHER ==========\n";
        cout << "Current text:\n";
        cout << (text.empty() ? "[EMPTY]\n" : text + "\n");

        cout << "\nMenu:\n";
        cout << "1. Enter text\n";
        cout << "2. Load from file\n";
        cout << "3. Encrypt text\n";
        cout << "4. Decrypt with shift\n";
        cout << "5. Auto decrypt (frequency analysis)\n";
        cout << "6. Save to file\n";
        cout << "7. Clear text\n";
        cout << "0. Exit\n";

        cout << "\nChoose option: ";
        cin >> choice;

        if (choice == 0) {
            cout << "Program ended.\n";
            break;
        }

        switch (choice) {

        case 1: {
            cin.ignore();
            cout << "Enter text: ";
            getline(cin, text);
            break;
        }

        case 2: {
            cin.ignore();
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

            int shift;
            cout << "Enter shift: ";
            cin >> shift;

            text = encrypt(text, shift);
            cout << "Text encrypted.\n";
            break;
        }

        case 4: {
            if (text.empty()) {
                cout << "Text is empty!\n";
                break;
            }

            int shift;
            cout << "Enter shift: ";
            cin >> shift;

            text = encrypt(text, -shift);
            cout << "Text decrypted.\n";
            break;
        }

        case 5: {
    if (text.empty()) {
        cout << "Text is empty!\n";
        break;
    }

    int shift = frequencyAnalysis(text);

    string decrypted = encrypt(text, -shift);

    cout << "\nDetected shift: " << shift << endl;
    cout << "Decrypted text:\n";
    cout << decrypted << endl;

    cout << "\nIs the result correct? (YES/NO): ";
    string ans;
    cin >> ans;

    if (ans == "YES" || ans == "yes" || ans == "Yes") {
        text = decrypted;
        cout << "Confirmed. Text updated.\n";
    } else {
        cout << "Not confirmed. Original text preserved.\n";
    }

    break;
}

        case 6: {
            cin.ignore();
            string filename;
            cout << "Enter file name: ";
            getline(cin, filename);

            saveToFile(filename, text);
            break;
        }

        case 7: {
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