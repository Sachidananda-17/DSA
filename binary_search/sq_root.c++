#include<iostream>
using namespace std;

int sq(int x) {
    int ans = 0;
    int low = 0, high = x;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (mid * mid == x) {
            return mid;
        }
        if (mid * mid < x) {
            low = mid + 1;
            ans = mid;
        } else {
            high = mid - 1;
        }
    }
    return ans;
}

int main() {
    int x;
    cin >> x;
    cout << sq(x) << endl;  
    return 0;
}
