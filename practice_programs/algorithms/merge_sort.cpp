#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using std::cout;
using std::cin;
using std::endl;

// Sort and Merge the lists
void merge(int *arr, int low, int mid, int high) {
    // remember how we break the array and copy it
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int a1[n1];
    int a2[n2];
    for(int i = 0; i < n1; i++) {
        a1[i] = arr[low + i];
    }
    for(int i = 0; i < n2; i++) {
        a2[i] = arr[mid + i + 1];
    }

    int i = 0;
    int j = 0;
    int k = low;
    /* always use the following way to merge the lists else it can compare with stale values */
    while(i < n1 && j < n2) {
        if (a1[i] <= a2[j]) {
            arr[k] = a1[i];
            i++;
        } else {
            arr[k] = a2[j];
            j++;
        }
        k++;
    }
    while (i < n1) {
        arr[k] = a1[i];
        i++;
        k++;
    }
    while (j < n2) {
        arr[k] = a2[j];
        j++;
        k++;
    }
}

// Divide the lists
void merge_sort(int *arr, int low, int high) {
    if (low < high) {
        // to avoid overflow of int sizes, do the following which is same as (low+high)/2.
        int mid = low+(high-low)/2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid+1, high);
        merge(arr, low, mid, high);
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
    merge_sort(arr, 0, n-1);
    cout << "sorted array is:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}
