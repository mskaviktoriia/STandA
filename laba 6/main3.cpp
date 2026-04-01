#include <iostream>
#include <queue>
#include <cmath>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    queue<int> q;
    queue<int> newQ;

    srand(time(0));

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        int num = rand() % 100 + 1;
        q.push(num);
    }

    while (!q.empty()) {
        int x = q.front();
        q.pop();

        if (x % 2 == 0) {
            newQ.push(x);
            newQ.push(100);
        }
    }

    double product = 1.0;
    int count = 0;

    while (!newQ.empty()) {
        int x = newQ.front();
        newQ.pop();

        product *= x;
        count++;
    }

    if (count > 0) {
        double geom = pow(product, 1.0 / count);
        cout << geom;
    } else {
        cout << 0;
    }

    return 0;
}