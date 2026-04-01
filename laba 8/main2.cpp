#include <iostream>
#include <string>
using namespace std;

struct Course {
    string name;
    int hours;
    int students;
    Course* prev;
    Course* next;
};

void printForward(Course* head) {
    Course* curr = head;
    while (curr) {
        cout << curr->name << " " << curr->hours << " " << curr->students << endl;
        curr = curr->next;
    }
}

void printBackward(Course* tail) {
    Course* curr = tail;
    while (curr) {
        cout << curr->name << " " << curr->hours << " " << curr->students << endl;
        curr = curr->prev;
    }
}

void freeList(Course* head) {
    Course* curr = head;
    while (curr) {
        Course* temp = curr;
        curr = curr->next;
        delete temp;
    }
}

int main() {
    int n;
    cin >> n;
    Course* head = nullptr;
    Course* tail = nullptr;

    for (int i = 0; i < n; i++) {
        Course* c = new Course;
        cin >> c->name >> c->hours >> c->students;
        c->prev = tail;
        c->next = nullptr;
        if (tail) tail->next = c;
        else head = c;
        tail = c;
    }

    double sum = 0;
    Course* curr = head;
    while (curr) {
        sum += curr->students;
        curr = curr->next;
    }
    double avg = sum / n;

    Course* highHead = nullptr;
    Course* highTail = nullptr;
    Course* lowHead = nullptr;
    Course* lowTail = nullptr;

    curr = head;
    while (curr) {
        Course* c = new Course(*curr);
        c->prev = nullptr;
        c->next = nullptr;
        if (curr->students > avg) {
            c->prev = highTail;
            if (highTail) highTail->next = c;
            else highHead = c;
            highTail = c;
        } else {
            c->prev = lowTail;
            if (lowTail) lowTail->next = c;
            else lowHead = c;
            lowTail = c;
        }
        curr = curr->next;
    }

    cout << "High students list forward:" << endl;
    printForward(highHead);
    cout << "High students list backward:" << endl;
    printBackward(highTail);

    cout << "Low students list forward:" << endl;
    printForward(lowHead);
    cout << "Low students list backward:" << endl;
    printBackward(lowTail);

    freeList(highHead);
    freeList(lowHead);
    freeList(head);

    return 0;
}