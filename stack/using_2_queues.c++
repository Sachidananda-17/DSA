#include <bits/stdc++.h>
using namespace std;

class Stack {
    int N;
    queue<int> q1;
    queue<int> q2;
public:
    Stack() {
        N = 0;
    }
    
    void push(int val) {
        q2.push(val);
        N++;
        while (!q1.empty()) {
            q2.push(q1.front());
            q1.pop();
        }
        // Swap q1 and q2
        queue<int> temp = q1;
        q1 = q2;
        q2 = temp;
    }

    void pop() {
        if (!q1.empty()) {
            q1.pop();
            N--;
        }
    }

    int top() {
        if (!q1.empty()) {
            return q1.front();
        }
        return -1; // Return an error value or handle error as needed
    }

    int size() {
        return N;
    }
};

int main() {
    Stack st;
    st.push(1);
    st.push(2);
    st.push(3);
    st.push(4);
    st.push(5);
    cout << st.top() << endl; // Should print 5
    st.pop();
    cout << st.top() << endl; // Should print 4
    st.pop();
    cout << st.top() << endl; // Should print 3
    return 0;
}
