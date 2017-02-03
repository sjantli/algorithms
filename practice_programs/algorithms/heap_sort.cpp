#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using std::cout;
using std::cin;
using std::endl;

#define LEFT(i) ((2*i) + 1)
#define RIGHT(i) ((2*i) + 2)
#define PARENT(i) \
    if (i % 2 == 0) \
        (i/2 - 1) \
    else        \
        (i/2)

void heapify(int *arr, int index, int heapsize) {
    int left = LEFT(index);
    int right = RIGHT(index);

    int largest = index;

    if (left < heapsize && arr[left] > arr[largest]) {
        largest = left;
    }
    if (right < heapsize && arr[right] > arr[largest]) {
        largest = right;
    }
    if (largest != index) {
        // swap arr[largest] and a[index] and heapify on largest(trickles down to n)
        int temp = arr[largest];
        arr[largest] = arr[index];
        arr[index] = temp;
        heapify(arr, largest, heapsize);
    }
}

void build_heap(int *arr, int n) {
    for (int i = n/2 - 1; i >= 0; i--) {
        heapify(arr, i, n);
    }
}

void heap_sort(int *arr, int n) {
    int heapsize = n;
    build_heap(arr, n);
    for (int i = n-1; i > 0; i--) {
        // since by this time we would have the max element at the heap root, exchange it with last element, reduce the heapsize and heapify from root
        int temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapsize --;
        heapify(arr, 0, heapsize);
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
    heap_sort(arr, n);
    cout << "sorted array is:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;
}
