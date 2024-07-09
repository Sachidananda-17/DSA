/*
isomorphic strings
*/


#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    bool isIsomorphic(string s, string t) {
        vector<int> indexS(256, 0);  
        vector<int> indexT(256, 0);  
        
        int len = s.length();  
        
        if (len != t.length()) {  
            return false;
        }
        
        for (int i = 0; i < len; i++) {
            if (indexS[s[i]] != indexT[t[i]]) {  
                return false;
            }
            
            indexS[s[i]] = i + 1;  
            indexT[t[i]] = i + 1;  
        }
        
        return true;  
    }
};

int main() {
    Solution sol;
    string s, t;
    
    
    cout << "Enter the first string: ";
    cin >> s;
    cout << "Enter the second string: ";
    cin >> t;
    
    
    cout << "Are '" << s << "' and '" << t << "' isomorphic? " << (sol.isIsomorphic(s, t) ? "Yes" : "No") << endl;
    
    return 0;
}
