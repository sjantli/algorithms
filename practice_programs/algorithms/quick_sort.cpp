#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using std::cout;
using std::cin;
using std::endl;

int partition(int *arr, int low, int high) {
    int i = low - 1;
    int x = arr[high];
    for (int j = low; j < high; j++) {
        if (arr[j] <= x) {
            i = i + 1;
            int temp = arr[i];
            arr[i] = arr[j];
            arr[j] = temp;
        }
    }
    int temp = arr[i+1];
    arr[i+1] = x;
    arr[high] = temp;
    return i+1;
}

// Divide the lists
void quick_sort(int *arr, int low, int high) {
    if (low < high) {
        // to avoid overflow of int sizes, do the following which is same as (low+high)/2.
        int mid = partition(arr, low, high);
        quick_sort(arr, low, mid-1);
        quick_sort(arr, mid+1, high);
    }
}

int main() {
    int n;
    cout << "enter the size of array\n";
    cin >> n;
    int arr[n];
    cout << "enter the array elements\n";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    quick_sort(arr, 0, n-1);
    cout << "sorted array is:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}
