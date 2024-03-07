#include <iostream>
#include <vector>

using namespace std;

// partition the array using the last element as pivot
int partition(vector<int> &arr, int left, int right)
{
    int pivot = arr[left];
    int l = left + 1, r = right;
    while (l < r)
    {
        while (arr[l] <= pivot)
            l++;
        while (arr[r] >= pivot)
            r--;
        if (l < r)
        {
            int temp = arr[r];
            arr[r] = arr[l];
            arr[l] = temp;
        }
    }
    arr[left] = arr[r];
    arr[r] = pivot;
    return r;
}

// Quicksort function
void quickSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        // Partition the array into two parts using the pivot element
        int pi = partition(arr, left, right);

        // sort the subarrays
        quickSort(arr, left, pi - 1);
        quickSort(arr, pi + 1, right);
    }
}

int main()
{
    vector<int> arr = {10, 7, 8, 9, 1, 5};
    int size = arr.size();

    cout << "Original array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    quickSort(arr, 0, size - 1);

    cout << "Sorted array: ";
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;

    return 0;
}
