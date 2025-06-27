#include <stdio.h>
int convertToBinary(int n) {
    if (n == 0) {
        return 0;
    }
    return n % 2 + 10 * convertToBinary(n / 2);
}
int main() {
    int n;
    printf("Nhap so nguyen duong: ");
    scanf("%d", &n);
    
    if (n < 0) {
        printf("So phai la so nguyen duong.\n");
        return 1;
    }
    
    int binary = convertToBinary(n);
    printf("So %d trong he nhi phan la: %d\n", n, binary);
    
    return 0;
}