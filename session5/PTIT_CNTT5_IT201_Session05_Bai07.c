#include <stdio.h>
int main (){
    int n;
    printf("Nhap mot so nguyen duong: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Khong hop le! \n");
        return 1; 
    }
    
    int fib[n];
    fib[0] = 0; 
    if (n > 1) {
        fib[1] = 1; 
    }
    
    for (int i = 2; i < n; i++) {
        fib[i] = fib[i - 1] + fib[i - 2]; 
    }
    // In ra các số Fibonacci đã tính
    printf("Cac so Fibonacci dau tien:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", fib[i]);
    }


    return 0;
}