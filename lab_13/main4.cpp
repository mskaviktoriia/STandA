#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    multimap<char, string> words;
    string word;

    cout << "Enter words one by one. Enter 0 to finish:\n";

    while (true) {
        cin >> word;

        if (word == "0") {
            break;
        }

        if (!word.empty()) {
            char firstLetter = word[0];
            words.insert({firstLetter, word});
        }
    }

    cout << "\nGrouped words:\n";

    char currentLetter = '\0';

    for (auto it = words.begin(); it != words.end(); ) {
        currentLetter = it->first;
        cout << currentLetter << ": ";

        auto range = words.equal_range(currentLetter);

        for (auto wordIt = range.first; wordIt != range.second; ++wordIt) {
            cout << wordIt->second << " ";
        }

        cout << endl;
        it = range.second;
    }

    return 0;
}
