#include <iostream>
#include <vector>

using namespace std;
void merge(vector<int> &arr, int left, int mid, int right)
{
    int n1 = mid - left + 1; // no of elements form left to mid
    int n2 = right - mid;    // no of element from mid to right

    // copy these to new new arrays
    vector<int> a(n1);
    for (int i = 0; i < n1; i++)
        a[i] = arr[left + i];
    vector<int> b(n2);
    for (int i = 0; i < n2; i++)
        b[i] = arr[mid + 1 + i];

    int i = 0, j = 0, k = left; // k starts from left as the 1st sorted element will be placed at left of arr
    while (i < n1 && j < n2)
    {
        if (a[i] <= b[j])
            arr[k] = a[i++];
        else
            arr[k] = b[j++];
        k++;
    }
    while (i < n1)
        arr[k++] = a[i++];
    while (j < n2)
        arr[k++] = b[j++];
}
void mergeSort(vector<int> &arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}
int main()
{
    vector<int> arr = {12, 11, 13, 5, 6, 7};
    int size = arr.size();
    cout << "Unsorted array" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }
    mergeSort(arr, 0, size - 1);
    cout << "\nSorted array" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << "\t";
    }

    return 0;
}