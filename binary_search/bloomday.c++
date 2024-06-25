/*
Blloming days - amazon question: the question is about the finding the number days that would be required to form the boque with the no of flowers each.
Note: the selected flowers for the botique has to be consecutive in the array
the elements in the array given will be no of days required to bloom the flower.
m - boquews
k - no  of flowers in boque
*/
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int minDays(vector<int>& bloomDay, int m, int k) {
        if ((long long)m * k > bloomDay.size()) {
            return -1;
        }

        int low = 1, high = *max_element(bloomDay.begin(), bloomDay.end());
        while (low < high) {
            int mid = low + (high - low) / 2;

            if (canMakeBouquets(bloomDay, m, k, mid)) {
                high = mid;
            } else {
                low = mid + 1;
            }
        }

        return low;
    }

private:
    bool canMakeBouquets(vector<int>& bloomDay, int m, int k, int day) {
        int total = 0;
        for (int i = 0; i < bloomDay.size(); i++) {
            int count = 0;
            while (i < bloomDay.size() && count < k && bloomDay[i] <= day) {
                count++;
                i++;
            }

            if (count == k) {
                total++;
                i--; // Adjust index since the outer loop will also increment it.
            }

            if (total >= m) {
                return true;
            }
        }

        return false;
    }
};

int main() {
    Solution sol;
    vector<int> bloomDay = {1, 10, 3, 10, 2};
    int m = 3, k = 1;

    cout << "Minimum number of days: " << sol.minDays(bloomDay, m, k) << endl;

    return 0;
}
