#include <iostream>
#include <vector>
#include <iomanip>

using namespace std;

struct Employee {
    string position;
    int A;
    int B;
    int quantity;
};

void printLine() {
    cout << string(110, '-') << endl;
}

void showEmployees(vector<Employee>& employees) {

    printLine();

    cout << left
         << setw(5)  << "ID"
         << setw(25) << "Position"
         << setw(10) << "A"
         << setw(10) << "B"
         << setw(15) << "Coefficient"
         << setw(15) << "Quantity"
         << endl;

    printLine();

    for (int i = 0; i < employees.size(); i++) {

        double coefficient =
            (double)employees[i].A / employees[i].B;

        cout << left
             << setw(5)  << i + 1
             << setw(25) << employees[i].position
             << setw(10) << employees[i].A
             << setw(10) << employees[i].B
             << setw(15) << coefficient
             << setw(15) << employees[i].quantity
             << endl;
    }

    printLine();
}

int main() {

    vector<Employee> employees = {
        {"Nurse Assistant", 1, 1, 7},
        {"Nurse", 6, 5, 10},
        {"Doctor", 8, 5, 10},
        {"Head of Pharmacy", 9, 5, 1},
        {"Department Head", 2, 1, 3},
        {"Chief Doctor", 12, 5, 1},
        {"Head of Household", 13, 5, 1},
        {"Hospital Director", 3, 1, 1}
    };

    double totalFund;

    cout << "Enter total salary fund (recommended 380000): ";
    cin >> totalFund;

    cout << "\nCurrent employee data:\n";

    showEmployees(employees);

    int choice;

    do {

        cout << "\nDo you want to change something?\n";
        cout << "1 - Change employee data\n";
        cout << "0 - Save data and continue\n";
        cout << "Your choice: ";
        cin >> choice;

        if (choice == 1) {

            int employeeID;

            cout << "\nEnter employee ID: ";
            cin >> employeeID;

            employeeID--;

            if (employeeID >= 0 &&
                employeeID < employees.size()) {

                cout << "\n1 - Change A\n";
                cout << "2 - Change B\n";
                cout << "3 - Change quantity\n";
                cout << "Your choice: ";

                int editChoice;
                cin >> editChoice;

                if (editChoice == 1) {

                    cout << "Enter new A: ";
                    cin >> employees[employeeID].A;
                }
                else if (editChoice == 2) {

                    cout << "Enter new B: ";
                    cin >> employees[employeeID].B;
                }
                else if (editChoice == 3) {

                    cout << "Enter new quantity: ";
                    cin >> employees[employeeID].quantity;
                }

                cout << "\nUpdated data:\n";

                showEmployees(employees);
            }
            else {
                cout << "\nInvalid employee ID\n";
            }
        }

    } while (choice != 0);

    double totalCoefficient = 0;

    for (const auto& employee : employees) {

        double coefficient =
            (double)employee.A / employee.B;

        totalCoefficient +=
            coefficient * employee.quantity;
    }

    double baseSalary =
        totalFund / totalCoefficient;

    cout << fixed << setprecision(2);

    cout << "\nBase salary for Nurse Assistant: "
         << baseSalary << " UAH\n";

    printLine();

    cout << left
         << setw(25) << "Position"
         << setw(10) << "A"
         << setw(10) << "B"
         << setw(15) << "Coefficient"
         << setw(15) << "Salary"
         << setw(15) << "Quantity"
         << setw(20) << "Total Salary"
         << endl;

    printLine();

    double finalSum = 0;

    for (const auto& employee : employees) {

        double coefficient =
            (double)employee.A / employee.B;

        double salary =
            baseSalary * coefficient;

        double totalSalary =
            salary * employee.quantity;

        finalSum += totalSalary;

        cout << left
             << setw(25) << employee.position
             << setw(10) << employee.A
             << setw(10) << employee.B
             << setw(15) << coefficient
             << setw(15) << salary
             << setw(15) << employee.quantity
             << setw(20) << totalSalary
             << endl;
    }

    printLine();

    cout << "\nFinal salary fund: "
         << finalSum << " UAH\n";

    return 0;
}