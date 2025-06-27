#include <stdio.h>

int sumDigits(int n) {
    if (n == 0) {
        return 0;
    }
    return (n % 10) + sumDigits(n / 10);
}
int main() {
    int n;
    printf("Nhap so nguyen duong n: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Input khong hop le.\n");
        return 1;
    }
    
    int result = sumDigits(n);
    printf("Tong cac chu so cua %d la: %d\n", n, result);
    
    return 0;
}