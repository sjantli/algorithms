#include<stdio.h>
int func(int a[], int b[], int n) {
    printf("%d\t%d\n", (sizeof(a)/sizeof(a[0])), (sizeof(b)/sizeof(b[0])));
    for(int i =0; i < n; i++) {
        printf("%d\t%d\n", a[i], b[i]);
    }
}

void main() {
    int a[4] = {5,4,3,2};
    int b[4];
    b[0] = 5;
    b[1] = 4;
    b[2] = 3;
    b[3] = 2;
    printf("%d\t%d\n", (sizeof(a)/sizeof(a[0])), (sizeof(b)/sizeof(b[0])));
    func(a, b, 4);
    printf("%d\t%d\n", (sizeof(a)/sizeof(a[0])), (sizeof(b)/sizeof(b[0])));
}
