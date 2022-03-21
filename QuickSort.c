#include "QuickSort.h"

void QuickSort(int arr[],int L,int R) {
    int left = L, right = R-1;
    int pivot = arr[left];
    if(left>=right)
        return;
    while (left < right) {
        while(left<right && arr[right]>pivot)
            right--;

        if(left<right&&arr[right]<=pivot)
        {
            arr[left]=arr[right];
            left++;
        }

        while(left<right && arr[left]<pivot)
            left++;
        if(left<right&&arr[left]>=pivot)
        {
            arr[right]=arr[left];
            right--;
        }
        arr[left]=pivot;
    }
    QuickSort(arr,left+1,R); //left +1改变了左指针 L
    QuickSort(arr,L,right); //right改变了右指针 R
}
