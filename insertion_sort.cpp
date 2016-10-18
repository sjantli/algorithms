#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using std::cout;
using std::cin;
using std::endl;

void insertion_sort(int *arr, int n) {
	for (int i = 1; i < n; i++) {
        int key = arr[i];
        for (int j = i-1; j >= 0; j--) {
            // if new element is less than previously sorted array then swap arr[j] and arr[j+1]
            if (key < arr[j]) {
                int temp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = temp;
            }
        }
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
    insertion_sort(arr, n);
    cout << "sorted array is:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;


}
