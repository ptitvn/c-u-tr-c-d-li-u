#include <stdio.h>

int countWays(int n) {
    if (n == 0) return 1; 
    if (n < 0) return 0; 
    return countWays(n - 1) + countWays(n - 2); 
}
int main() {
    int n;
    printf("Nhap so bac cua cau thang: ");
    scanf("%d", &n);
    
    if (n < 0) {
        printf("So bac phai la so nguyen duong.\n");
        return 1;
    }
    
    int ways = countWays(n);
    printf("So cach de leo het %d bac la: %d\n", n, ways);
    
    return 0;
}