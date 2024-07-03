#include <iostream>
#include <vector>
using namespace std;

string removeOuterParentheses(string s) {
    string result;
    int balance = 0;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == '(') {
            if (balance > 0) {
                result += s[i];
            }
            balance++;
        } else {
            balance--;
            if (balance > 0) {
                result += s[i];
            }
        }
    }
    return result;
}

int main() {
    vector<string> st;
    int n;
    cout << "Enter the number of strings: ";
    cin >> n;
    cin.ignore(); // To ignore the newline character after the number input

    cout << "Enter the strings:" << endl;
    for (int i = 0; i < n; i++) {
        string temp;
        getline(cin, temp);
        st.push_back(temp);
    }

    for (const string &s : st) {
        cout << removeOuterParentheses(s) << endl;
    }

    return 0;
}
