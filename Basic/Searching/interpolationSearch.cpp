#include <iostream>

// Function to perform interpolation search
int interpolationSearch(int arr[], int size, int key)
{
    int low = 0;
    int high = size - 1;

    while (low <= high && key >= arr[low] && key <= arr[high])
    {
        // Calculate the position using interpolation formula
        int pos = low + ((double)(high - low) / (arr[high] - arr[low])) * (key - arr[low]);

        // If key is found
        if (arr[pos] == key)
        {
            return pos;
        }

        // If key is smaller, ignore the right half
        if (arr[pos] < key)
        {
            low = pos + 1;
        }

        // If key is larger, ignore the left half
        else
        {
            high = pos - 1;
        }
    }

    return -1; // If key is not found
}

int main()
{
    int arr[] = {2, 5, 7, 9, 12, 15, 17};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 12;

    int result = interpolationSearch(arr, size, key);

    if (result != -1)
    {
        std::cout << "Element found at index: " << result << std::endl;
    }
    else
    {
        std::cout << "Element not found in the array." << std::endl;
    }

    return 0;
}
