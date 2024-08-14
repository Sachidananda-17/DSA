// need to print  n length possible binary strings


#include<iostream>
using namespace std;

void generateBinaryStrings(int n)
{
    int totalStrings = 1 << n;
    for(int i=0;i<totalStrings; ++i)
    {
        string binaryString = "";
        for(int j = n -1; j>=0; --j)
        {
            binaryString +=((i &(1<<j))? '1' : '0');
        }
        cout<< binaryString<< "," ; 
    }
}

int main()
{
    int n ;
    cout<<"Enter the length of the Binary Strings: ";
    cin>>n;

    generateBinaryStrings(n);
    return 0;
}