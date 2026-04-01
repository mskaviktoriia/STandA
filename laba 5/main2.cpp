#include <iostream>
#include <string>
using namespace std;

struct Node {
    string city;
    double distance;
    Node* next;
};

void addToEnd(Node*& head, string city, double distance) {
    Node* newNode = new Node{city, distance, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

void printTwoFarthest(Node* head) {
    if (!head || !head->next) return;

    Node* first = head;
    Node* second = head;

    while (head) {
        if (head->distance > first->distance) {
            second = first;
            first = head;
        } else if (head->distance > second->distance && head != first) {
            second = head;
        }
        head = head->next;
    }

    cout << first->city << endl;
    cout << second->city << endl;
}

void freeList(Node*& head) {
    while (head) {
        Node* temp = head;
        head = head->next;
        delete temp;
    }
}

int main() {
    Node* head = nullptr;
    int n;
    cin >> n;

    for (int i = 0; i < n; i++) {
        string city;
        double distance;
        cin >> city >> distance;
        addToEnd(head, city, distance);
    }

    printTwoFarthest(head);

    addToEnd(head, "Paris", 2020);

    freeList(head);

    return 0;
}