#include <iostream>
#include<bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
int insertionSort(int arr[], int n) 
{ 
    int i, key, j; 
    int counter=0;
    //indices starting from 1
    for (i = 2; i < n; i++)
    { 
        if ((i+1) & 1 == 1)
        {
            key = arr[i]; 
            j = i - 2; 
            while (j >= 0 && arr[j] > key)
            { 
                arr[j + 2] = arr[j]; 
                j = j - 2;
                counter+=1; 
            } 
            arr[j + 2] = key; 
        }
    }
    return counter;  
} 
int main()
{
    int n=100;
    int arr[n];
    int count;
    srand(time(0));
    for (int i=0;i<100;i++)
    {
        arr[i]=rand();
    }
    cout<<"The unsorted array is:"<<endl;
    for (int i=0;i<100;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl<<endl;
    auto start = high_resolution_clock::now();
    count=insertionSort(arr,n);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<nanoseconds>(stop - start);
    cout<<"The sorted array is: indices starting from 1:"<<endl;
    for (int i=0;i<100;i++)
    {
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    cout<<"the random time is:"<<duration.count()<<" Microseconds"<<endl;
    cout<<"The number of comparisons are:"<<count<<endl;
}