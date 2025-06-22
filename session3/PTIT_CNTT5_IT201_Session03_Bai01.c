#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;

    // Nhập số lượng phần tử
    printf("Nhap so luong phan tu (0 < n < 1000): ");
    scanf("%d", &n);

    // Kiểm tra điều kiện n
    if (n < 0) {
        printf("So luong phan tu khong duoc am\n");
        return 1;
    } else if (n == 0) {
        printf("So luong phan tu phải lon hon  0\n");
        return 1;
    } else if (n >= 1000) {
        printf("So luong phan tu khong vuot qua 1000\n");
        return 1;
    }

    // Cấp phát động cho mảng
    int *arr = (int *)malloc(n * sizeof(int));
    if (arr == NULL) {
        printf("Cap phat bo nho dong thanh cong\n");
        return 1;
    }

    // Nhập giá trị các phần tử trong mảng
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // In ra các phần tử trong mảng
    printf("Cac phan tu trong mang la:\n");
    for (int i = 0; i < n; i++) {
        printf("So thu %d = %d\n", i + 1, arr[i]);
    }

    // Giải phóng bộ nhớ
    free(arr);
    return 0;
}
