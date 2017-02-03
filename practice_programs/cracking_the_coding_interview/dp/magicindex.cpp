#include <iostream>
#include <string>
#include <stack>
#include <vector>

#define MAX(a, b) (a > b) ? a : b
#define MIN(a, b) (a < b) ? a : b


int magicSlow(int *arr, int size) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == i)
            return i;
    }
    return -1;
}

int magicFastDistinct(int *arr, int start, int end, int size) {
    if (start > end || start < 0 || end >= size) {
        return -1;
    }
    int mid = (start + end)/2;
    if (arr[mid] == mid) {
        return mid;
    } else if (mid < arr[mid]) {
        return magicFastDistinct(arr, start, mid-1, size);
    } else {
        return magicFastDistinct(arr, mid+1, end, size);
    }
}

// ex: -1, 0 , 2, 5, 5, 6, 6
// ex: -20, -40, 2, 2, 2, 3, 4, 7, 9, 12, 13
int magicFast(int *arr, int start, int end, int size) {
    if (start > end || start < 0 || end >= size) {
        return -1;
    }
    int mid = (start + end)/2;
    if (arr[mid] == mid) {
        return mid;
    }
    int left = magicFast(arr, start, MIN(mid-1, arr[mid]), size);
    if (left >= 0)
        return left;

    return magicFast(arr, MAX(mid+1, arr[mid]), end, size);
}

int main() {
    int repeat1[7] = {-1, 0, 2, 5, 5, 6, 6};
    int repeat2[11] = {-20, -10, 2, 2, 2, 3, 4, 7, 9, 12, 13};

    int distinct1[7] = {-1, 0, 2, 4, 5, 6, 7};
    int distinct2[11] = {-20, -10, 0, 1, 2, 3, 4, 7, 9, 12, 13};
    int size1 = sizeof(repeat1)/sizeof(repeat1[0]);
    int size2 = sizeof(repeat2)/sizeof(repeat2[0]);
    int size3 = sizeof(distinct1)/sizeof(distinct1[0]);
    int size4 = sizeof(distinct2)/sizeof(distinct2[0]);

    std::cout << "magicslow repeat1(2): " << magicSlow(repeat1, size1) << "\n";
    std::cout << "magicslow repeat2(2): " << magicSlow(repeat2, size2) << "\n";
    std::cout << "magicfast repeat1(2): " << magicFast(repeat1, 0, size1 - 1, size1) << "\n";
    std::cout << "magicfast repeat2(2): " << magicFast(repeat2, 0, size2 - 1, size2) << "\n";
    std::cout << "magicslow distinct1(2): " << magicSlow(distinct1, size3) << "\n";
    std::cout << "magicslow distinct2(7): " << magicSlow(distinct2, size4) << "\n";
    std::cout << "magicfast distinct1(2): " << magicFastDistinct(distinct1, 0, size3 - 1, size3) << "\n";
    std::cout << "magicfast distinct2(7): " << magicFastDistinct(distinct2, 0, size4 - 1, size4) << "\n";
}

