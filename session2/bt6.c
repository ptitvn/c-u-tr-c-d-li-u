#include <stdio.h>

int main() {
    int n, position, value;
    int arr[100]; 

    // Nhập số lượng phần tử của mảng
    printf("Nhap so luong phan tu vao mang (0 < n <= 100): ");
    scanf("%d", &n);

    if (n <= 0 || n > 100) {
        printf("So luong phan tu khong hop le!\n");
        return 1;
    }

    // Nhập các phần tử của mảng
    printf("Nhap %d phan tu cua mang:\n", n);
    for (int i = 0; i < n; i++) {
        printf("Phan tu [%d]: ", i);
        scanf("%d", &arr[i]);
    }

    // Nhập vị trí và giá trị muốn thêm
    printf("Nhap vi tri muon them (0 <= vi tri <= %d): ", n);
    scanf("%d", &position);
    printf("Nhap gia tri muon them: ");
    scanf("%d", &value);

    // Kiểm tra vị trí hợp lệ
    if (position < 0 || position > n || n >= 100) {
        printf("Vi tri khong hop le!\n");
        return 1;
    }

    // Dịch chuyển các phần tử để chèn giá trị mới
    for (int i = n; i > position; i--) {
        arr[i] = arr[i - 1];
    }
    arr[position] = value; // Thêm giá trị vào vị trí chỉ định
    n++; // Tăng số lượng phần tử

    // In mảng sau khi thêm
    printf("Mang sau khi them phan tu :\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}
