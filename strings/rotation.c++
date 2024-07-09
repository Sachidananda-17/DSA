/*
Rotation of a string to check whether it will be equal to the goal string or not?

*/

#include <iostream>
#include <string>
using namespace std;

// Function to check if one string can be rotated to become another
bool rotateString(const string& s, const string& goal) {
    int length = s.length();
    
    // If lengths are different, return false
    if (length != goal.length()) {
        return false;
    }
    
    // Iterate through possible rotations of string s
    for (int i = 0; i < length; i++) {
        string rotated = s.substr(i) + s.substr(0, i); // Create rotated string
        
        // Check if rotated string matches goal
        if (rotated == goal) {
            return true;
        }
    }
    
    // If no rotation matches goal, return false
    return false;
}

int main() {
    string s, goal;

    // Input strings from user
    cout << "Enter the first string (s): ";
    cin >> s;
    cout << "Enter the second string (goal): ";
    cin >> goal;

    // Check if s can be rotated to become goal
    if (rotateString(s, goal)) {
        cout << "Yes, '" << s << "' can be rotated to become '" << goal << "'." << endl;
    } else {
        cout << "No, '" << s << "' cannot be rotated to become '" << goal << "'." << endl;
    }

    return 0;
}
