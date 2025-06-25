#include <stdio.h>
int main (){
    int n;
    // Nhập số lượng phần tử
    printf("Nhap so luong phan tu (0 < n <= 1000): ");
    scanf("%d", &n);    
    // Kiểm tra điều kiện n
    if (n <= 0 || n > 1000) {
        printf("So luong phan tu khong hop le!\n");
        return 1;
    }
    // nhập các phần tử của mảng
    int arr[n];
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    // Tìm  chỉ số của phần tử lớn nhất đầu tiên trong mảng
    int maxIndex = 0; 
    for (int i = 1; i < n; i++) {
        if (arr[i] > arr[maxIndex]) {
            maxIndex = i; 
        }
    }
    printf("Phan tu lon nhat dau tien trong mang o vi tri %d\n",  maxIndex);
    return 0;

}