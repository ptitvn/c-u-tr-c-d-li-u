#include <stdio.h>

int fibonacci(int k) {
    if (k == 1 || k == 2) return 1;
    return fibonacci(k - 1) + fibonacci(k - 2);
}

int main() {
    int n;
    printf("Nhap so nguyen duong n: ");
    scanf("%d", &n);

    if (n < 1) {
        printf("Input khong hop le\n");
        return 1;
    }

    printf("Cac so Fibonacci dau tien theo thu tu nguoc la: ");
    for (int i = n; i >= 1; i--) {
        printf("%d", fibonacci(i));
        if (i > 1) printf(", ");
    }
    printf("\n");
    return 0;
}