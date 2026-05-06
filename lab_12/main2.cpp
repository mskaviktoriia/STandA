#include <iostream>
#include <list>
#include <string>

using namespace std;

struct Car {
    string name;
    int year;
    double mileage;
};

int main() {
    list<Car> carList;
    int choice;

    while (true) {
        cout << "\nMENU FOR WORKING WITH LIST" << endl;
        cout << "1. Input first element" << endl;
        cout << "2. Insert at beginning" << endl;
        cout << "3. Insert at end" << endl;
        cout << "4. Insert after element" << endl;
        cout << "5. Insert before element" << endl;
        cout << "6. Search for node" << endl;
        cout << "7. Delete by year" << endl;
        cout << "8. View list" << endl;
        cout << "9. Exit" << endl;
        cout << "Enter operation number: ";
        cin >> choice;

        if (choice == 9) break;

        if (choice >= 1 && choice <= 5) {
            Car c;
            cout << "Name: "; cin >> c.name;
            cout << "Year: "; cin >> c.year;
            cout << "Mileage: "; cin >> c.mileage;

            if (choice == 1 || choice == 3) {
                carList.push_back(c);
            } else if (choice == 2) {
                carList.push_front(c);
            } else if (choice == 4 || choice == 5) {
                string targetName;
                cout << "Enter target car name: "; cin >> targetName;
                bool found = false;
                for (auto it = carList.begin(); it != carList.end(); ++it) {
                    if (it->name == targetName) {
                        if (choice == 4) {
                            auto nextIt = it;
                            carList.insert(++nextIt, c);
                        } else {
                            carList.insert(it, c);
                        }
                        found = true;
                        break;
                    }
                }
                if (!found) cout << "Target car not found!" << endl;
            }
        }
        else if (choice == 6) {
            string searchName;
            cout << "Enter name to search: "; cin >> searchName;
            bool found = false;
            for (auto it = carList.begin(); it != carList.end(); ++it) {
                if (it->name == searchName) {
                    found = true;
                    break;
                }
            }
            if (found) cout << "Car with name " << searchName << " is in the list" << endl;
            else cout << "Car with name " << searchName << " is not in the list" << endl;
        }
        else if (choice == 7) {
            int limitYear;
            cout << "Enter year limit: "; cin >> limitYear;
            auto it = carList.begin();
            while (it != carList.end()) {
                if (it->year < limitYear) it = carList.erase(it);
                else ++it;
            }
        }
        else if (choice == 8) {
            for (const auto& c : carList) {
                cout << c.name << " (" << c.year << ") - " << c.mileage << " km" << endl;
            }
        }
    }
    return 0;
}