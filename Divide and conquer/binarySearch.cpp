#include <iostream>
using namespace std;
int binarySearch(int arr[], int left, int right, int key)
{
    if (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == key)
        {
            return mid;
        }
        if (arr[mid] < key)
        {
            return binarySearch(arr, mid + 1, right, key); // Return the result of recursive call
        }
        else
        {
            return binarySearch(arr, left, mid - 1, key); // Return the result of recursive call
        }
    }
    return -1;
}

int main()
{
    int arr[] = {2, 5, 7, 9, 12, 15, 17};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 12;
    int result = binarySearch(arr, 0, size - 1, key);

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