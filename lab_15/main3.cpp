#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct TV {
    string brand;
    int screenSize;
    double price;
};

void sortTVs(vector<TV>& arr) {
    int n = arr.size();

    for (int i = 1; i < n; i++) {
        TV key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j].screenSize > key.screenSize) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }

    int i = 0;
    while (i < n) {
        int j = i;
        while (j < n - 1 && arr[j].screenSize == arr[j + 1].screenSize) {
            j++;
        }

        int g = i;
        while (g <= j) {
            if (g == i || arr[g].price <= arr[g - 1].price) {
                g++;
            } else {
                swap(arr[g], arr[g - 1]);
                g--;
            }
        }
        i = j + 1;
    }
}

int main() {
    int count;
    cout << "Enter number of TVs: ";
    cin >> count;

    vector<TV> tvList(count);

    for (int i = 0; i < count; i++) {
        cout << "\nTV #" << i + 1 << endl;
        cout << "Brand: ";
        cin >> tvList[i].brand;
        cout << "Screen size (32, 45, 60): ";
        cin >> tvList[i].screenSize;
        cout << "Price: ";
        cin >> tvList[i].price;
    }

    sortTVs(tvList);

    cout << "\nSorted TV List (Size ASC, Price DESC):" << endl;
    for (int i = 0; i < count; i++) {
        cout << tvList[i].screenSize << "\" " << tvList[i].brand 
             << " - " << tvList[i].price << " UAH" << endl;
    }

    return 0;
}