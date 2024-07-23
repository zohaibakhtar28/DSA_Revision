#include <bits/stdc++.h>
using namespace std;

// selection sort.
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

void selection_sort(vector<int> &arr, int n) // n*n
{
    for (int i = 0; i <= n - 2; i++)
    {
        int min = i;
        for (int j = i + 1; j <= n - 1; j++)
        {
            if (arr[j] < arr[min])
            {
                min = j;
            }
            int temp = arr[min];
            arr[min] = arr[i];
            arr[i] = temp;
        }
    }
}

void bubbleSort(vector<int> &arr, int n) // n*n
{
    for (int i = n - 1; i >= 0; i--)
    {
        for (int j = 0; j < i; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                swap(arr[j], arr[j + 1]);
            }
        }
    }
}

void insertion_sort(vector<int> &arr, int n) // n*n , best - n
{
    for (int i = 0; i < n; i++)
    {
        int j = i;
        while (j > 0 && arr[j - 1] > arr[j])
        {
            swap(arr[j - 1], arr[j]);
            j--;
        }
    }
}

void merge(vector<int> &arr, int low, int mid, int high)
{
    vector<int> temp;

    int i = low;
    int j = mid + 1;
    while (i <= mid && j <= high)
    {
        if (arr[i] <= arr[j])
        {
            temp.push_back(arr[i]);
            i++;
        }
        else
        {
            temp.push_back(arr[j]);
            j++;
        }
    }

    while (i <= mid)
    {

        temp.push_back(arr[i]);
        i++;
    }
    while (j <= high)
    {

        temp.push_back(arr[j]);
        j++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];
    }
}
void merge_sort(vector<int> &arr, int low, int high)
{
    if (low == high)
    {
        return;
    }

    int mid = (low + high) / 2;
    merge_sort(arr, low, mid);
    merge_sort(arr, mid + 1, high);
    merge(arr, low, mid, high);
}

int pIndex(vector<int> &arr, int low, int high)
{
    int i = low;
    int j = high;
    int pivot = arr[low];

    while (i < j)
    {
        while (arr[i] <= pivot && i <= high)

        {
            i++;
        }

        while (arr[j] > pivot && j >= low)

        {
            j--;
        }

        if (i < j)
        {
            swap(arr[i], arr[j]);
        }
    }

    swap(arr[low], arr[j]);
    return j;
}
void quick_sort(vector<int> &arr, int low, int high)
{
    if (low < high)
    {
        int index = pIndex(arr, low, high);
        quick_sort(arr, low, index - 1);
        quick_sort(arr, index + 1, high);
    }
}
int main()
{
    vector<int> arr{9, 8, 7, 6, 5, 4, 3, 2, 1};
    int n = 9;
    quick_sort(arr, 0, n - 1);
    for (auto x : arr)
    {
        cout << x << " ";
    }
}