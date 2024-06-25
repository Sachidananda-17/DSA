/*
    Given an integer x, the task is to compute the floor value of the square root of x.
    The floor value of a square root is the greatest integer that is less than or equal
    to the square root of the number.

    Example:
    Input:  5
    Output: 2

    Input:  9
    Output: 3
*/




#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minEatingSpeed(vector<int>& piles, int h) {
        // Initialize the lower bound of the search range
        int low = 1;
        // Initialize the upper bound of the search range to the maximum bananas in a pile
        int high = *max_element(piles.begin(), piles.end());
        
        // Result variable to store the minimum eating speed
        int res = high;

        // Binary search for the minimum feasible eating speed
        while (low <= high) {
            // Middle point of the current search range
            int k = low + (high - low) / 2;
            long int hours = 0;

            // Calculate total hours needed to eat all bananas with speed k
            for (int i = 0; i < piles.size(); i++) {
                hours += ceil((double)piles[i] / k);
            }

            // If Koko can eat all bananas within h hours with speed k
            if (hours <= h) {
                // Update result and search for a smaller feasible speed
                res = min(res, k);
                high = k - 1;
            } else {
                // Otherwise, search for a larger speed
                low = k + 1;
            }
        }

        // Return the minimum feasible eating speed
        return res;
    }
};

int main() {
    // Example input
    vector<int> piles = {3, 6, 7, 11};
    int h = 8;

    // Create an instance of Solution
    Solution solution;

    // Get the minimum eating speed
    int result = solution.minEatingSpeed(piles, h);

    // Output the result
    cout << "Minimum eating speed: " << result << endl;

    return 0;
}
