#include <iostream>
#include<bits/stdc++.h>
#include <chrono>
#include <cmath>
using namespace std;
int binarySearch(int arr[], int l, int r, int key)
{
    if (r >= l) {
        float mid = ceil(l + (r - l) / 2);//to find the middle element of the sorted half
        if (arr[int(mid)] == key)//if the element is same as the middle of the sorted half
            return mid;
        if (key<arr[int(mid)] && arr[int(mid)-1]<key)//if the element is immediate left of the middle 
            return mid;
        if (key>arr[int(mid)] && arr[int(mid)+1]>key)//if the element is immediate right of the middle
            return mid+1;
        if (arr[int(mid)] > key)//if the element is on the left side of the sorted half
            return binarySearch(arr, l, mid - 1, key);
        else
            return binarySearch(arr, mid + 1, r, key);//if the element is on the right side of the sorted half
    }
    return r+1;//if greatest element
}
void insertionSort(int arr[], int n,int half) 
{ 
    int i, key, j;
    int r,l,index;
    l=0;//the zeroth position
    for (i = half; i < n; i++)//loop to sort the elements beyond the first half of the array
    {
        key = arr[i]; 
        r = i - 1;
        index=binarySearch(arr,l,r,key);//finds the index of where the element is supposed to be
        while (r >= index)//switching done to rearrange the positions
        { 
            arr[r + 1] = arr[r]; 
            r = r - 1;
        } 
        arr[r + 1] = key; 
    }
} 
int main()
{
    int n;
    cout<<"Input number of elements:";
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];//input such that the first half is sorted and the next half is random
    }
    int half=n/2;//to begin the sorting of elements after the first 5 elements
    insertionSort(arr,n,half);
    cout<<"The sorted array is:"<<endl;
    for (int i=0;i<n;i++)
    {
        cout<<arr[i]<<" ";
    }
    return 0;
}