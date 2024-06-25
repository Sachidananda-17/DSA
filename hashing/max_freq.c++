#include <iostream>
using namespace std;

int mostFrequent(int* arr, int n)
{
    int maxcount = 0;
    int element_having_max_freq;
    for (int i = 0; i < n; i++)
    {
        int count = 0;
        for (int j = 0; j < n; j++)
        {
            if (arr[i] == arr[j])
                count++;
        }

        if (count > maxcount)
        {
            maxcount = count;
            element_having_max_freq = arr[i];
        }
    }
    return element_having_max_freq;
}

int main()
{
    int n;
    cout << "Enter the number of elements: ";
    cin >> n;

    int arr[n]; // Declare the array properly
    cout << "Enter the elements:" << endl;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << "The most frequent element is: " << mostFrequent(arr, n) << endl;
    
    return 0; // Add return statement to main
}
