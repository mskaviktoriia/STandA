#include <iostream>
#include <stack>
using namespace std;

int main() {
    stack<int> testStack;
    int n, grade;

    cin >> n;

    for (int i = 0; i < n; i++) {
        cin >> grade;
        testStack.push(grade);
    }

    stack<int> tempStack = testStack;
    while (!tempStack.empty()) {
        cout << tempStack.top() << " ";
        tempStack.pop();
    }
    cout << endl;

    double sum = 0;
    int count = 0;
    tempStack = testStack;
    while (!tempStack.empty()) {
        sum += tempStack.top();
        tempStack.pop();
        count++;
    }
    double average = (count > 0) ? (sum / count) : 0;
    cout << average << endl;

    while (!testStack.empty()) {
        testStack.pop();
    }

    return 0;
}