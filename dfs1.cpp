#include <iostream>
using namespace std;

//#include <bits/stdc++.h>
int n, a[20][20], v[20],i,j,count=0;
void dfs(int x)
{
    count++;
    v[x]=count;
    if(v[x]!=0)
    {
        cout<<x<<"\t";

        int k;
        for(k=1; k<=n;k++)
        {
            if(a[x][k]==1 && v[k]==0)
            {
                dfs(k);
            }
        }
    }
}
int main() {
 //int n, a[20][20], i, j, visited[20], source;
 cout << "Enter the number of vertices: ";
 cin >> n;
 cout << "\nEnter the adjacency matrix:\n";
 for (i = 1; i <= n; i++)
 for (j = 1; j <= n; j++)
 cin >> a[i][j];
 for (i = 1; i <= n; i++)
 v[i] = 0;
 
cout << "\nDFS:\t";
 for (i = 1; i <= n; i++)
 if (v[i] == 0)
 dfs(i);

 
 return 0;
}