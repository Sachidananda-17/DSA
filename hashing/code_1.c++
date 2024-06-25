// take the arry as input and number whose frequency has to be checked and print the output

#include<iostream>
using namespace std;

int main()
{

    int n;
    cin>>n;
    int  arr[n];
    cout<<"enter the elements";
    for(int i=0;i<n; i++)
    {
        cin>>arr[i];
    }

    // precompute

    int hash[13] = {0};
    for ( int i=0 ; i<n;i++)
    {
        hash[arr[i]] +=1;
    }


    int q;
    cout<<"enter the number of queries";
    cin>>q;
    cout<<"enther the numbers";

    while ( q--)
    {
        int number;
        cin>>number;
        // fetch
        cout<<hash[number]<<endl;
    }

    return 0;


}
