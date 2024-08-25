#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main()
{
    vector<int> arr;
    int n; 
    cin >> n;
    arr.resize(n);

    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }

    int k; 
    cin >> k;

    if(k > n) {
        cout << "Error: Window size cannot be greater than the number of elements." << endl;
        return 1; // Exit the program
    }

    int largest_sum = INT_MIN;
    int sum = 0;

    for(int i = 0; i < k; i++) {
        sum += arr[i];
    }

    largest_sum = sum; 

    for(int i = k; i < n; i++) {
        sum += arr[i] - arr[i - k];
        largest_sum = max(largest_sum, sum);
    }

    cout << largest_sum << endl;

    return 0;
}
