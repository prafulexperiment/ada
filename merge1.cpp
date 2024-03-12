#include<iostream>
using namespace std;

void merge(int arr[] , int left, int mid, int right)
{
    int n1= mid-left +1;
    int n2 = right-mid;


    int *leftArray = new int[n1];
    int *rightArray = new int [n2];

    for(int i=0;i<n1;i++)
    {
        leftArray[i]=arr[left+i];
    }
    for(int j=0;j<n2;j++)
    {
        rightArray[j]=arr[mid+1+j];
    }

int k=left,i=0,j=0;
    while(i<n1 && j<n2)
    {   
        if(leftArray[i]<=rightArray[j])
        {
            arr[k]=leftArray[i];
            i++;
        }
        else{
            arr[k]=rightArray[j];
            j++;
        }
        k++;

    }

    while(i<n1)
    {
        arr[k]=leftArray[i];
        i++;
        k++;
    }
     while(j<n2)
    {
        arr[k]=rightArray[j];
        j++;
        k++;
    }


}

void mergeSort(int arr[],int left,int right)
{
    if(left<right)
    {
      int  mid= left+(right-left)/2;

        mergeSort(arr,left,mid);
        mergeSort(arr,mid+1,right);

        merge(arr,left,mid,right);
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
    mergeSort(arr,0,n-1);
    printArray(arr,n);
    return 0;
}