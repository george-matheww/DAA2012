#include <iostream>
#include<bits/stdc++.h>
using namespace std;
class Student{
    public:
    char name[15];
    int regno;
    int marks;
    void input();
    void outpu();
};
void Student::input()
{
    cin>>name;
    cin>>regno;
    cin>>marks;
}
void selectionSort(Student arr[], int n)
{
    Student temp;//temporary object for switching
    int i, j, min;
    // One by one move boundary of unsorted subarray
    for (i = 0; i < n-1; i++)
    {
        // Find the minimum element in unsorted array
        min = i;
        for (j = i+1; j < n; j++)
            if (arr[j].marks < arr[min].marks)
                min = j;
        temp=arr[min];
        arr[min]=arr[i];
        arr[i]=temp;
    }
}
void Student::outpu()
{
    cout<<name<<" "<<regno<<" "<<marks<<endl;
}
int main()
{
    int n;
    cout<<"Number of students:";
    cin>>n;
    Student arr[n];
    for (int i=0;i<n;i++){
        cout<<"Enter details of Student:"<<i+1<<endl;
        arr[i].input();}
    selectionSort(arr,n);
    cout<<"The sorted details of the students are:"<<endl;
    for (int i=0;i<n;i++)
        arr[i].outpu();
}