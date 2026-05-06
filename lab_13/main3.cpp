#include <iostream>
#include <map>
#include <string>
using namespace std;

void changeGrade(map<string, int>& students, const string& name, int newGrade) {
    students[name] = newGrade;
}

int main() {
    map<string, int> students = {
        {"Anna", 90},
        {"Ivan", 75},
        {"Maria", 88}
    };

    string name;
    int grade;

    cout << "Enter student name: ";
    cin >> name;

    cout << "Enter new grade: ";
    cin >> grade;

    changeGrade(students, name, grade);

    cout << "\nStudents list:\n";
    for (const auto& student : students) {
        cout << student.first << ": " << student.second << endl;
    }

    return 0;
}
