#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;

struct Lesson {
    int index;
    int start;
    int finish;
};

bool isCorrectTime(string time) {
    if (time.length() != 5 || time[2] != ':')
        return false;

    int hours = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(3, 2));

    return hours >= 0 && hours < 24 &&
           minutes >= 0 && minutes < 60;
}

int toMinutes(string time) {
    int hours = stoi(time.substr(0, 2));
    int minutes = stoi(time.substr(3, 2));

    return hours * 60 + minutes;
}

string toTime(int minutes) {
    int hours = minutes / 60;
    int mins = minutes % 60;

    return (hours < 10 ? "0" : "") + to_string(hours)
         + ":"
         + (mins < 10 ? "0" : "") + to_string(mins);
}

void inputLessons(vector<Lesson>& lessons) {
    int n;
    string startTime, finishTime;

    cout << "Enter number of lessons: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        while (true) {
            cout << "\nLesson " << i + 1 << endl;

            cout << "Start time (hh:mm): ";
            cin >> startTime;

            cout << "Finish time (hh:mm): ";
            cin >> finishTime;

            if (!isCorrectTime(startTime) ||
                !isCorrectTime(finishTime)) {

                cout << "Incorrect time format.\n";
                continue;
            }

            int start = toMinutes(startTime);
            int finish = toMinutes(finishTime);

            if (start >= finish) {
                cout << "Start must be earlier than finish.\n";
                continue;
            }

            lessons.push_back({i + 1, start, finish});
            break;
        }
    }
}

void printLessons(vector<Lesson> lessons, string title) {
    cout << "\n" << title << "\n";

    for (Lesson lesson : lessons) {
        cout << lesson.index
             << " | "
             << toTime(lesson.start)
             << " - "
             << toTime(lesson.finish)
             << endl;
    }
}

vector<Lesson> selectLessons(vector<Lesson> lessons) {
    vector<Lesson> selected;

    int lastFinish = -1;

    sort(lessons.begin(), lessons.end(),
        [](Lesson a, Lesson b) {
            return a.finish < b.finish;
        });

    printLessons(lessons,
        "LESSONS AFTER SORTING");

    for (Lesson lesson : lessons) {
        if (lesson.start >= lastFinish) {
            selected.push_back(lesson);
            lastFinish = lesson.finish;
        }
    }

    return selected;
}

int main() {
    vector<Lesson> lessons;

    inputLessons(lessons);

    vector<Lesson> selected =
        selectLessons(lessons);

    printLessons(selected,
        "SELECTED LESSONS");

    cout << "\nMaximum number of lessons: "
         << selected.size() << endl;

    return 0;
}