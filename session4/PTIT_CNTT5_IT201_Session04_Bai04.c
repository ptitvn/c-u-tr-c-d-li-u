#include <stdio.h>
int main (){
    int n ;
    // Nhập số lượng phần tử
    printf("Nhap so luong phan tu (0 < n <= 1000):  ");
    scanf("%d", &n);
    // Kiểm tra điều kiện n
    if (n <= 0 || n > 1000) {   
        printf("So luong phan tu khong hop le!\n");
        return 1;
    }
    // Nhập các phần tử của mảng
    int arr[n];
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    //  Tìm chỉ số của phần tử cuối cùng 
    int x;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);
    int lastIndex = -1; 
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            lastIndex = i;
        }
    }
    if (lastIndex != -1) {
        printf("Phan tu %d cuoi cung o vi tri %d\n", x, lastIndex);
    } else {
        printf("Khong tim thay phan tu .\n", x);
    }
}