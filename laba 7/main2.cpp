#include <iostream>
#include <string>
using namespace std;

struct Employee {
    string surname;
    string department;
    int experience;
    double salary;
    Employee* prev;
    Employee* next;
};

void printForward(Employee* head) {
    Employee* curr = head;
    while (curr) {
        cout << curr->surname << " " << curr->department << " " << curr->experience << " " << curr->salary << endl;
        curr = curr->next;
    }
}

void printBackward(Employee* tail) {
    Employee* curr = tail;
    while (curr) {
        cout << curr->surname << " " << curr->department << " " << curr->experience << " " << curr->salary << endl;
        curr = curr->prev;
    }
}

void freeList(Employee* head) {
    Employee* curr = head;
    while (curr) {
        Employee* temp = curr;
        curr = curr->next;
        delete temp;
    }
}

int main() {
    int n;
    cin >> n;
    Employee* head = nullptr;
    Employee* tail = nullptr;

    for (int i = 0; i < n; i++) {
        Employee* emp = new Employee;
        cin >> emp->surname >> emp->department >> emp->experience >> emp->salary;
        emp->prev = tail;
        emp->next = nullptr;
        if (tail) tail->next = emp;
        else head = emp;
        tail = emp;
    }

    double sum = 0;
    Employee* curr = head;
    while (curr) {
        sum += curr->salary;
        curr = curr->next;
    }
    double avg = sum / n;

    Employee* highHead = nullptr;
    Employee* highTail = nullptr;
    Employee* lowHead = nullptr;
    Employee* lowTail = nullptr;

    curr = head;
    while (curr) {
        if (curr->salary > avg) {
            Employee* emp = new Employee(*curr);
            emp->prev = highTail;
            emp->next = nullptr;
            if (highTail) highTail->next = emp;
            else highHead = emp;
            highTail = emp;
        } else {
            Employee* emp = new Employee(*curr);
            emp->prev = lowTail;
            emp->next = nullptr;
            if (lowTail) lowTail->next = emp;
            else lowHead = emp;
            lowTail = emp;
        }
        curr = curr->next;
    }

    Employee* newEmp = new Employee{"New", "Dept", 1, avg + 100, nullptr, nullptr};
    newEmp->prev = highTail;
    newEmp->next = nullptr;
    if (highTail) highTail->next = newEmp;
    else highHead = newEmp;
    highTail = newEmp;

    cout << "High salary list forward:" << endl;
    printForward(highHead);
    cout << "High salary list backward:" << endl;
    printBackward(highTail);

    cout << "Low salary list forward:" << endl;
    printForward(lowHead);
    cout << "Low salary list backward:" << endl;
    printBackward(lowTail);

    freeList(highHead);
    freeList(lowHead);
    freeList(head);

    return 0;
}