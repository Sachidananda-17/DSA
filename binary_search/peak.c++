// peak element finding  :- peak element is the element who satisfies the cond'n | a[n-1] < a[n] > a[n+1] |

#include <iostream>
#include <vector>
using namespace std;

int peak(vector<int>& arr) {
    int n = arr.size();
    if (n == 1) return 0;
    if (arr[0] > arr[1]) return 0;
    if (arr[n - 1] > arr[n - 2]) return n - 1;

    int low = 1, high = n - 2;
    while (low <= high) {
        int mid = (low + high) / 2;
        if (arr[mid] > arr[mid - 1] && arr[mid] > arr[mid + 1]) return mid;
        else if (arr[mid] > arr[mid - 1]) {
            low = mid + 1;
        } else {
            high = mid - 1;
        }
    }
    return -1;
}

int main() {
    vector<int> arr = {1, 2, 3, 6, 8, 9, 6};
    cout << "The peak element is at index: " << peak(arr) << endl;
    return 0;
}
