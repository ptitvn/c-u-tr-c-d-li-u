#include <stdio.h>

int main() {
    int n, pos;

    // Nhập số lượng phần tử của mảng
    printf("Nhap so luong phan tu cua mang  (0 < n <= 100): ");
    scanf("%d", &n);

    // Kiểm tra tính hợp lệ của n
    if (n <= 0 || n > 100) {
        printf("So luong phan tu khong hop le!\n");
        return 1;
    }

    int arr[n];

    // Nhập các phần tử của mảng
    printf("Nhap %d phan tu cua mang:\n", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Nhập vị trí muốn xóa
    printf("Nhap vi chi muon xoa (0 <= vi tri < %d): ", n);
    scanf("%d", &pos);

    // Kiểm tra tính hợp lệ của vị trí
    if (pos < 0 || pos >= n) {
        printf("Vi tri khong hop le!\n");
        return 1;
    }

    // Xóa phần tử tại vị trí pos
    for (int i = pos; i < n - 1; i++) {
        arr[i] = arr[i + 1];
    }
    n--; // Giảm số lượng phần tử của mảng

    // In mảng sau khi xóa
    printf("Mang sau khi xoa phan tu tai %d:\n", pos);
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
