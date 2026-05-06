#include <iostream>
#include <set>
#include <unordered_set>
#include <vector>
#include <string>
#include <chrono>

using namespace std;
using namespace chrono;

int main() {
    int N, K;
    cin >> N;

    vector<string> words(N);

    for (int i = 0; i < N; i++) {
        cin >> words[i];
    }

    set<string> s;
    unordered_set<string> us;

    auto start1 = high_resolution_clock::now();
    for (const auto& w : words) {
        s.insert(w);
    }
    auto end1 = high_resolution_clock::now();

    auto start2 = high_resolution_clock::now();
    for (const auto& w : words) {
        us.insert(w);
    }
    auto end2 = high_resolution_clock::now();

    cin >> K;
    vector<string> queries(K);

    for (int i = 0; i < K; i++) {
        cin >> queries[i];
    }

    auto start3 = high_resolution_clock::now();
    int found_set = 0;
    for (const auto& q : queries) {
        if (s.find(q) != s.end()) found_set++;
    }
    auto end3 = high_resolution_clock::now();

    auto start4 = high_resolution_clock::now();
    int found_unordered = 0;
    for (const auto& q : queries) {
        if (us.find(q) != us.end()) found_unordered++;
    }
    auto end4 = high_resolution_clock::now();

    auto time_set_insert = duration_cast<nanoseconds>(end1 - start1).count();
    auto time_unordered_insert = duration_cast<nanoseconds>(end2 - start2).count();
    auto time_set_search = duration_cast<nanoseconds>(end3 - start3).count();
    auto time_unordered_search = duration_cast<nanoseconds>(end4 - start4).count();

    cout << "set insert time: " << time_set_insert << " ns\n";
    cout << "unordered_set insert time: " << time_unordered_insert << " ns\n";
    cout << "set search time: " << time_set_search << " ns\n";
    cout << "unordered_set search time: " << time_unordered_search << " ns\n";

    cout << "Found in set: " << found_set << "\n";
    cout << "Found in unordered_set: " << found_unordered << "\n";

    return 0;
}