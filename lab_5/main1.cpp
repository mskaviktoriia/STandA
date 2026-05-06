#include <iostream>
using namespace std;

struct Node {
    int data;
    Node* next;
};

void addToStart(Node*& head, int value) {
    Node* newNode = new Node{value, head};
    head = newNode;
}

void addToEnd(Node*& head, int value) {
    Node* newNode = new Node{value, nullptr};
    if (!head) {
        head = newNode;
        return;
    }
    Node* temp = head;
    while (temp->next)
        temp = temp->next;
    temp->next = newNode;
}

void addToMiddle(Node* head, int value) {
    if (!head || !head->next) return;
    Node* temp = head->next;
    Node* newNode = new Node{value, temp->next};
    temp->next = newNode;
}

void printList(Node* head) {
    while (head) {
        cout << head->data << " ";
        head = head->next;
    }
    cout << endl;
}

double average(Node* head) {
    int sum = 0, count = 0;
    while (head) {
        sum += head->data;
        count++;
        head = head->next;
    }
    return (count == 0) ? 0 : (double)sum / count;
}

void deleteFirstEven(Node*& head) {
    if (!head) return;

    if (head->data % 2 == 0) {
        Node* temp = head;
        head = head->next;
        delete temp;
        return;
    }

    Node* temp = head;
    while (temp->next && temp->next->data % 2 != 0) {
        temp = temp->next;
    }

    if (temp->next) {
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        delete toDelete;
    }
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

    addToStart(head, 3);
    addToEnd(head, 5);
    addToEnd(head, 7);
    addToEnd(head, 9);

    printList(head);

    addToMiddle(head, 100);

    printList(head);

    cout << average(head) << endl;

    deleteFirstEven(head);

    printList(head);

    freeList(head);

    return 0;
}