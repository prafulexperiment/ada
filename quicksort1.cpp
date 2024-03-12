#include<iostream>
#include <bits/stdc++.h>
using namespace std;
void quicksort(int arr[],int low,int high);

int partition(int arr[], int low, int high)
{   int j;
    int pivot= arr[high];
    int i=low-1;
    for(j = low;j<high;j++)
    {
        if(arr[j]<pivot)
        {
            i++;
            swap(arr[i],arr[j]);
        }

    }
    swap(arr[i+1],arr[high]);
    return i+1;
}

void quicksort(int arr[],int low,int high)
{
    if(low<high)
    {
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}
void printArray(int arr[], int n)
{
    for(int i=0;i<n;i++)
    {
        cout<<arr[i]<<"\t";
    }
}

int main()
{
    int arr[]={12,43,2,4,51,3,4,2};
    int n=sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,n-1);
    printArray(arr,n);
    return 0;
}