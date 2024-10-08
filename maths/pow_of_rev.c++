// This C++ program calculates the power of a number raised to its reverse for multiple test cases, with results modulo 1000000007.


#include <bits/stdc++.h>
using namespace std;

class Solution {
public:
    long long power(int N, int R) {
        const int MOD = 1000000007;

        long long result = 1;
        N = N % MOD;

        while (R > 0) {
            if (R % 2 == 1) {
                result = (result * N) % MOD;
            }

            long long temp = static_cast<long long>(N) * N;
            N = temp % MOD;
            R = R / 2;
        }

        return result;
    }
};

// compute reverse of a number 
long long rev(long long n) {
    long long rev_num = 0;
    while (n > 0) { 
        rev_num = rev_num * 10 + n % 10; 
        n = n / 10; 
    } 
    return rev_num;
}

int main() {
    int T;
    cin >> T; // testcases
    
    while (T--) {
        long long N;
        cin >> N; // input N
        
        long long R = 0; 
        
        // reverse the given number n
        R = rev(N);
        Solution ob;
        
        // power of the number to its reverse
        long long ans = ob.power(N, R);
        cout << ans << endl;
    }

    return 0;
}
