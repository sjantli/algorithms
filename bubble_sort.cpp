#include <iostream>
#include <stdlib.h>
#include <stdio.h>

using std::cout;
using std::cin;
using std::endl;

void bubble_sort(int *arr, int n) {
	for (int i = 0; i < n; i++) {
        for(int j = 0; j < n-1; j++) {
            // keep comparing with adjacent elements and sort them until the entire array is traversed.
            if(arr[j] > arr[j+1]) {
                int temp = arr[j];
                arr[j] = arr[j+1];
                arr[j+1] = temp;
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
    bubble_sort(arr, n);
    cout << "sorted array is:\n";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << "\t";
    }
    cout << endl;


}
