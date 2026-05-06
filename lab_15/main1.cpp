#include <iostream>
#include <vector>
#include <ctime>
#include <string>

using namespace std;

void bubbleSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

void selectionSort(vector<int>& arr) {
    int n = arr.size();
    for (int i = 0; i < n - 1; i++) {
        int min_idx = i;
        for (int j = i + 1; j < n; j++) {
            if (arr[j] < arr[min_idx]) min_idx = j;
        }
        swap(arr[min_idx], arr[i]);
    }
}

void gnomeSort(vector<int>& arr) {
    int n = arr.size();
    int i = 0;
    while (i < n) {
        if (i == 0 || arr[i] >= arr[i - 1]) i++;
        else {
            swap(arr[i], arr[i - 1]);
            i--;
        }
    }
}

int main() {
    int sizes[] = {1000, 10000, 100000};

    for (int n : sizes) {
        cout << "--- Size n = " << n << " ---" << endl;

        double times[4];
        string names[] = {"Bubble", "Insertion", "Selection", "Gnome"};

        for (int i = 0; i < 4; i++) {
            vector<int> arr(n);
            for (int k = 0; k < n; k++) arr[k] = rand() % 100000;

            clock_t start = clock();
            if (i == 0) bubbleSort(arr);
            else if (i == 1) insertionSort(arr);
            else if (i == 2) selectionSort(arr);
            else if (i == 3) gnomeSort(arr);
            clock_t end = clock();

            times[i] = (double)(end - start) / CLOCKS_PER_SEC;
            cout << names[i] << ": " << times[i] << "s" << endl;
        }

        int best = 0, worst = 0;
        for (int i = 1; i < 4; i++) {
            if (times[i] < times[best]) best = i;
            if (times[i] > times[worst]) worst = i;
        }

        cout << "Best: " << names[best] << endl;
        cout << "Worst: " << names[worst] << endl << endl;
    }

    return 0;
}