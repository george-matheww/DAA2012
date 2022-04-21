#include <algorithm>
#include <chrono>
#include <iostream>
#include <string>
#include <vector>
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
void selection_sort(vector<Student> &arr, int count)
{
    int i, j, min;
    Student spare;
    for (i = 0; i < count-1; i++)
    {
        min = i;         //minimum element in unsorted array
        for (j = i+1; j < count; j++)
            if (arr[j].marks < arr[min].marks)
                min = j;
        //swap(arr[min_ind], arr[i]);// Swap the found minimum element with the first element
        spare= arr[min];
        arr[min]=arr[i];
        arr[i]=spare;
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
    vector<Student> arr(n);
    for (int i=0;i<n;i++){
        cout<<"Enter details of Student:"<<i+1<<endl;
        arr[i].input();}
    selection_sort(arr,n);
    cout<<"The sorted details of the students are:"<<endl;
    for(int i=0;i<n;i++){
        arr[i].outpu();}
    return 0; 
}