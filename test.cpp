#include <algorithm>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

class Student{
    public:
        string name;
        char regno[9];
        int marks;
};

void selection_sort(Student arr[], int n)
{
    int i, j, min_ind;
    //int temp;
    for (i = 0; i < n-1; i++)
    {
        min_ind = i;         //minimum element in unsorted array
        for (j = i+1; j < n; j++)
        if (arr[j].marks < arr[min_ind].marks)
            min_ind = j;
    
        swap(arr[min_ind], arr[i]);// Swap the found minimum element with the first element
        /*
        temp= arr[min_ind].marks;
        arr[min_ind].marks=arr[i].marks;
        arr[i].marks=temp;
        */
    }
}

int main() 
{ 
    Student arr[5];
    cout<<"Taking input for 5 students\n"<<endl;
    for(int i=0;i<5;i++){
        cout<<"Enter Student name: ";
        cin>>arr[i].name;
        cout<<"Enter Student registration number: ";
        cin>>arr[i].regno;
        cout<<"Enter Student marks: ";
        cin>>arr[i].marks;
        cout<<endl;
    }
    
    selection_sort(arr,5);
    
    cout<<"\nThe details of the students are as follows: "<<endl;
    
    for(int i=0;i<5;i++){
        cout<< "\nStudent name: "<<arr[i].name;
        cout<<"\nStudent registration number: "<<arr[i].regno;
        cout<<"\nStudent marks: "<<arr[i].marks<<endl;
    }

    return 0; 
}