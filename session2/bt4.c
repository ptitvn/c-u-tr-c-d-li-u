#include <stdio.h>

int main() {
    int n;

    // Nhập số lượng phần tử của mảng
    do {
        printf("Nhap so luong phan tu cua mang (0 < n <= 100): ");
        scanf("%d", &n);
    } while (n <= 0 || n > 100);

    int arr[n];

    // Nhập các phần tử của mảng
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i);
        scanf("%d", &arr[i]);
    }

    int position, value;

    // Nhập vị trí muốn sửa và giá trị mới
    printf("Nhap vi tri muon sua (0 <= position < %d): ", n);
    scanf("%d", &position);

    if (position < 0 || position >= n) {
        printf("Vi tri khong hop le!\n");
        return 1;
    }

    printf("Nhap gia tri moi: ");
    scanf("%d", &value);

    // Cập nhật giá trị tại vị trí mong muốn
    arr[position] = value;

    // In mảng sau khi cập nhật
    printf("Mang sau khi cap nhat:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
