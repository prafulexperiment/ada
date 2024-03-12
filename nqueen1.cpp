#include <iostream>
#include <cmath>

int count = 0;
int x[100];

int place(int k, int i) {
    for (int j = 1; j < k; j++)
        if (x[j] == i || std::abs(x[j] - i) == std::abs(j - k))
            return 0;
    return 1;
}

void nqueen(int k, int n) {
    for (int i = 1; i <= n; i++)
        if (place(k, i)) {
            x[k] = i;
            if (k == n) {
                count++;
                for (int j = 1; j <= n; j++) {
                    for (int p = 1; p <= n; p++)
                        std::cout << (x[j] == p ? " q " : " 0 ");
                    std::cout << "\n";
                }
                std::cout << "\n";
            } else {
                nqueen(k + 1, n);
            }
        }
}

int main() {
    int n;
    std::cout << "\t\t\tN QUEEN'S PROBLEM\n";
    std::cout << "Enter the number of patients: ";
    std::cin >> n;
    
    nqueen(1, n);

    if (count == 0)
        std::cout << "\nThere is no solution for '" << n << "-Queens' problem\n";
    else
        std::cout << "Total number of solutions: " << count << "\n";

    return 0;
}
