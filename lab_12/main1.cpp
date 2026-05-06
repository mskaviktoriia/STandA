#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

struct Book {
    string title;
    string genre;
    double price;
    int popularity;
    int year;
};

void printBooks(const vector<Book>& books) {
    for (int i = 0; i < books.size(); i++) {
        cout << books[i].title << " | " << books[i].genre << " | " << books[i].price << " | " << books[i].popularity << endl;
    }
}

int main() {
    vector<Book> inventory;
    
    inventory.push_back({"The Great Gatsby", "Classic", 15.5, 80, 1925});
    inventory.push_back({"To Kill a Mockingbird", "Fiction", 12.0, 95, 1960});
    inventory.push_back({"Dune", "Sci-Fi", 20.0, 70, 1965});

    sort(inventory.begin(), inventory.end(), [](Book a, Book b) {
        return a.price < b.price;
    });

    cout << "Sorted by price:" << endl;
    printBooks(inventory);

    string filterGenre = "Fiction";
    cout << "\nFiltered by genre (" << filterGenre << "):" << endl;
    for (int i = 0; i < inventory.size(); i++) {
        if (inventory[i].genre == filterGenre) {
            cout << inventory[i].title << endl;
        }
    }

    return 0;
}