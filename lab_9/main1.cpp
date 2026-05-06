#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;

struct Node {
    int data;
    Node* left;
    Node* right;

    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int value) {
    if (root == nullptr)
        return new Node(value);

    if (value < root->data)
        root->left = insert(root->left, value);
    else if (value > root->data)
        root->right = insert(root->right, value);

    return root;
}

bool exists(Node* root, int value) {
    if (root == nullptr) return false;
    if (root->data == value) return true;

    if (value < root->data)
        return exists(root->left, value);
    else
        return exists(root->right, value);
}

void splitTree(Node* root, Node*& evenTree, Node*& oddTree) {
    if (root == nullptr) return;

    if (root->data % 2 == 0)
        evenTree = insert(evenTree, root->data);
    else
        oddTree = insert(oddTree, root->data);

    splitTree(root->left, evenTree, oddTree);
    splitTree(root->right, evenTree, oddTree);
}

int depth(Node* root) {
    if (root == nullptr) return 0;

    int leftDepth = depth(root->left);
    int rightDepth = depth(root->right);

    return max(leftDepth, rightDepth) + 1;
}

void printTree(Node* root) {
    if (root == nullptr) return;

    printTree(root->left);
    cout << root->data << " ";
    printTree(root->right);
}

void deleteTree(Node* root) {
    if (root == nullptr) return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    Node* root = nullptr;
    Node* evenTree = nullptr;
    Node* oddTree = nullptr;

    int n;
    cout << "Enter number of nodes: ";
    cin >> n;

    int choice;
    cout << "1 - manual input, 2 - random: ";
    cin >> choice;

    if (choice == 1) {
        int value;
        for (int i = 0; i < n; i++) {
            cout << "Enter value: ";
            cin >> value;

            if (!exists(root, value))
                root = insert(root, value);
            else {
                cout << "Value already exists!\n";
                i--;
            }
        }
    } else if (choice == 2) {
        int a, b;
        cout << "Enter range [a, b]: ";
        cin >> a >> b;

        if (a >= b || n > (b - a + 1)) {
            cout << "Invalid range or too many nodes!\n";
            return 1;
        }

        srand(time(0));

        while (n > 0) {
            int value = a + rand() % (b - a + 1);

            if (!exists(root, value)) {
                root = insert(root, value);
                n--;
            }
        }
    }

    splitTree(root, evenTree, oddTree);

    cout << "\nMain tree: ";
    printTree(root);

    cout << "\nEven tree: ";
    printTree(evenTree);

    cout << "\nOdd tree: ";
    printTree(oddTree);

    cout << "\n\nMain tree depth: " << depth(root);
    cout << "\nEven tree depth: " << depth(evenTree);
    cout << "\nOdd tree depth: " << depth(oddTree);

    deleteTree(root);
    deleteTree(evenTree);
    deleteTree(oddTree);

    return 0;
}