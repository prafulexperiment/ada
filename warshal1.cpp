#include <iostream>
int max(int a, int b) {
 return (a > b) ? a : b;
}
void warshall(int p[10][10], int n) {
 for (int k = 1; k <= n; k++)
 for (int i = 1; i <= n; i++)
 for (int j = 1; j <= n; j++)
 p[i][j] = max(p[i][j], p[i][k] && p[k][j]);
}
int main() {
 int p[10][10]={0}, n, e, u, v;
 // Input the number of systems and edges
 std::cout << "\n Enter the number of systems (vertices):";
 std::cin >> n;
 std::cout << "\n Enter the number of connections (edges):";
 std::cin >> e;
 // Input the connections and populate the adjacency matrix
 for (int i = 1; i <= e; i++) {
 std::cout << "\n Enter the end systems of connection " << i << ":";
 std::cin >> u >> v;
 p[u][v] = 1;
 }
 // Display the adjacency matrix
 std::cout << "\n Matrix of input data: \n";
 for (int i = 1; i <= n; i++) {
 for (int j = 1; j <= n; j++)
 std::cout << p[i][j] << "\t";
 std::cout << "\n";
 }
 // Apply Warshall's algorithm to find transitive closure
 warshall(p, n);
 // Display the transitive closure matrix
 std::cout << "\n Transitive closure: \n";
 for (int i = 1; i <= n; i++) {
 for (int j = 1; j <= n; j++)
 std::cout << p[i][j] << "\t";
 std::cout << "\n";
 }
 return 0;
}
