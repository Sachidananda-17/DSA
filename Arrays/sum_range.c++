#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n;
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    // Input array elements
    vector<int> arr(n);
    cout << "Enter " << n << " elements of the array:\n";
    for (int i = 0; i < n; ++i) {
        cin >> arr[i];
    }

    int q;
    cout << "Enter the number of queries: ";
    cin >> q;

    // Process queries
    for (int i = 0; i < q; ++i) {
        int start, end;
        cout << "Enter start and end indices for query " << i + 1 << ": ";
        cin >> start >> end;

        if (start < 0 || end >= n || start > end) {
            cout << "Invalid query!\n";
            continue;
        }

        // Calculate sum of elements from start to end
        int sum = 0;
        for (int j = start; j <= end; ++j) {
            sum += arr[j];
        }

        cout << "Sum of elements from index " << start << " to " << end << " is: " << sum << endl;
    }

    return 0;
}
