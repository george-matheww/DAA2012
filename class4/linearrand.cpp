// C++ implementation of the approach
#include <limits.h>
#include <iostream>
#include <bits/stdc++.h>
#include <chrono>
using namespace std;
using namespace std::chrono;
struct Node {
	long long _max;
	long long _pre;
	long long _suf;
	long long _sum;
};
Node getNode(long long x){
	Node a;
	a._max = x;
	a._pre = x;
	a._suf = x;
	a._sum = x;
	return a;
}
Node merg(const Node &l, const Node &r){
	Node ans ;
	ans._max = ans._pre = ans._suf = ans._sum = 0;
	ans._pre = max({l._pre, l._sum+r._pre, l._sum+r._sum});
	ans._suf = max({r._suf, r._sum+l._suf, l._sum+r._sum});
	ans._sum = l._sum + r._sum;
	ans._max = max({ans._pre, ans._suf, ans._sum,l._max, r._max, l._suf+r._pre});
	return ans;
}
Node getMaxSumSubArray(int l, int r, vector<long long> &ar){
	if (l == r) return getNode(ar[l]);
	int mid = (l + r) >> 1;
	Node left = getMaxSumSubArray(l, mid, ar);
	Node right = getMaxSumSubArray(mid+1, r, ar);
	return merg(left, right);
}

int main(){
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

    auto start = high_resolution_clock::now();
	Node ans = getMaxSumSubArray(0, n1-1, ar);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    cout<<"The MaxSubArraySum1:"<<ans._max<<"\n"<<"The duration1 is:"<<duration.count()<<" Microseconds"<<endl<<endl;
	
    auto start2 = high_resolution_clock::now();
	Node ans2 = getMaxSumSubArray(0, n2-1, ar2);
    auto stop2 = high_resolution_clock::now();
    auto duration2 = duration_cast<microseconds>(stop2 - start2);
    cout<<"The MaxSubArraySum2:"<<ans2._max<<"\n"<<"The duration2 is:"<<duration2.count()<<" Microseconds"<<endl<<endl;

    auto start3 = high_resolution_clock::now();
	Node ans3 = getMaxSumSubArray(0, n3-1, ar3);
    auto stop3 = high_resolution_clock::now();
    auto duration3 = duration_cast<microseconds>(stop3 - start3);
    cout<<"The MaxSubArraySum3:"<<ans3._max<<"\n"<<"The duration3 is:"<<duration3.count()<<" Microseconds"<<endl<<endl;

    auto start4 = high_resolution_clock::now();
	Node ans4 = getMaxSumSubArray(0, n4-1, ar4);
    auto stop4 = high_resolution_clock::now();
    auto duration4 = duration_cast<microseconds>(stop4 - start4);
    cout<<"The MaxSubArraySum4:"<<ans4._max<<"\n"<<"The duration4 is:"<<duration4.count()<<" Microseconds"<<endl<<endl;

    auto start5 = high_resolution_clock::now();
	Node ans5 = getMaxSumSubArray(0, n5-1, ar5);
    auto stop5 = high_resolution_clock::now();
    auto duration5 = duration_cast<microseconds>(stop5 - start5);
    cout<<"The MaxSubArraySum5:"<<ans5._max<<"\n"<<"The duration5 is:"<<duration5.count()<<" Microseconds"<<endl<<endl;

    auto start6 = high_resolution_clock::now();
	Node ans6 = getMaxSumSubArray(0, n6-1, ar6);
    auto stop6 = high_resolution_clock::now();
    auto duration6 = duration_cast<microseconds>(stop6 - start6);
    cout<<"The MaxSubArraySum6:"<<ans6._max<<"\n"<<"The duration6 is:"<<duration6.count()<<" Microseconds"<<endl<<endl;

    auto start7 = high_resolution_clock::now();
	Node ans7 = getMaxSumSubArray(0, n7-1, ar7);
    auto stop7 = high_resolution_clock::now();
    auto duration7 = duration_cast<microseconds>(stop7 - start7);
    cout<<"The MaxSubArraySum7:"<<ans7._max<<"\n"<<"The duration7 is:"<<duration7.count()<<" Microseconds"<<endl<<endl;
	return 0;
}
