#include<iostream>
using namespace std;
sorted ( int n , int arr[])
{
    int  i =0;
     if (arr[i] >= arr[i+1])
        {
            cout<<"true";
        }
        else 
        {
            cout<<"false";
        }


}

int main()
{
    int  n , arr[100];
    cout<<"enter the number of elements"<<endl;
    cin>>n;
    cout<<"enter the elements"<<endl;
    for ( int  i=0; i<n; i++)
    {
        cin>>arr[i];
    }
    sorted(n,arr);
    return 0 ;

}