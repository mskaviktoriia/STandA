#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, int> wordCount;
    string word;

    cout << "Enter text (enter '0' to finish):" << endl;

    while (cin >> word) {
        if (word == "0") {
            break;
        }
        wordCount[word]++;
    }

    cout << "\nWord count results:" << endl;
    for (const auto& pair : wordCount) {
        cout << pair.first << ": " << pair.second << endl;
    }

    return 0;
}