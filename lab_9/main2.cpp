#include <iostream>
#include <fstream>
#include <string>
#include <map>
using namespace std;

struct Node {
    int code;
    string name;
    double price;
    Node* left;
    Node* right;

    Node(int c, string n, double p) {
        code = c;
        name = n;
        price = p;
        left = right = nullptr;
    }
};

Node* insert(Node* root, int code, string name, double price) {
    if (root == nullptr)
        return new Node(code, name, price);

    if (code < root->code)
        root->left = insert(root->left, code, name, price);
    else if (code > root->code)
        root->right = insert(root->right, code, name, price);

    return root;
}

Node* search(Node* root, int code) {
    if (root == nullptr || root->code == code)
        return root;

    if (code < root->code)
        return search(root->left, code);
    else
        return search(root->right, code);
}

void sumAndCount(Node* root, double& sum, int& count) {
    if (root == nullptr) return;

    sum += root->price;
    count++;

    sumAndCount(root->left, sum, count);
    sumAndCount(root->right, sum, count);
}

void countLevels(Node* root, int level, map<int, int>& levels) {
    if (root == nullptr) return;

    levels[level]++;

    countLevels(root->left, level + 1, levels);
    countLevels(root->right, level + 1, levels);
}

void deleteSubtree(Node*& root) {
    if (root == nullptr) return;

    deleteSubtree(root->left);
    deleteSubtree(root->right);
    delete root;
    root = nullptr;
}

void deleteChildren(Node* root, int code) {
    Node* target = search(root, code);
    if (target == nullptr) return;

    deleteSubtree(target->left);
    deleteSubtree(target->right);
}

void deleteTree(Node* root) {
    if (root == nullptr) return;

    deleteTree(root->left);
    deleteTree(root->right);
    delete root;
}

int main() {
    ifstream file("data.txt");

    Node* root = nullptr;

    int code;
    string name;
    double price;

    while (file >> code >> name >> price) {
        root = insert(root, code, name, price);
    }

    double sum = 0;
    int count = 0;
    sumAndCount(root, sum, count);

    if (count > 0)
        cout << "Average price: " << sum / count << endl;

    map<int, int> levels;
    countLevels(root, 0, levels);

    cout << "Nodes per level:\n";
    for (auto& p : levels) {
        cout << "Level " << p.first << ": " << p.second << endl;
    }

    int searchCode;
    cout << "Enter code to delete children: ";
    cin >> searchCode;

    deleteChildren(root, searchCode);

    deleteTree(root);

    return 0;
}