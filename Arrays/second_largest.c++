#include<iostream>
using namespace std;

second_largest ( int arr[], int n)
{
 int largest = arr[0];
 for (int i = 1 ; i< n ; i++)
 {
    if (arr[i] > largest)
    {
        largest = arr[i];
    }
 }
 cout<<"the largest elements in the array is"<<largest<<endl;

  int res = -1;
  for ( int i = 0 ; i <n; i++)
  {
    if ( arr[i]!=largest)
    {
        if(res==-1)
        res =i;
    }
    else if ( arr[i] > arr[res])
    res = i;
  }

  cout<<"the second largest element in the array is"<<res<<endl;
  return res;



}


int main()
{
    int n,arr[100];
    cout<<"enther the number of elements";
    cin>>n;
    cout<<"enter the elements of the array";
    for(int i=0;i<n;i++)
    {
        cin>>arr[i];
    }
    second_largest(arr,n);
    return 0;

}