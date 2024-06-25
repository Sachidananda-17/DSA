#include <iostream>
#include <vector>
#include <climits> // Include this for INT_MAX
using namespace std;

int findMin(vector<int> &arr)
{
    int low = 0, high = arr.size() - 1;
    int ans = INT_MAX;
    
    while (low <= high)
    {
        int mid = (low + high) / 2;
        
        // If the subarray is already sorted, the minimum is the first element
        if (arr[low] <= arr[mid])
        {
            ans = min(ans, arr[low]);
            low = mid + 1;
        }
        else
        {
            // If the subarray is not sorted, then the minimum is in the left half
            high = mid - 1;
            ans = min(ans, arr[mid]);
        }
    }
    return ans;
}

int main()
{
    vector<int> arr = {4, 5, 6, 7, 1, 2, 3};
    int result = findMin(arr);
    cout << "The minimum element is: " << result << endl;
    return 0;
}
