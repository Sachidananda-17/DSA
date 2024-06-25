// #include<bits/c++.h>
#include<iostream>
using namespace std;
largest_element(int arr[], int n)
{
    int max = arr[0];
    for (int i = 1; i< n ; i++)
    { 
        if (arr[i] > max);
        {
            max = arr[i];
            
        }

         
        
    }
    cout<<max<<endl;
   
}

    int main()
    {
        cout<< " enter thhe number of elements ";
        int n , arr[100];
        cin>>n;
        cout << "enter the elements of the array";
        for ( int i=0; i<n; i++)
        {
            cin>>arr[i];
        }

        cout<<"largest element in the array is ";
        largest_element(arr,n);
        return 0;
    }


