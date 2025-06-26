#include <stdio.h>

int main (){
    //Xây dựng chương trình yêu cầu người dùng nhập vào một số nguyên dương bất kỳ 

    int n;
    printf("Nhap mot so nguyen duong: ");
    scanf("%d", &n);
    //Kiểm tra điều kiện n
    if (n <= 0) {
        printf("khong hop le! \n");
        return 1; 
    }
    // Sử dụng đệ quy, tính và in ra giai thừa của số đã nhập
    long long factorial = 1;
    for (int i = 1; i <= n; i++) {
        factorial *= i;
    }
    printf("Giai thua cua %d la: %lld\n", n, factorial);
    return 0; 
}