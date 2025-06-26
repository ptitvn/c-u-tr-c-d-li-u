#include <stdio.h>

int sum(int n) {
    if (n <= 0) {
        return 0; 
    }
    return n + sum(n - 1); 
}
int main() {
    int n;
    printf("Nhap mot so nguyen duong: ");
    scanf("%d", &n);
    
    if (n < 0) {
        printf("Khong hop le! Vui long nhap mot so nguyen duong.\n");
        return 1; 
    }
    
    int result = sum(n);
    printf("Tong tu 1 den %d la: %d\n", n, result);
    
    return 0;
}