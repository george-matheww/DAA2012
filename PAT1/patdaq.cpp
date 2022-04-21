#include <bits/stdc++.h>
using namespace std;
int missing_element(int arrayofintegers[],int numberofelements)
{
    int bottomhalf=0,upperhalf=numberofelements-1;
    int difference = (arrayofintegers[upperhalf]-arrayofintegers[bottomhalf])/numberofelements;
    while (bottomhalf <= upperhalf)
    {
        int half = upperhalf-(upperhalf-bottomhalf)/2;
        if ((half+1 < numberofelements) && ((arrayofintegers[half+1]-arrayofintegers[half])!=difference))
        {
            return arrayofintegers[half]+difference;
        }
        if ((half-1 > 0) && ((arrayofintegers[half]-arrayofintegers[half-1])!=difference))
        {
            return arrayofintegers[half]-difference;
        }
        if ((arrayofintegers[half] - arrayofintegers[0]) != half * difference){
            upperhalf = half - 1;
        }
        else {
            bottomhalf = half + 1;
        }
    }
}
int main()
{
    int n;
    cout<<"enter the number of elements\n";
    cin>>n;
    int arr[n];
    for (int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    cout<<"the missing element is:"<<missing_element(arr,n);
    return 0;
}