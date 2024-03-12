#include<iostream>
using namespace std;

void selection(int arr[] ,int n)
{
    int i,j,min_idx;
    for(int i=0;i<n-1;i++)
    {
        min_idx = i;
        for(int j=i+1;j<n;j++)
        {
            if(arr[j]<arr[min_idx])
            {
                min_idx=j;
            }
            if(min_idx!=i)
            {
                swap(arr[min_idx],arr[i]);
            }
        }
    }
}

void printArray(int arr[], int n)
{
    for(int i=0 ; i<n;i++)
    {
        cout<<arr[i]<<" ";
        // cout<<endl;
    }
}
int main()
{
    int n;
    int arr[]={1,2,3,45,842,5};
    n=sizeof(arr)/sizeof(arr[0]);
    selection(arr,n);
    printArray(arr,n);
}