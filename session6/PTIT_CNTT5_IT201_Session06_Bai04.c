#include <stdio.h>

void moveTower(int n, char source, char target, char auxiliary) {
    if (n == 1) {
        printf("Di chuyen dia 1 tu %c sang %c\n", source, target);
        return;
    }
    moveTower(n - 1, source, auxiliary, target);
    printf("Di chuyen dia %d tu %c sang %c\n", n, source, target);
    moveTower(n - 1, auxiliary, target, source);
}   
int main() {
    int n;
    printf("Nhap so nguyen duong n: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("Input khong hop le.\n");
        return 1;
    }
    
    printf("Cac buoc chuyen dia:\n");
    moveTower(n, 'A', 'C', 'B');
    
    return 0;
}
