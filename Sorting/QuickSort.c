#include <stdio.h>
int partition(int arr[], int low, int high){
    int pivot = arr[low];
    int i=low,j=high,temp;

    while(i<j){
        while(arr[i]<=pivot && i<high){
            i++;
        }
        while(arr[j]>pivot && j>low){
            j--;
        }
        if(i<j){
            temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
        temp = arr[low];
        arr[low] = arr[j];
        arr[j] = temp;
        return j;
}
void quickSort(int arr[], int low, int high){
    if(low<high){
        int partitionIndex = partition(arr,low,high);
        quickSort(arr,low,partitionIndex-1);
        quickSort(arr,partitionIndex+1,high);
    }
}
int main()
{
    int arr[8]={4, 6, 2, 5, 7, 9, 1, 3};
    int size = sizeof(arr)/sizeof(arr[0]);
    quickSort(arr,0,size-1);
    for(int i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
    return 0;
}
