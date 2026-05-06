#include <iostream>
#include <string>
#include <ctime>
using namespace std;

struct Node {
    string name;
    int height;
    Node* left;
    Node* right;

    Node(string n, int h) {
        name = n;
        height = h;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root, string name, int height) {
    if (!root) {
        return new Node(name, height);
    }

    if (height > root->height) {
        root->left = insert(root->left, name, height);
    } else {
        root->right = insert(root->right, name, height);
    }

    return root;
}

int countNodes(Node* root) {
    if (!root)
        return 0;
    return 1 + countNodes(root->left) + countNodes(root->right);
}

int findName(Node* root, string name) {
    if (!root)
        return 0;

    int count = 0;
    if (root->name == name)
        count = 1;

    return count + findName(root->left, name) + findName(root->right, name);
}

bool exists(Node* root, string name) {
    if (!root)
        return false;

    if (root->name == name)
        return true;

    return exists(root->left, name) || exists(root->right, name);
}

int depth(Node* root) {
    if (!root)
        return 0;

    int l = depth(root->left);
    int r = depth(root->right);

    return 1 + max(l, r);
}

void copyLeftHeights(Node* root, Node*& newTree) {
    if (!root)
        return;

    if (root->left) {
        newTree = insert(newTree, "", root->left->height);
        copyLeftHeights(root->left, newTree);
    }

    copyLeftHeights(root->right, newTree);
}

void printTree(Node* root) {
    if (!root)
        return;

    cout << root->name << " " << root->height << endl;

    printTree(root->left);
    printTree(root->right);
}

void freeTree(Node* root) {
    if (!root)
        return;

    freeTree(root->left);
    freeTree(root->right);
    delete root;
}

string randomName() {
    string names[] = {"Vika", "Angelina", "Sofia", "Liza", "Vlad"};
    int size = sizeof(names) / sizeof(names[0]);
    return names[rand() % size];
}

int main() {
    srand(time(NULL));

    Node* root = NULL;
    int n;

    cout << "Enter number of nodes: ";
    cin >> n;

    for (int i = 0; i < n; i++) {
        int h = rand() % 50 + 150;
        string name = randomName();
        cout << name << " " << h << endl;
        root = insert(root, name, h);
    }

    cout << "\nOriginal tree:\n";
    printTree(root);

    cout << "\nTotal nodes: " << countNodes(root) << endl;

    string searchName;
    cout << "\nEnter search name: ";
    cin >> searchName;

    int count = findName(root, searchName);

    if (count > 0) {
        cout << "Name exists. Occurrences: " << count << endl;
    } else {
        cout << "Name not found\n";
    }

    Node* newTree = NULL;
    copyLeftHeights(root, newTree);

    cout << "\nNew tree:\n";
    printTree(newTree);

    cout << "\nNew tree nodes: " << countNodes(newTree) << endl;

    cout << "\nDepth of original tree: " << depth(root) << endl;
    cout << "Depth of new tree: " << depth(newTree) << endl;

    freeTree(root);
    freeTree(newTree);

    return 0;
}