#include <iostream>
#include<bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
void bubbleSort(int arr[], int n) 
{ 
    int i, j;
    int temp;
    bool swapped;
    for (i = 0; i < n-1; i++){
        swapped = false;
        for (j = 0; j < n-i-1; j++){

            if (arr[j] > arr[j+1]){ 
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swapped = true;}
        }
        if (swapped == false)
        break;
    }
} 
int main()
{
    //int arr[] = {64, 34, 25, 12, 22, 11, 90}; 
    int n=10000;
    int arr[n];
    int count;
    for (int i=0;i<10000;i++)
    {
        arr[i]=i;
    }
    auto start = high_resolution_clock::now();
    bubbleSort(arr, n); 
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    //cout<<"Sorted array: \n"; 
    //for (int i=0;i<n;i++)
        //cout<<arr[i]<<" ";
    //cout<<endl;
    cout<<"The optimized time is:"<<duration.count()<<" Microseconds";
    return 0; 
}

