#include <stdio.h>
// Hàm để tìm cặp phần tử có tổng bằng một số nguyên 
void findPairWithSum(int arr[], int n, int target) {
    int found = 0; 
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == target) {
                printf("Cap phan tu co tong bang %d la: (%d, %d)\n", target, arr[i], arr[j]);
                found = 1;
            }
        }
    }
    if (!found) {
        printf("Khong tim thay cap phan tu nao co tong bang %d.\n", target);
    }
}

int main() {
    int n, target;

    // Nhập số phần tử của mảng
    printf("Nhap so phan tu vao mang : ");
    scanf("%d", &n);

    int arr[n];

    // Nhập các phần tử của mảng
    printf("Nhap cac phan tu vao mang :\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Nhập số nguyên cần tìm tổng
    printf("Nhap so nguyen can tim tong: ");
    scanf("%d", &target);

    // Gọi hàm tìm cặp phần tử
    findPairWithSum(arr, n, target);

    return 0;
}
