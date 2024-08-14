#include <iostream>
#include <string>
using namespace std;

int binary_2_decimal(string x) {
    int len = x.length(), p2 = 1, num = 0;
    for (int i = len - 1; i >= 0; i--) {
        if (x[i] == '1') {
            num = num + p2;
        }
        p2 = p2 * 2;
    }
    return num;
}

int main() {
    string x;
    cin >> x;
    int decimal_value = binary_2_decimal(x);
    cout << decimal_value << endl; // Print the result
    return 0;
}
