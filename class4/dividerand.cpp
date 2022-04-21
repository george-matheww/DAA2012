#include <limits.h>
#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
int max(int a, int b) { return (a > b) ? a : b; }
int max(int a, int b, int c) { return max(max(a, b), c); }
int maxCrossingSum(int arr[], int l, int m, int h)
{
    int sum = 0;
    int left_sum = INT_MIN;
    for (int i = m; i >= l; i--) {
        sum = sum + arr[i];
        if (sum > left_sum)
            left_sum = sum;
    }
    sum = 0;
    int right_sum = INT_MIN;
    for (int i = m + 1; i <= h; i++) {
        sum = sum + arr[i];
        if (sum > right_sum)
            right_sum = sum;
    }
    return max(left_sum + right_sum, left_sum, right_sum);
}
int maxSubArraySum(int arr[], int l, int h)
{
    if (l == h)
        return arr[l];
    int m = (l + h) / 2;
    return max(maxSubArraySum(arr, l, m),
               maxSubArraySum(arr, m + 1, h),
               maxCrossingSum(arr, l, m, h));
}
int main()
{
    int n1=100,n2=1000,n3=10000,n4=50000,n5=100000,n6=500000,n7=1000000;
    vector<long long> ar(n1);
    auto f = []() -> int { return rand() % 100; };
    generate(ar.begin(), ar.end(), f);
    vector<long long> ar2(n2);
    auto g = []() -> int { return rand() % 1000; };
    generate(ar2.begin(), ar2.end(), g);
    vector<long long> ar3(n3);
    auto h = []() -> int { return rand() % 10000; };
    generate(ar3.begin(), ar3.end(), h);
    vector<long long> ar4(n4);
    auto i = []() -> int { return rand() % 50000; };
    generate(ar4.begin(), ar4.end(), i);
    vector<long long> ar5(n5);
    auto j = []() -> int { return rand() % 100000; };
    generate(ar5.begin(), ar5.end(), j);
    vector<long long> ar6(n6);
    auto k = []() -> int { return rand() % 500000; };
    generate(ar6.begin(), ar6.end(), k);
    vector<long long> ar7(n7);
    auto l = []() -> int { return rand() % 1000000; };
    generate(ar7.begin(), ar7.end(), l);
    int arr1[ar.size()];
    int arr2[ar2.size()];
    int arr3[ar3.size()];
    int arr4[ar4.size()];
    int arr5[ar5.size()];
    int arr6[ar6.size()];
    int arr7[ar7.size()];
    for(int i = 0; i < ar.size(); i++){
        arr1[i] = ar[i];}
    for(int i = 0; i < ar2.size(); i++){
        arr2[i] = ar2[i];}
    for(int i = 0; i < ar3.size(); i++){
        arr3[i] = ar3[i];}
    for(int i = 0; i < ar4.size(); i++){
        arr4[i] = ar4[i];}
    for(int i = 0; i < ar5.size(); i++){
        arr5[i] = ar5[i];}
    for(int i = 0; i < ar6.size(); i++){
        arr6[i] = ar6[i];}
    for(int i = 0; i < ar7.size(); i++){
        arr7[i] = ar7[i];}

    auto start = high_resolution_clock::now();
    int max_sum1 = maxSubArraySum(arr1, 0, n1 - 1);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<"The MaxSubArraySum1:"<<max_sum1<<"\n"<<"The duration1 is:"<<duration.count()<<" Microseconds"<<endl<<endl;
    
    auto start2 = high_resolution_clock::now();
    int max_sum2 = maxSubArraySum(arr2, 0, n2 - 1);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout<<"The MaxSubArraySum2:"<<max_sum2<<"\n"<<"The duration2 is:"<<duration2.count()<<" Microseconds"<<endl<<endl;
    
    auto start3 = high_resolution_clock::now();
    int max_sum3 = maxSubArraySum(arr3, 0, n3 - 1);
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(stop3 - start3);
    cout<<"The MaxSubArraySum3:"<<max_sum3<<"\n"<<"The duration3 is:"<<duration3.count()<<" Microseconds"<<endl<<endl;
    
    auto start4= high_resolution_clock::now();
    int max_sum4 = maxSubArraySum(arr4, 0, n4 - 1);
    auto stop4 = high_resolution_clock::now();
    auto duration4 = duration_cast<microseconds>(stop4 - start4);
    cout<<"The MaxSubArraySum4:"<<max_sum4<<"\n"<<"The duration4 is:"<<duration4.count()<<" Microseconds"<<endl<<endl;
    
    auto start5= high_resolution_clock::now();
    int max_sum5 = maxSubArraySum(arr5, 0, n5 - 1);
    auto stop5 = high_resolution_clock::now();
    auto duration5 = duration_cast<microseconds>(stop5 - start5);
    cout<<"The MaxSubArraySum5:"<<max_sum5<<"\n"<<"The duration5 is:"<<duration5.count()<<" Microseconds"<<endl<<endl;
    
    auto start6= high_resolution_clock::now();
    int max_sum6 = maxSubArraySum(arr6, 0, n6 - 1);
    auto stop6 = high_resolution_clock::now();
    auto duration6 = duration_cast<microseconds>(stop6 - start6);
    cout<<"The MaxSubArraySum6:"<<max_sum6<<"\n"<<"The duration6 is:"<<duration6.count()<<" Microseconds"<<endl<<endl;
    
    auto start7= high_resolution_clock::now();
    int max_sum7 = maxSubArraySum(arr7, 0, n7 - 1);
    auto stop7 = high_resolution_clock::now();
    auto duration7 = duration_cast<microseconds>(stop7 - start7);
    cout<<"The MaxSubArraySum7:"<<max_sum7<<"\n"<<"The duration7 is:"<<duration7.count()<<" Microseconds"<<endl<<endl;
    return 0;
}