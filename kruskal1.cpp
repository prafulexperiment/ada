#include <iostream>
using namespace std;
#include <chrono>
using namespace chrono;
// Function prototypes
void find_min();
int check_cycle(int x, int y);

int min_cost, cost[100][100], parent[100], i, j, x, y, n;

int main() {
    auto start = high_resolution_clock::now();
    int count = 0, tot = 0, flag = 0;
    cout<<"Enter the number of vertices \n";
    cin>>n;
    cout<<"Enter the cost matrix \n";
    cout<<"Enter 999 for No edges and self loops \n";
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++) {
            cin>>cost[i][j];
            parent[j] = 0;
        }
    while (count != n - 1 && min_cost != 999) {
        find_min();
        flag = check_cycle(x, y);
        if (flag == 1) {
           cout<<x <<"---->"<< y<<"="<<cost[x][y]<<endl;
           //cout<<endl;
            count++;
            tot += cost[x][y];
        }
        cost[x][y] = cost[y][x] = 999;
    }
    auto end = high_resolution_clock::now();
   cout<<"\nThe total cost of minimum spanning tree="<< tot;
//    cout << "Time taken: " << duration_cast<milliseconds>(end - start).count() << " milliseconds" << endl;
cout << "Time taken: " << (end - start).count() << " microseconds" << endl;
    return 0;
    
    
}

void find_min() {
    min_cost = 999;
    for (i = 1; i <= n; i++)
        for (j = 1; j <= n; j++)
            if (cost[i][j] < min_cost) {
                min_cost = cost[i][j];
                x = i;
                y = j;
            }
}

int check_cycle(int x, int y) {
    if ((parent[x] == parent[y]) && (parent[x] != 0))
        return 0;
    else if (parent[x] == 0 && parent[y] == 0)
        parent[x] = parent[y] = x;
    else if (parent[x] == 0)
        parent[x] = parent[y];
    else if (parent[x] != parent[y])
        parent[y] = parent[x];
    return 1;
}
