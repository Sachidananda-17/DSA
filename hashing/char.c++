#include<iostream>
using namespace std;
 int main()
 {
    string s;
    cout<<"enter the string";
    cin>>s;

    // precompute

    int  hash[26] = {0};
    for(int i=0 ; i<s.size() ; i++)
    {
        hash[s[i] - 'a'] ++ ;
    }
    cout<<"enter the no of  queries";
    int q; 
    cin>>q;
    cout<<"enter the queries";
    while( q--)
    {
        char c;
        cin>>c;
        // fetch

        cout << hash[c-'a'] <<endl;
    }

    return 0;
    


 }