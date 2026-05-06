#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Time {
    int hours;
    int minutes;
};

struct Train {
    int number;
    string destination;
    double distance;
    Time departure;
    Time arrival;
    int travelTime;
};

int main() {
    int n;
    cout << "Enter number of trains: ";
    cin >> n;

    vector<Train> trains(n);

    for (int i = 0; i < n; i++) {
        cout << "Train #" << i + 1 << endl;
        cout << "Number: "; cin >> trains[i].number;
        cout << "Destination: "; cin >> trains[i].destination;
        cout << "Travel time (minutes): "; cin >> trains[i].travelTime;
    }

    int maxIdx = 0;
    for (int i = 1; i < n; i++) {
        if (trains[i].travelTime > trains[maxIdx].travelTime) {
            maxIdx = i;
        }
    }

    cout << "\n--- Part A: Longest trip ---" << endl;
    cout << "Number: " << trains[maxIdx].number << endl;
    cout << "Destination: " << trains[maxIdx].destination << endl;

    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (trains[j].travelTime < trains[min_idx].travelTime) {
                min_idx = j;
            }
        }
        swap(trains[i], trains[min_idx]);
    }

    cout << "\n--- Part B: Results after Selection Sort ---" << endl;
    cout << "Train with max time: " << endl;
    cout << "Number: " << trains[n-1].number << endl;
    cout << "Destination: " << trains[n-1].destination << endl;
    cout << "Time: " << trains[n-1].travelTime << " min" << endl;

    return 0;
}