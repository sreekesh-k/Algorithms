#include <iostream>

using namespace std;
// Function to perform linear search
int linearSearch(int arr[], int size, int key)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == key)
        {
            return i; // Return the index if key is found
        }
    }
    return -1; // Return -1 if key is not found
}

int main()
{
    int arr[] = {2, 5, 7, 9, 12, 15, 17};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 12;

    int result = linearSearch(arr, size, key);

    if (result != -1)
    {
        cout << "Element found at index: " << result << endl;
    }
    else
    {
        cout << "Element not found in the array." << endl;
    }

    return 0;
}
