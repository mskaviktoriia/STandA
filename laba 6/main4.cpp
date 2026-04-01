#include <iostream>
#include <string>
using namespace std;

struct Team {
    string name;
    string city;
    int points;
};

int main() {
    int n, threshold;
    cout << "How many teams? ";
    cin >> n;

    Team teams[100];
    for (int i = 0; i < n; i++) {
        cout << "Team name city points: ";
        cin >> teams[i].name >> teams[i].city >> teams[i].points;
    }

    cout << "Threshold: ";
    cin >> threshold;

    Team leader = teams[0];
    Team outsider = teams[0];

    string usedCities[100];
    int usedCount = 0;

    cout << "\nUnique city teams:" << endl;
    for (int i = 0; i < n; i++) {
        if (teams[i].points > leader.points) leader = teams[i];
        if (teams[i].points < outsider.points) outsider = teams[i];

        bool cityUsed = false;
        for (int j = 0; j < usedCount; j++) {
            if (usedCities[j] == teams[i].city) cityUsed = true;
        }
        if (!cityUsed) {
            usedCities[usedCount++] = teams[i].city;
            cout << teams[i].name << " " << teams[i].city << " " << teams[i].points << endl;
        }
    }

    cout << "\nHigh points teams (> " << threshold << "):" << endl;
    for (int i = 0; i < n; i++) {
        if (teams[i].points > threshold) {
            cout << teams[i].name << " " << teams[i].city << " " << teams[i].points << endl;
        }
    }

    cout << "\nLeader: " << leader.name << " " << leader.city << " " << leader.points << endl;
    cout << "Outsider: " << outsider.name << " " << outsider.city << " " << outsider.points << endl;

    return 0;
}