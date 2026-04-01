#include <iostream>
#include <string>
using namespace std;

struct Node {
    string date;
    double temp;
    Node* prev;
    Node* next;
};

int main() {
    int n1, n2;
    cin >> n1;
    Node* head1 = nullptr;
    Node* tail1 = nullptr;

    for (int i = 0; i < n1; i++) {
        Node* node = new Node;
        cin >> node->date >> node->temp;
        node->prev = tail1;
        node->next = nullptr;
        if (tail1) tail1->next = node;
        else head1 = node;
        tail1 = node;
    }

    cin >> n2;
    Node* head2 = nullptr;
    Node* tail2 = nullptr;

    for (int i = 0; i < n2; i++) {
        Node* node = new Node;
        cin >> node->date >> node->temp;
        node->prev = tail2;
        node->next = nullptr;
        if (tail2) tail2->next = node;
        else head2 = node;
        tail2 = node;
    }

    if (tail1) tail1->next = head2;
    if (head2) head2->prev = tail1;
    Node* head = head1 ? head1 : head2;

    if (head) {
        double maxTemp = head->temp;
        double minTemp = head->temp;
        Node* curr = head;
        while (curr) {
            if (curr->temp > maxTemp) maxTemp = curr->temp;
            if (curr->temp < minTemp) minTemp = curr->temp;
            curr = curr->next;
        }
        cout << maxTemp << endl;
        cout << minTemp << endl;
    }

    Node* curr = head;
    while (curr) {
        Node* temp = curr;
        curr = curr->next;
        delete temp;
    }

    return 0;
}