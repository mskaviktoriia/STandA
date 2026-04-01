#include <iostream>
#include <stack>
#include <cstdlib>
#include <ctime>

using namespace std;

int main() {
    srand(time(0));

    stack<double> s;
    stack<double> newStack;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        double num = -6 + rand() % 18;
        s.push(num);
    }

    double k;
    cin >> k;

    while (!s.empty()) {
        if (s.top() >= k) {
            newStack.push(s.top());
        }
        s.pop();
    }

    double sum = 0;
    int count = 0;

    stack<double> temp = newStack;
    while (!temp.empty()) {
        sum += temp.top();
        count++;
        temp.pop();
    }

    if (count > 0) {
        cout << sum / count;
    } else {
        cout << "Empty stack";
    }

    return 0;
}