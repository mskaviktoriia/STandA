#include <iostream>
#include <array>
#include <algorithm>
using namespace std;

int main() {
    array<int, 10> grades;

    for (int i = 0; i < 10; i++) {
        cin >> grades[i];
    }

    double sum = 0;
    for (int x : grades) sum += x;
    double avg = sum / 10;

    int maxVal = *max_element(grades.begin(), grades.end());
    int minVal = *min_element(grades.begin(), grades.end());

    int countAbove = 0;
    for (int x : grades)
        if (x > avg) countAbove++;

    sort(grades.begin(), grades.end());

    cout << "Average: " << avg << endl;
    cout << "Max: " << maxVal << endl;
    cout << "Min: " << minVal << endl;
    cout << "Above average: " << countAbove << endl;

    cout << "Ascending: ";
    for (int x : grades) cout << x << " ";
    cout << endl;

    cout << "Descending: ";
    for (auto it = grades.rbegin(); it != grades.rend(); it++)
        cout << *it << " ";

    return 0;
}