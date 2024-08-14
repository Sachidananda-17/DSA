#include <iostream>
#include <string>
#include <algorithm> // for reverse
using namespace std;

string int_2_binary(int x) {
    if (x == 0) return "0"; // Handle the case where x is 0
    
    string res = "";
    while (x > 0) {
        if (x % 2 == 0) {
            res += '0';
        } else {
            res += '1';
        }
        x = x / 2;
    }
    reverse(res.begin(), res.end()); // Reverse the string to get the correct binary representation
    return res;
}

int main() {
    int n;
    cin >> n;
    string binary_representation = int_2_binary(n);
    cout << binary_representation << endl; // Print the result
    return 0;
}
