#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct Music {
    string carrier;
    string title;
    string artist;
    double duration;
    int tracks;
    double price;
};

int main() {
    stack<Music> s;
    stack<Music> cassetteStack;

    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        Music m;
        cin >> m.carrier >> m.title >> m.artist >> m.duration >> m.tracks >> m.price;
        s.push(m);
    }

    string targetArtist;
    cin >> targetArtist;

    double totalTime = 0;

    while (!s.empty()) {
        Music m = s.top();

        if (m.artist == targetArtist) {
            totalTime += m.duration;
        }

        if (m.carrier == "cassette") {
            cassetteStack.push(m);
        }

        s.pop();
    }

    double sum = 0;
    int count = 0;

    stack<Music> temp = cassetteStack;
    while (!temp.empty()) {
        sum += temp.top().price;
        count++;
        temp.pop();
    }

    cout << totalTime << endl;

    if (count > 0) {
        cout << sum / count << endl;
    } else {
        cout << "Empty stack" << endl;
    }

    return 0;
}