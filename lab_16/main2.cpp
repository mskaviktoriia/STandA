#include <iostream>
using namespace std;

struct Product {
    string name;
    int proteins, fats, carbs;
    int kcal;
};

int calcKcal(int p, int f, int c) {
    return 4 * p + 9 * f + 4 * c;
}

void input(Product a[], int n) {
    for (int i = 0; i < n; i++) {
        cout << "Name: ";
        cin >> a[i].name;

        cout << "P F C: ";
        cin >> a[i].proteins >> a[i].fats >> a[i].carbs;

        a[i].kcal = calcKcal(a[i].proteins, a[i].fats, a[i].carbs);
    }
}

void findMax(Product a[], int n) {
    int mx = a[0].kcal;

    for (int i = 1; i < n; i++)
        if (a[i].kcal > mx)
            mx = a[i].kcal;

    cout << "\nMax kcal = " << mx << "\nProducts:\n";

    for (int i = 0; i < n; i++) {
        if (a[i].kcal == mx)
            cout << " " << a[i].name << "\n";
    }
}

void rangeSearch(Product a[], int n, int A, int B) {
    bool found = false;

    cout << "\nProducts in range [" << A << "; " << B << "]:\n";

    for (int i = 0; i < n; i++) {
        if (a[i].kcal >= A && a[i].kcal <= B) {
            cout << " " << a[i].name
                 << " kcal=" << a[i].kcal << "\n";
            found = true;
        }
    }

    if (!found)
        cout << "No products in this range.\n";
}

int main() {
    int n;
    cout << "n = ";
    cin >> n;

    Product a[n];

    input(a, n);
    findMax(a, n);

    int A, B;
    cout << "Enter A B: ";
    cin >> A >> B;

    rangeSearch(a, n, A, B);

    return 0;
}