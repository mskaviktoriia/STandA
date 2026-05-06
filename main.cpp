#include <iostream>
#include <string>
#include <vector>
using namespace std;

struct Product {
    string name;
    double price;
    double nutrients[3];
    double calories;
};

double calculateCalories(Product p) {
    return 4 * p.nutrients[0] + 9 * p.nutrients[1] + 4 * p.nutrients[2];
}

void selectionSort(vector<Product>& v) {
    int n = v.size();
    for (int i = 0; i < n - 1; i++) {
        int maxIdx = i;
        for (int j = i + 1; j < n; j++) {
            if (v[j].calories > v[maxIdx].calories)
                maxIdx = j;
        }
        Product temp = v[i];
        v[i] = v[maxIdx];
        v[maxIdx] = temp;
    }
}

void gnomeSort(vector<Product>& v) {
    int i = 0;
    int n = v.size();

    while (i < n) {
        if (i == 0 || v[i].price >= v[i - 1].price)
            i++;
        else {
            Product temp = v[i];
            v[i] = v[i - 1];
            v[i - 1] = temp;
            i--;
        }
    }
}

void printProducts(const vector<Product>& v) {
    for (auto p : v) {
        cout << "Name: " << p.name << ", Price: " << p.price << endl;
        cout << "Proteins: " << p.nutrients[0]
             << ", Fats: " << p.nutrients[1]
             << ", Carbs: " << p.nutrients[2] << endl;
        cout << "Calories: " << p.calories << endl;
    }
    cout << endl;
}

int main() {
    int n;
    cin >> n;

    vector<Product> products(n);

    for (int i = 0; i < n; i++) {
        cin >> products[i].name;
        cin >> products[i].price;
        cin >> products[i].nutrients[0];
        cin >> products[i].nutrients[1];
        cin >> products[i].nutrients[2];

        products[i].calories = calculateCalories(products[i]);
    }

    vector<Product> sortedByCalories = products;
    vector<Product> sortedByPrice = products;

    selectionSort(sortedByCalories);
    gnomeSort(sortedByPrice);

    double targetPrice;
    cin >> targetPrice;

    cout << "Sorting by descending calories:\n";
    printProducts(sortedByCalories);

    cout << "Sorting by ascending price:\n";
    printProducts(sortedByPrice);

    cout << "Search results:\n";

    bool found = false;
    for (auto p : products) {
        if (p.price == targetPrice) {
            cout << "Name: " << p.name << ", Price: " << p.price << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "No products found with this price.\n";
    }

    return 0;
}