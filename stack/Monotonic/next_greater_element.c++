#include <iostream>
#include <vector>
#include <stack>
using namespace std;

vector<int> nextGreaterElements(vector<int>& arr) {
    int n = arr.size();
    vector<int> nge(n, -1);  // Result vector initialized with -1
    stack<int> st;  // Stack to store elements

    // Traverse the array from right to left
    for (int i = n - 1; i >= 0; i--) {
        // Pop elements from the stack until we find a greater element or the stack is empty
        while (!st.empty() && st.top() <= arr[i]) {
            st.pop();
        }

        // If the stack is not empty, the top element is the next greater element
        if (!st.empty()) {
            nge[i] = st.top();
        }

        // Push the current element onto the stack
        st.push(arr[i]);
    }

    return nge;
}

int main() {
    vector<int> arr = {4, 5, 2, 10, 8};
    vector<int> result = nextGreaterElements(arr);

    for (int i = 0; i < result.size(); i++) {
        cout << result[i] << " ";
    }

    return 0;
}




// time complexity --- o(2n)
// space complexity --- o(1)