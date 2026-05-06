#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Student {
    string surname;
    int exam[3];
    double avg;
};

double calcAvg(int a, int b, int c) {
    return (a + b + c) / 3.0;
}

void findMaxStudents(Student a[], int n) {
    double mx = a[0].avg;

    for (int i = 1; i < n; i++)
        if (a[i].avg > mx)
            mx = a[i].avg;

    cout << "Max average = " << mx << "\nStudents:\n";

    int count = 0;
    for (int i = 0; i < n; i++) {
        if (a[i].avg == mx) {
            cout << i << " " << a[i].surname << "\n";
            count++;
        }
    }

    cout << "Count = " << count << "\n";
}

void binarySearchAvg(Student a[], int n, double key) {
    int l = 0, r = n - 1;
    bool found = false;

    while (l <= r) {
        int m = (l + r) / 2;

        if (a[m].avg == key) {
            found = true;

            int i = m;
            while (i >= 0 && a[i].avg == key) i--;
            i++;

            cout << "Students with avg " << key << ":\n";
            while (i < n && a[i].avg == key) {
                cout << i << " " << a[i].surname << "\n";
                i++;
            }
            break;
        }

        if (a[m].avg < key) l = m + 1;
        else r = m - 1;
    }

    if (!found)
        cout << "No students with such average.\n";
}

int main() {
    int n;
    cout << "n = ";
    cin >> n;

    Student a[n];

    for (int i = 0; i < n; i++) {
        cout << "Surname: ";
        cin >> a[i].surname;

        cout << "3 exams: ";
        cin >> a[i].exam[0] >> a[i].exam[1] >> a[i].exam[2];

        a[i].avg = calcAvg(a[i].exam[0], a[i].exam[1], a[i].exam[2]);
    }

    findMaxStudents(a, n);

    sort(a, a + n, [](Student x, Student y) {
        return x.avg < y.avg;
    });

    double key;
    cout << "Search avg: ";
    cin >> key;

    binarySearchAvg(a, n, key);

    return 0;
}