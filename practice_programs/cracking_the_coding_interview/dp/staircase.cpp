#include <iostream>
#include <string>
#include <stack>

int countWaysRecursion(int n) {
    if (n < 0)
        return 0;
    else if (n == 0)
        return 1;
    else
        return countWaysRecursion(n-1) + countWaysRecursion(n-2) + countWaysRecursion(n-3);
}

int countWaysDp(int n, int arr[]) {
    if (n < 0)
        return 0;
    else if (n == 0)
        return 1;
    else if (arr[n] > -1)
        return arr[n];
    else {
        arr[n] = countWaysDp(n-1, arr) + countWaysDp(n-2, arr) + countWaysDp(n-3, arr);
        return arr[n];
    }
}

int main() {
    int n = 5;
    int arr[n+1];
    for(int i = 0; i <= n; i++)
        arr[i] = -1;
    std::cout << "count ways recursion: " << countWaysRecursion(n);
    std::cout << "\ncount ways dp: " << countWaysDp(n, arr) << "\n";
}

