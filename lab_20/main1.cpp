#include <iostream>
#include <iomanip>
using namespace std;

const int SIZE = 4;

string products[SIZE] = {"Meat", "Flour", "Milk powder", "Sugar"};

void showTable(double volume[], double calories[]) {
    cout << "TABLE VALUES\n\n";
    cout << "According to the table, product data is:\n\n";

    cout << left << setw(15) << "Product"
         << setw(18) << "Volume"
         << "Calories\n";

    for (int i = 0; i < SIZE; i++) {
        cout << left << setw(15) << products[i]
             << setw(18) << volume[i]
             << calories[i] << endl;
    }
}

void inputValues(double volume[], double calories[]) {
    char choice;

    showTable(volume, calories);

    cout << "\nDo you want to change these values? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        cout << "\nEnter your desired values:\n\n";

        for (int i = 0; i < SIZE; i++) {
            cout << products[i] << endl;

            cout << "Volume (dm3/kg): ";
            cin >> volume[i];

            cout << "Calories (kcal/kg): ";
            cin >> calories[i];

            cout << endl;
        }
    }
}

void inputProportions(double k[]) {
    char choice;

    cout << "\nDOCTOR RECOMMENDATIONS\n\n";
    cout << "Recommended proportions are:\n";
    cout << "Meat : Flour : Milk powder : Sugar = 16 : 8 : 8 : 1\n\n";

    k[0] = 16;
    k[1] = 8;
    k[2] = 8;
    k[3] = 1;

    cout << "Enter these proportions, or change them if you want.\n";
    cout << "Do you want to change proportions? (y/n): ";
    cin >> choice;

    if (choice == 'y' || choice == 'Y') {
        cout << "\nEnter your proportions:\n";

        for (int i = 0; i < SIZE; i++) {
            cout << products[i] << ": ";
            cin >> k[i];
        }
    }
}

double findT(double maxVolume, double maxWeight,
             double k[], double volume[]) {
    double weightPart = k[0] + k[1] + k[2] + k[3];

    double volumePart = 0;
    for (int i = 0; i < SIZE; i++)
        volumePart += k[i] * volume[i];

    return min(maxWeight / weightPart, maxVolume / volumePart);
}

double scalar(double a[], double b[]) {
    double s = 0;

    for (int i = 0; i < SIZE; i++)
        s += a[i] * b[i];

    return s;
}

void output(double x[], double volume[], double calories[]) {
    cout << fixed << setprecision(2);

    cout << "\nOPTIMAL SET OF PRODUCTS\n\n";

    for (int i = 0; i < SIZE; i++)
        cout << products[i] << ": " << x[i] << " kg\n";

    cout << "\nTotal weight: " << x[0] + x[1] + x[2] + x[3] << " kg\n";
    cout << "Total volume: " << scalar(x, volume) << " dm3\n";
    cout << "Total calories: " << scalar(x, calories) << " kcal\n";
}

int main() {
    double volume[SIZE] = {1, 1.5, 2, 1};
    double calories[SIZE] = {1500, 5000, 5000, 4000};
    double k[SIZE], x[SIZE];
    double maxVolume, maxWeight;

    inputValues(volume, calories);
    inputProportions(k);

    cout << "\nEnter maximum backpack volume(45kg recommended): ";
    cin >> maxVolume;

    cout << "Enter maximum backpack weight(35kg recommended): ";
    cin >> maxWeight;

    double t = findT(maxVolume, maxWeight, k, volume);

    for (int i = 0; i < SIZE; i++)
        x[i] = k[i] * t;

    output(x, volume, calories);

    return 0;
}
