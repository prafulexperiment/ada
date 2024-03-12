#include <iostream>
using namespace std;

void heapSort(int a[], int n);
void siftDown(int a[], int root, int bottom);

int main() {
    int a[100], n, i;

    cout << "Enter the number of elements: \n";
    cin >> n;

    cout << "Enter the elements: \n";
    for (i = 0; i < n; i++)
        cin >> a[i];

    heapSort(a, n);

    cout << "Sorted elements are: \n";
    for (i = 0; i < n; i++)
        cout << a[i] << " ";

    return 0;
}

void heapSort(int a[], int n) {
    int i, temp;

    for (i = n - 1; i >= 0; i--)
        siftDown(a, i, n - 1);

    for (i = n - 1; i >= 1; i--) {
        temp = a[0];
        a[0] = a[i];
        a[i] = temp;
        siftDown(a, 0, i - 1);
    }
}

void siftDown(int a[], int root, int bottom) {
    int done, maxChild, temp;

    done = 0;
    while ((root * 2 <= bottom) && (!done)) {
        if (root * 2 == bottom)
            maxChild = root * 2;
        else if (a[root * 2] > a[root * 2 + 1])
            maxChild = root * 2;
        else
            maxChild = root * 2 + 1;

        if (a[root] < a[maxChild]) {
            temp = a[root];
            a[root] = a[maxChild];
            a[maxChild] = temp;
            root = maxChild;
        } else
            done = 1;
    }
}
