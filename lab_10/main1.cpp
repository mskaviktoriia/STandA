#include <iostream>
using namespace std;

const int MAX = 100;

int graph[MAX][MAX];
int n;

void inputMatrix() {
    cout << "Enter number of vertices: ";
    cin >> n;

    cout << "Enter adjacency matrix:\n";
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            cin >> graph[i][j];
}

bool isComplete() {
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            if (i != j && graph[i][j] == 0)
                return false;
    return true;
}

void adjacencyList() {
    cout << "\nAdjacency list:\n";
    for (int i = 0; i < n; i++) {
        cout << i + 1 << ": ";
        for (int j = 0; j < n; j++) {
            if (graph[i][j] != 0)
                cout << "(" << j + 1 << "," << graph[i][j] << ") ";
        }
        cout << endl;
    }
}

void averageDistance() {
    int sum = 0, edges = 0;

    for (int i = 0; i < n; i++)
        for (int j = i + 1; j < n; j++)
            if (graph[i][j] != 0) {
                sum += graph[i][j];
                edges++;
            }

    if (edges > 0)
        cout << "\nAverage distance: " << (double)sum / edges << endl;
}

void isolatedVertices() {
    int count = 0;

    cout << "\nIsolated vertices:\n";

    for (int i = 0; i < n; i++) {
        int degree = 0;
        int lastWeight = 0;

        for (int j = 0; j < n; j++) {
            if (graph[i][j] != 0) {
                degree++;
                lastWeight = graph[i][j];
            }
        }

        if (degree == 1) {
            cout << "Vertex " << i + 1 << " distance " << lastWeight << endl;
            count++;
        }
    }

    cout << "Total isolated: " << count << endl;
}

void longestPath3() {
    int maxDist = 0;
    int a = -1, b = -1, c = -1;

    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            for (int k = 0; k < n; k++)
                if (i != j && j != k && graph[i][j] != 0 && graph[j][k] != 0) {
                    int dist = graph[i][j] + graph[j][k];
                    if (dist > maxDist) {
                        maxDist = dist;
                        a = i;
                        b = j;
                        c = k;
                    }
                }

    if (a != -1)
        cout << "\nLongest path: (" << a + 1 << ") --- "
             << graph[a][b] << " --- (" << b + 1 << ") --- "
             << graph[b][c] << " --- (" << c + 1 << ")\n";
}

void dfs(int v, bool visited[]) {
    visited[v] = true;

    for (int i = 0; i < n; i++) {
        if (graph[v][i] != 0 && !visited[i])
            dfs(i, visited);
    }
}

void checkConnected() {
    bool visited[MAX] = {false};

    dfs(0, visited);

    for (int i = 0; i < n; i++) {
        if (!visited[i]) {
            cout << "\nCannot visit all vertices once\n";
            return;
        }
    }

    cout << "\nGraph is connected (can visit all vertices)\n";
}

int main() {
    inputMatrix();

    if (isComplete())
        cout << "\nGraph is complete\n";
    else
        cout << "\nGraph is not complete\n";

    adjacencyList();
    averageDistance();
    isolatedVertices();
    longestPath3();
    checkConnected();

    return 0;
}