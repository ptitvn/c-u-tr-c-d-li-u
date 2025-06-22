#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m, i;

    // Nhập số lượng phần tử ban đầu
    printf("Nhap so luong phan tu n (0 < n <= 1000): ");
    scanf("%d", &n);

    if (n <= 0 || n > 1000) {
        printf("So luong phan tu khong hop le!\n");
        return 1;
    }

    // Cấp phát bộ nhớ động cho mảng ban đầu
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Khong the cap phat bo nho dong!\n");
        return 1;
    }

    // Nhập các phần tử cho mảng ban đầu
    printf("Nhap %d phan tu cho mang\n", n);
    for (i = 0; i < n; i++) {
        printf("Phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Nhập số lượng phần tử cần thêm
    printf("Nhập số lượng phần tử cần thêm m: ");
    scanf("%d", &m);

    if (m < 0) {
        printf("Số lượng phần tử thêm không hợp lệ!\n");
        free(arr);
        return 1;
    }

    // Cấp phát lại bộ nhớ để thêm phần tử
    arr = (int *)realloc(arr, (n + m) * sizeof(int));
    if (arr == NULL) {
        printf("Không thể cấp phát lại bộ nhớ!\n");
        return 1;
    }

    // Nhập các phần tử mới
    printf("Nhap %d phan tu can them:\n", m);
    for (i = n; i < n + m; i++) {
        printf("Phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // In mảng sau khi thêm phần tử
    printf("Mang sau khi them phan tu:\n");
    for (i = 0; i < n + m; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    // Giải phóng bộ nhớ động
    free(arr);

    return 0;
}
