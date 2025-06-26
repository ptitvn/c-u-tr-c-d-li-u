#include <stdio.h>

int main (){
    //Xây dựng chương trình yêu cầu người dùng nhập vào một số nguyên dương bất kỳ
    int n;
    printf("Nhap mot so nguyen duong: ");
    scanf("%d", &n);
    //Kiểm tra điều kiện n
    if (n <= 0) {
        printf("So nhap vao khong hop le! Vui long nhap mot so nguyen duong.\n");
        return 1; // Kết thúc chương trình với mã lỗi
    }
    // Sử dụng đệ quy, in ra lần lượt các phần tử từ 1 đến n
    printf("Cac so tu 1 den %d la: ", n);
    for (int i = 1; i <= n; i++) {
        printf("%d ", i);
    }
    
    return 0;
}