#include<iostream>
using namespace std;

int abs(int n) {
    if (n < 0) {
        return -1 * n;
    } else {
        return n;
    }
}

int main() {
    int n;
    cout << "Enter the number: ";
    cin >> n;
    cout << "The absolute value of " << n << " is " << abs(n);
    return 0;
}
