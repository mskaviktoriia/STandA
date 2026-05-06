#include <iostream>
#include <map>
#include <unordered_map>
#include <chrono>
using namespace std;
using namespace chrono;

int main() {
    int N, M, K;

    cout << "Enter N (number of elements to insert): ";
    cin >> N;

    cout << "Enter M (number of elements to delete): ";
    cin >> M;

    cout << "Enter K (number of elements to search): ";
    cin >> K;

    map<int, int> orderedMap;
    unordered_map<int, int> unorderedMap;

    auto start = high_resolution_clock::now();

    for (int i = 0; i < N; i++) {
        orderedMap[i] = i;
    }

    auto end = high_resolution_clock::now();
    auto mapInsertTime = duration_cast<microseconds>(end - start).count();

    start = high_resolution_clock::now();

    for (int i = 0; i < N; i++) {
        unorderedMap[i] = i;
    }

    end = high_resolution_clock::now();
    auto unorderedInsertTime = duration_cast<microseconds>(end - start).count();

    start = high_resolution_clock::now();

    for (int i = 0; i < M && i < N; i++) {
        orderedMap.erase(i);
    }

    end = high_resolution_clock::now();
    auto mapDeleteTime = duration_cast<microseconds>(end - start).count();

    start = high_resolution_clock::now();

    for (int i = 0; i < M && i < N; i++) {
        unorderedMap.erase(i);
    }

    end = high_resolution_clock::now();
    auto unorderedDeleteTime = duration_cast<microseconds>(end - start).count();

    int foundMap = 0;
    start = high_resolution_clock::now();

    for (int i = 0; i < K; i++) {
        if (orderedMap.find(i) != orderedMap.end()) {
            foundMap++;
        }
    }

    end = high_resolution_clock::now();
    auto mapSearchTime = duration_cast<microseconds>(end - start).count();

    int foundUnorderedMap = 0;
    start = high_resolution_clock::now();

    for (int i = 0; i < K; i++) {
        if (unorderedMap.find(i) != unorderedMap.end()) {
            foundUnorderedMap++;
        }
    }

    end = high_resolution_clock::now();
    auto unorderedSearchTime = duration_cast<microseconds>(end - start).count();

    cout << "\nResults in microseconds:\n";

    cout << "\nstd::map:\n";
    cout << "Insert time: " << mapInsertTime << endl;
    cout << "Delete time: " << mapDeleteTime << endl;
    cout << "Search time: " << mapSearchTime << endl;
    cout << "Found elements: " << foundMap << endl;

    cout << "\nstd::unordered_map:\n";
    cout << "Insert time: " << unorderedInsertTime << endl;
    cout << "Delete time: " << unorderedDeleteTime << endl;
    cout << "Search time: " << unorderedSearchTime << endl;
    cout << "Found elements: " << foundUnorderedMap << endl;

    return 0;
}
