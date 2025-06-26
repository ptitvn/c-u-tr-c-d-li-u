#include <stdio.h>
int main (){

    int firstNum, secondNum;
    printf("Nhap so nguyen duong dau tien: ");
    scanf("%d", &firstNum);
    printf("Nhap so nguyen duong thu hai: ");
    scanf("%d", &secondNum);
    if (firstNum <= 0 || secondNum <= 0) {
        printf("Khong hop le! \n");
        return 1; 
    }
    long long sum = 0;
    for (int i = firstNum; i <= secondNum; i++) {
        sum += i;
    }
    printf("Tong tu %d den %d la: %lld\n", firstNum, secondNum, sum);
    
    return 0;
}