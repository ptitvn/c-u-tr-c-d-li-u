#include <stdio.h>

int main() {
    int n, i, target, count = 0;

    // Nhập số lượng phần tử của mảng
    do {
        printf("Nhap so luong phan tu cua mang (0 < n <= 100): ");
        scanf("%d", &n);
    } while (n <= 0 || n > 100);

    int arr[n];

    // Nhập các phần tử của mảng
    printf("Nhap %d cua phan tu mang :\n", n);
    for (i = 0; i < n; i++) {
        printf("Phan tu thu  %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // Nhập số cần đếm
    printf("Nhap so can dem: ");
    scanf("%d", &target);

    // Đếm số lần xuất hiện của số đó
    for (i = 0; i < n; i++) {
        if (arr[i] == target) {
            count++;
        }
    }

    // In kết quả
    printf("So %d xuat hien %d lan trong mang .\n", target, count);

    return 0;
}
