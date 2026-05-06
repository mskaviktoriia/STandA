#include <iostream>
#include <deque>
using namespace std;

int main() {
    deque<string> q;
    int c;
    string s;

    while (true) {
        cout << "\n1-normal 2-urgent 3-process 4-show 5-size 0-exit\n";
        cin >> c;

        if (c == 1) {
            cin >> s;
            q.push_back(s);
        }
        else if (c == 2) {
            cin >> s;
            q.push_front(s);
        }
        else if (c == 3) {
            if (!q.empty()) {
                cout << "Processing: " << q.front() << endl;
                q.pop_front();
            }
        }
        else if (c == 4) {
            for (auto x : q)
                cout << x << " ";
            cout << endl;
        }
        else if (c == 5) {
            cout << q.size() << endl;
        }
        else break;
    }
}