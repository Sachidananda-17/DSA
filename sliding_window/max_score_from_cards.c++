/*
will be given a vector and the window size need to find the sum with the window size and return the max score

-- the elements with in window size need to selected in such a manner the elements has to be conscecutive in a circular manner ( continue in nature )
*/


#include <iostream>
#include <vector>
using namespace std;

int max_score(vector<int>& cardPoints, int k) {
    int n = cardPoints.size();
    int lsum = 0, rsum = 0;

    // Calculate the sum of the first k elements (leftmost elements)
    for (int i = 0; i < k; i++) {
        lsum += cardPoints[i];
    }

    int max_Sum = lsum;

    // Now, start removing elements from the left and adding from the right
    for (int i = 0; i < k; i++) {
        lsum -= cardPoints[k - 1 - i]; // Remove from left
        rsum += cardPoints[n - 1 - i]; // Add from right

        max_Sum = max(max_Sum, lsum + rsum); // Update the maximum score
    }

    return max_Sum;
}

int main() {
    vector<int> arr = {1, 2, 3, 4, 5, 6, 8};

    int k;
    cout << "Enter the window size: ";
    cin >> k;

    int result = max_score(arr, k);
    cout << "The maximum score is: " << result << endl;

    return 0;
}
