#include <stdio.h>
int main () {
    int n;
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
    // Tìm kiếm và in ra các cặp phần tử đối xứng trong mảng
    printf("Cac cap phan tu doi xung trong mang:\n");
    int found = 0; 
    for (int i = 0; i < n / 2; i++) {
        if (arr[i] == arr[n - 1 - i]) {
            printf("(%d, %d)\n", arr[i], arr[n - 1 - i]);
            found = 1; 
        }
    }
    if (!found) {
        printf("Khong co cap phan tu doi xung trong mang.\n");
    }
    return 0;
}