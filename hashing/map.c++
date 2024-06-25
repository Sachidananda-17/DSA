// use to map function rather than hashing to avoide space complexity

#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cout<<"enter the number of elements"<<endl;
    cin>>n;
    int arr[n];
    cout<<"enter the elements "<<endl;
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];

    }
    // pre-compute
    map<int ,int>mpp;
    for(int i=0;i<n;i++)
    {
        mpp[arr[i]]++;
    }

    // map stores values in the sorted order
    for(auto it: mpp)
    {
        cout<<it.first<<"->"<<it.second<<endl;
    }
    int q;
    cout<<"enter the num of queries"<<endl;
    cin>>q;
    while(q--)
    {
        int number;
        cin>>number;
        // fetch
        cout<<mpp[number]<<endl;
    }
    return 0;
}
