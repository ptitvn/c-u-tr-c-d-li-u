#include <stdio.h>

// Hàm đếm số lần xuất hiện của phần tử x trong mảng arr[]
int demSoLanXuatHien(int arr[], int n, int x) {
    int dem = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            dem++;  
        }
    }
    return dem;
    // Độ phức tạp thời gian: O(n), duyệt toàn bộ mảng một lần
    // Độ phức tạp không gian: O(1), không dùng thêm bộ nhớ phụ
}

int main() {
    int n, x;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);

    int arr[n];
    printf("Nhap cac phan tu trong mang:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("Nhap gia tri can dem: ");
    scanf("%d", &x);

    int soLan = demSoLanXuatHien(arr, n, x);
    printf("So lan xuat hien cua %d trong mang la: %d\n", x, soLan);

    return 0;
}