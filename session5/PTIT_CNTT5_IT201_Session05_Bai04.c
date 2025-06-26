#include <stdio.h>

int sum(int firstNum, int secondNum) {
    if (firstNum > secondNum) {
        return 0; // Trường hợp dừng đệ quy
    }
    return firstNum + sum(firstNum + 1, secondNum); 
}
int main() {
    int firstNum, secondNum;
    printf("Nhap so nguyen duong dau tien: ");
    scanf("%d", &firstNum);
    printf("Nhap so nguyen duong thu hai: ");
    scanf("%d", &secondNum);
    
    if (firstNum < 0 || secondNum < 0 || firstNum > secondNum) {
        printf("Nhap khong hop le! Vui long nhap hai so nguyen duong, trong do so dau tien nho hon hoac bang so thu hai.\n");
        return 1; 
    }
    
    int result = sum(firstNum, secondNum);
    printf("Tong tu %d den %d la: %d\n", firstNum, secondNum, result);
    
    return 0;
}