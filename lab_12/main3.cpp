#include <iostream>
#include <deque>
#include <string>
#include <algorithm>

using namespace std;

struct Order {
    int id;
    string customer;
    string address;
    double cost;
    int priority;
    string status;
};

int main() {
    deque<Order> orders;

    Order o1 = {101, "Smith", "Wall St", 250.0, 1, "Pending"};
    Order o2 = {102, "Jones", "Broadway", 450.0, 5, "Pending"};
    if (o2.priority > 3) orders.push_front(o2);
    else orders.push_back(o2);

    if (o1.priority > 3) orders.push_front(o1);
    else orders.push_back(o1);

    sort(orders.begin(), orders.end(), [](Order a, Order b) {
        return a.cost < b.cost;
    });

    cout << "Orders filtered by cost range (200-500):" << endl;
    for (int i = 0; i < orders.size(); i++) {
        if (orders[i].cost >= 200 && orders[i].cost <= 500) {
            cout << "Order #" << orders[i].id << " for " << orders[i].customer << endl;
        }
    }

    return 0;
}