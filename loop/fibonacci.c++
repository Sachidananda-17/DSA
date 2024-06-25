#include<iostream>
using namespace std;
int fibonacci(int l )
{
    int a = 0 ;
    int b = 1;
    int c ;
    if ( l == 0 || l == 1)
    {
        cout<<"the " << l <<" th place fibonacci number is " << " 1";

    }

    else 
    {
        for ( int i=2;i<=l;i++)
        {
            c = a + b ;
            a=b;
            b=c;

            

        }
        cout<< b<<endl;
        
    }


}
int main()
{
    int x ; 
    cout<<"enter the fibonacci number";
    cin>>x;
    fibonacci(x);
    return 0;

}
