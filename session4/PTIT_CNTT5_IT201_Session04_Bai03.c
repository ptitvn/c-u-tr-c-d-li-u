#include <stdio.h>
int main (){
    int n ;
    // Nhập số lượng phần tử
    printf("Nhap so luong phan tu (0 < n <= 1000): ");
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
    // Tìm chỉ số của phần tử nhỏ nhất đầu tiên trong mảng
    int minIndex = 0;
    for (int i = 1; i < n; i++) {
        if (arr[i] < arr[minIndex]) {
            minIndex = i; // Cập nhật chỉ số của phần tử nhỏ nhất
        }
    }
    printf("Phan tu nho nhat dau tien trong mang o vi tri %d\n", minIndex);
    return 0;

}