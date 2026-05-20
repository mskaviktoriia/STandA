#include <iostream>
#include <iomanip>

using namespace std;

const int ROWS = 3;
const int COLS = 3;

void printLine() {
    cout << "-------------------------------------------------------------\n";
}

void showData(int cost[ROWS][COLS],
              int supply[ROWS],
              int demand[COLS]) {

    cout << "\nCurrent transportation data:\n\n";

    cout << "|     | M1 | M2 | M3 | Supply |\n";
    cout << "|-----|----|----|----|--------|\n";

    for (int i = 0; i < ROWS; i++) {

        cout << "| S" << i + 1 << "  |";

        for (int j = 0; j < COLS; j++) {
            cout << setw(4)
                 << cost[i][j]
                 << "|";
        }

        cout << setw(8)
             << supply[i]
             << "|";

        cout << endl;
    }

    cout << "|-----|----|----|----|--------|\n";
    cout << "|Dem. |";

    for (int i = 0; i < COLS; i++) {
        cout << setw(4)
             << demand[i]
             << "|";
    }

    cout << endl;

    printLine();
}

void printPlan(int plan[ROWS][COLS],
               string title) {

    cout << "\n" << title << "\n\n";

    cout << "|     | M1 | M2 | M3 |\n";
    cout << "|-----|----|----|----|\n";

    for (int i = 0; i < ROWS; i++) {

        cout << "| S" << i + 1 << "  |";

        for (int j = 0; j < COLS; j++) {

            cout << setw(4)
                 << plan[i][j]
                 << "|";
        }

        cout << endl;
    }
}

int calculateCost(int plan[ROWS][COLS],
                  int cost[ROWS][COLS]) {

    int totalCost = 0;

    for (int i = 0; i < ROWS; i++) {
        for (int j = 0; j < COLS; j++) {

            totalCost +=
                plan[i][j] * cost[i][j];
        }
    }

    return totalCost;
}

void northWestMethod(int supply[],
                     int demand[],
                     int cost[ROWS][COLS]) {

    int s[ROWS];
    int d[COLS];

    for (int i = 0; i < ROWS; i++)
        s[i] = supply[i];

    for (int i = 0; i < COLS; i++)
        d[i] = demand[i];

    int plan[ROWS][COLS] = {0};

    int i = 0;
    int j = 0;

    while (i < ROWS && j < COLS) {

        int x = min(s[i], d[j]);

        plan[i][j] = x;

        s[i] -= x;
        d[j] -= x;

        if (s[i] == 0)
            i++;
        else
            j++;
    }

    printPlan(plan,
              "North-West Corner Method:");

    cout << "\nTotal delivery cost: "
         << calculateCost(plan, cost)
         << endl;
}

void minimumCostMethod(int supply[],
                       int demand[],
                       int cost[ROWS][COLS]) {

    int s[ROWS];
    int d[COLS];

    for (int i = 0; i < ROWS; i++)
        s[i] = supply[i];

    for (int i = 0; i < COLS; i++)
        d[i] = demand[i];

    int plan[ROWS][COLS] = {0};

    bool used[ROWS][COLS] = {false};

    while (true) {

        int minCost = 1000000;

        int row = -1;
        int col = -1;

        for (int i = 0; i < ROWS; i++) {
            for (int j = 0; j < COLS; j++) {

                if (!used[i][j] &&
                    s[i] > 0 &&
                    d[j] > 0 &&
                    cost[i][j] < minCost) {

                    minCost = cost[i][j];

                    row = i;
                    col = j;
                }
            }
        }

        if (row == -1 || col == -1)
            break;

        int x = min(s[row], d[col]);

        plan[row][col] = x;

        s[row] -= x;
        d[col] -= x;

        if (s[row] == 0 ||
            d[col] == 0) {

            used[row][col] = true;
        }
    }

    printPlan(plan,
              "Minimum Cost Method:");

    cout << "\nMinimum total delivery cost: "
         << calculateCost(plan, cost)
         << endl;
}

int main() {

    int cost[ROWS][COLS] = {
        {8, 7, 2},
        {1, 4, 3},
        {5, 1, 6}
    };

    int supply[ROWS] = {
        1500,
        1900,
        1600
    };

    int demand[COLS] = {
        1800,
        1200,
        2000
    };

    showData(cost, supply, demand);

    int choice;

    do {

        cout << "\nDo you want to change something?\n";
        cout << "1 - Change transportation cost\n";
        cout << "2 - Change supply\n";
        cout << "3 - Change demand\n";
        cout << "0 - Save data and continue\n";
        cout << "Your choice: ";

        cin >> choice;

        if (choice == 1) {

            int row, col;

            cout << "\nEnter warehouse number (1-3): ";
            cin >> row;

            cout << "Enter market number (1-3): ";
            cin >> col;

            cout << "Enter new transportation cost: ";
            cin >> cost[row - 1][col - 1];
        }

        else if (choice == 2) {

            int row;

            cout << "\nEnter warehouse number (1-3): ";
            cin >> row;

            cout << "Enter new supply value: ";
            cin >> supply[row - 1];
        }

        else if (choice == 3) {

            int col;

            cout << "\nEnter market number (1-3): ";
            cin >> col;

            cout << "Enter new demand value: ";
            cin >> demand[col - 1];
        }

        if (choice != 0) {
            showData(cost, supply, demand);
        }

    } while (choice != 0);

    cout << "\nFinal data:\n";

    showData(cost, supply, demand);

    northWestMethod(
        supply,
        demand,
        cost
    );

    minimumCostMethod(
        supply,
        demand,
        cost
    );

    return 0;
}