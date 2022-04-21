#include <iostream>
#include<bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
int insertionSort(int arr[], int n) 
{ 
    int i, key, j; 
    int counter=0;
    for (i = 1; i < n; i++)
    { 
        key = arr[i]; 
        j = i - 1; 
        while (j >= 0 && arr[j] > key)
        { 
            arr[j + 1] = arr[j]; 
            j = j - 1;
            counter+=1; 
        } 
        arr[j + 1] = key; 
    }
    return counter;  
} 
int main()
{
    int n=10000;
    int arr[n];
    int count;
    for (int i=0;i<10000;i++)
    {
        arr[i]=rand();
    }
    auto start = high_resolution_clock::now();
    count=insertionSort(arr,n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<"the random time is:"<<duration.count()<<" Microseconds"<<endl;
    cout<<"The number of comparisons are:"<<count<<endl;
}