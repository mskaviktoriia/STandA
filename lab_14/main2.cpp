#include <iostream>
#include <map>
using namespace std;

int main() {
    multimap<string, string> pb;
    int c;
    string name, num;

    while (true) {
        cout << "\n1-add 2-show 3-delete number 4-delete all 5-show all 0-exit\n";
        cin >> c;

        if (c == 1) {
            cin >> name >> num;
            pb.insert({name, num});
        }
        else if (c == 2) {
            cin >> name;
            auto r = pb.equal_range(name);
            for (auto it = r.first; it != r.second; it++)
                cout << it->second << " ";
            cout << endl;
        }
        else if (c == 3) {
            cin >> name >> num;
            auto r = pb.equal_range(name);
            for (auto it = r.first; it != r.second; ) {
                if (it->second == num)
                    it = pb.erase(it);
                else it++;
            }
        }
        else if (c == 4) {
            cin >> name;
            pb.erase(name);
        }
        else if (c == 5) {
            for (auto x : pb)
                cout << x.first << " " << x.second << endl;
        }
        else break;
    }
}