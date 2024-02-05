#include <stdio.h>

void merge(int arr[], int low, int mid, int high){
    int left = low;
    int right = mid+1;
    int temp[100];
    int k=0;

    while(left<=mid && right<=high){
        if(arr[left]<=arr[right]){
            temp[k]=arr[left];
            left++;
            k++;
        }
        else{
            temp[k]=arr[right];
            right++;
            k++;
        }
    }
    while(left<=mid){
        temp[k]=arr[left];
        left++;
        k++;
    }
    while(right<=high){
        temp[k]=arr[right];
        right++;
        k++;
    }
    for(int i=low;i<=high;i++){
        arr[i]=temp[i-low];
    }
}

void mergeSort(int arr[], int low, int high){
    if(low>=high) return;
    int mid = (low+high)/2;
    mergeSort(arr,low,mid);
    mergeSort(arr,mid+1,high);
    merge(arr,low,mid,high);
}

int main() {
    int arr[8] = {4, 6, 2, 5, 7, 9, 1, 3};
    int size = sizeof(arr) / sizeof(arr[0]);

    mergeSort(arr, 0, size - 1);

    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }

    return 0;
}
