#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    // Nhập số lượng phần tử
    printf("Nhap so luong phan tu (0 < n <= 1000): ");
    scanf("%d", &n);

    // Kiểm tra điều kiện n
    if (n <= 0 || n > 1000) {
        printf("So luong phan tu khong hop le!\n");
        return 1;
    }

    // Cấp phát bộ nhớ động cho mảng
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Khong the cap phat bo nho dong!\n");
        return 1;
    }

    // Nhập các phần tử của mảng
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Tìm số lớn nhất trong mảng
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // In ra số lớn nhất
    printf("So lon nhat trong mang la: %d\n", max);

    // Giải phóng bộ nhớ đã cấp phát
    free(arr);

    return 0;
}
