#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends

class Solution{
    public:
    
    long long ans = 0;
    void t(int n,int a , int c ,int b){
        if(n==1){
            ans++;
            cout<<"move disk 1 from rod "<<a<<" to rod "<<c<<endl;
            return ;
        }
        t(n-1,a,b,c);
        cout<<"move disk "<<n<<" from rod "<<a<<" to rod "<<c<<endl;
        ans++ ;
        t(n-1,b,c,a);
        
    }
    long long toh(int n,int a,int c, int b)
    {
        t(n,a,c,b);
        return ans;
    }
};

//{ Driver Code Starts.

int main() {

    int T;
    cin >> T;//testcases
    while (T--) {
        
        int N;
        cin >> N;//taking input N
        
        //calling toh() function
        Solution ob;
        
        cout << ob.toh(N, 1, 3, 2) << endl;
    }
    return 0;
}



// } Driver Code