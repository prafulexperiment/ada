#include <iostream>

using namespace std;

int n, c[20][20], i, j, visited[20];

void prim();

int main() {
    cout << "Enter the number of vertices: ";
    cin >> n;

    cout << "Enter the cost matrix:\n";
    for (i = 1; i <= n; i++) {
        for (j = 1; j <= n; j++)
            cin >> c[i][j];
        visited[i] = 0;
    }

    prim();

    return 0;
}

void prim() {
    int min, a, b, k, count = 0, cost = 0;
    min = 999;
    visited[1] = 1; 

    while (count < n - 1) {
        min = 999;

        for (i = 1; i <= n; i++)
            for (j = 1; j <= n; j++)
                if (visited[i] && !visited[j] && min > c[i][j]) {
                    min = c[i][j]; 
                    a = i;
                    b = j;
                }

        cout << a << "--->" << b << " = " << c[a][b] << endl; 
        cost += c[a][b]; 
        visited[b] = 1;
        count++;
    } 

    cout << "Total cost of Spanning tree is " << cost << endl; 
}