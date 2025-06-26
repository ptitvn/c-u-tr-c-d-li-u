#include <stdio.h>
int main(){
   
    // Tính tổng từ 1 đến n
    int n;
    printf("Nhap mot so nguyen duong: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf(" khong hop le!\n");
        return 1; 
    }
    int sum = 0;
    for (int i = 1; i <= n; i++) {
        sum += i;
    }
    // In ra kết quả tổng
    printf(" %d",  sum);
    

    return 0; 
}