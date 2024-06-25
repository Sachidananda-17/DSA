/*
pattern 2 

*
* *
* * *  
* * * *
* * * * *

*/

#include<iostream>
using namespace std;


int  pattern(int n)
{
    for(int i=0;i<n;i++)
    {
        for(int j=0; j<=i;j++)
        {
            cout<<"* ";
        }
        cout<<endl;
    }
    return 0;
}
int main()
{
    int n;
    cout<<"enter the n"<<endl;
    cin>>n;
    pattern(n);
    return 0;
}