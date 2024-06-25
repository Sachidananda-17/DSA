#include<iostream>
#include<vector>
using namespace std;

int rotated(const vector<int>& v, int x)
{
    int low = 0; 
    int high = v.size() - 1;

    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (v[mid] == x)
        {
            return mid;
        }

        // Determine which side is properly sorted
        if (v[low] <= v[mid]) // Left side is sorted
        {
            if (v[low] <= x && x < v[mid])
            {
                high = mid - 1; // Target is in the left half
            }
            else
            {
                low = mid + 1; // Target is in the right half
            }
        }
        else // Right side is sorted
        {
            if (v[mid] < x && x <= v[high])
            {
                low = mid + 1; // Target is in the right half
            }
            else
            {
                high = mid - 1; // Target is in the left half
            }
        }
    }

    return -1; // Target not found
}

int main()
{
    vector<int> v = {3, 4, 5, 6, 7, 1, 2};
    int x = 6;
    int index = rotated(v, x);

    if (index != -1)
    {
        cout << "Element found at index " << index << endl;
    }
    else
    {
        cout << "Element not found" << endl;
    }

    return 0;
}
