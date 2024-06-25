#include<iostream>
using namespace std;

int countDigit(long long n)
{
    if (n==0)
    return 1;
    int count = 0;
    while (n!= 0){
        n = n/10;
        ++count;
    }
    return count;
}

int main()
{
    long long n ;
    cout<<"enter the number";
    cin>>n;
    cout << "Number of digits : " << countDigit(n);
    return 0;
}