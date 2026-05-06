#include <iostream>
#include <map>
#include <string>
using namespace std;

int main() {
    map<string, string> phoneBook;
    int choice;
    string name, phone;

    do {
        cout << "\n1. Add contact\n";
        cout << "2. Find contact\n";
        cout << "3. Delete contact\n";
        cout << "4. Show all contacts\n";
        cout << "0. Exit\n";
        cout << "Choose: ";
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter name: ";
                cin >> name;
                cout << "Enter phone number: ";
                cin >> phone;
                phoneBook[name] = phone;
                cout << "Contact added.\n";
                break;

            case 2:
                cout << "Enter name: ";
                cin >> name;
                if (phoneBook.find(name) != phoneBook.end()) {
                    cout << "Phone number: " << phoneBook[name] << endl;
                } else {
                    cout << "Contact not found.\n";
                }
                break;

            case 3:
                cout << "Enter name: ";
                cin >> name;
                if (phoneBook.erase(name)) {
                    cout << "Contact deleted.\n";
                } else {
                    cout << "Contact not found.\n";
                }
                break;

            case 4:
                cout << "\nPhone book:\n";
                for (const auto& contact : phoneBook) {
                    cout << contact.first << ": " << contact.second << endl;
                }
                break;

            case 0:
                cout << "Exit.\n";
                break;

            default:
                cout << "Invalid choice.\n";
        }

    } while (choice != 0);

    return 0;
}
