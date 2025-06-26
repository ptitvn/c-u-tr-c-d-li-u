#include <stdio.h>

int factorial(int n) {
    if (n == 0 || n == 1) {
        return 1; 
    }
    return n * factorial(n - 1);
}
int main() {
    int n;
    printf("Nhap mot so nguyen duong: ");
    scanf("%d", &n);
    
    if (n < 0) {
        printf("Khong hop le! Vui long nhap mot so nguyen duong.\n");
        return 1; 
    }
    
    int result = factorial(n);
    printf("Giai thua cua %d la: %d\n", n, result);
    
    return 0;
}