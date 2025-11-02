#include <iostream>
#include <vector>

long long counts = 0; 
void merge(std::vector<int>& arr, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;

    std::vector<int> L(n1);
    std::vector<int> R(n2);

    for (int i = 0; i < n1; i++)
        L[i] = arr[left + i];
    for (int j = 0; j < n2; j++)
        R[j] = arr[mid + 1 + j];

    int i = 0, j = 0, k = left;

    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k++] = L[i++];
        }
        else
        {
            arr[k++] = R[j++];
            counts += n1 - i;
        }
    }

    while (i < n1)
        arr[k++] = L[i++];
    while (j < n2)
        arr[k++] = R[j++];
}

void mergeSort(std::vector<int>& arr, int left, int right)
{
    if (left < right)
    {
        int mid = left + (right - left) / 2;
        mergeSort(arr, left, mid);
        mergeSort(arr, mid + 1, right);
        merge(arr, left, mid, right);
    }
}

void printArray(const std::vector<int>& arr)
{
    for (int val : arr)
        std::cout << val << " ";
    std::cout << "\n";
}

int main()
{
    std::vector<int> arr = {3, 4, 2, 8, 1, 5, 7, 0};

    std::cout << "Given array is:\n";
    printArray(arr);

    mergeSort(arr, 0, arr.size() - 1);

    std::cout << "Sorted array is:\n";
    printArray(arr);

    std::cout << "Number of inversions: " << counts << "\n";

    std::cout<< 7/2;

    return 0;
}

// Time Complexity: O(n log n)
// Space Complexity: O(n)
