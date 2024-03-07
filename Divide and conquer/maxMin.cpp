#include <iostream>

using namespace std;

void maxMin(int i, int j, int *min, int *max, int arr[])
{
    if (i == j)
    {
        *min = arr[i];
        *max = arr[i];
    }
    else if (i == j - 1)
    {
        if (arr[i] > arr[j])
        {
            *min = arr[j];
            *max = arr[i];
        }
        else
        {
            *min = arr[i];
            *max = arr[j];
        }
    }
    else
    {
        int mid = (i + j) / 2;
        int min1, max1, min2, max2;
        maxMin(i, mid, &min1, &max1, arr);
        maxMin(mid + 1, j, &min2, &max2, arr);
        *min = min1 < min2 ? min1 : min2;
        *max = max1 > max2 ? max1 : max2;
    }
}

int main()
{
    int arr[] = {2, 5, 7, 9, 12, 15, 17};
    int size = sizeof(arr) / sizeof(arr[0]);
    int min = 0, max = 0;

    maxMin(0, size - 1, &min, &max, arr);

    cout << "Minimum element: " << min << endl;
    cout << "Maximum element: " << max << endl;

    return 0;
}
    