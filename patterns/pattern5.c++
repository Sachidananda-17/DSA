/*
pattern 5


* * * * *
* * * * 
* * * 
* * 
* 


*/

#include<iostream>
using namespace std;
int main()
{
    int n;
    cout<<"enter the value of n"<<endl;
    cin>>n;
    for(int i=1;i<=n;i++)
    {
        for(int j=0; j <=n-i+1; j++)
        {
            cout<<"* ";
        }

        cout<<endl;
    }

}