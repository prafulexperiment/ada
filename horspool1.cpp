#include <iostream>
#include <cstring>
using namespace std;

int horspool(const char* pattern, const char* text) {
    int m = strlen(pattern);
    int n = strlen(text);

    int table[256];
    for (int i = 0; i < 256; i++)
        table[i] = m;

    for (int j = 0; j <= m - 2; j++)
        table[pattern[j]] = m - 1 - j;

    int i = m - 1;
    while (i <= n - 1) {
        int k = 0;
        while (k <= m - 1 && (pattern[m - 1 - k] == text[i - k]))
            k++;

        if (k == m)
            return i - m + 1;
        else
            i = i + table[text[i]];
    }

    return -1;
}

int main() {
    char text[1000], pattern[20];

    cout << "Enter the text: \n";
    cin.getline(text, sizeof(text));

    cout << "Enter the pattern to be found: \n";
    cin.getline(pattern, sizeof(pattern));

    int result = horspool(pattern, text);

    if (result == -1)
        cout << "Pattern not found\n";
    else
        cout << "Pattern found at position " << result + 1 << "\n";

    return 0;
}