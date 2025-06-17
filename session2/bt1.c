#include <stdio.h>

int main() {
    int n;

    // Nhập số lượng phần tử của mảng
    do {
        printf("nhap so luong phan tu cua mang (0 < n <= 100): ");
        scanf("%d", &n);
    } while (n <= 0 || n > 100);

    int arr[n];

    // Nhập các phần tử của mảng
    printf("nhap cac phan tu mang :\n");
    for (int i = 0; i < n; i++) {
        printf("phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Tìm phần tử lớn nhất
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    // In ra phần tử lớn nhất
    printf("Phan tu lon nhat trong mang la: %d\n", max);

    return 0;
}
