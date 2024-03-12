#include<iostream>
using namespace std;

void bfs(int a[20][20],int source,int visited[20], int n)
{
    int queue[20],f,r,u,v;
    f=0;
    r=-1;
    queue[++r]=source;
    while(f<=r)
    {
        u=queue[f++];
        for(v=1;v<=n;v++)
        {
            if(a[u][v]==1 && visited[v]==0)
            {
                queue[++r]=v;
                visited[v]=1;
            }
        }
    }
}
int main()
{ int n,a[20][20],source,visited[20];
    cout<<"enter the no. of vertices";
    cin>>n;

    cout<<"enter the adjacency matrix";
    for(int i=0;i<n;i++)
    {
        for(int j=0;j<n;j++)
        {
            cin>>a[i][j];
        }
    }


    cout<<"enter the source node";
    cin>>source;

    for(int i=0;i<n;i++)
  {
    visited[i]=0;
  }

  visited[source]=1;

  bfs(a,source,visited,n);

  for(int i=0;i<n;i++)
  {
  if(visited[i]!=0)
  {
    cout<<"node"<<i<<"is reachable";
    cout<<endl;
  }
  else{
    cout<<"node"<<i<<"is not reachable";
  }
  }

}