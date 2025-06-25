#include <stdio.h>
int main (){
    int n;
    // Nhập số lượng phần tử
    printf("Nhap so luong phan tu (0 < n <= 1000): ");
    scanf("%d", &n);
    // Kiểm tra điều kiện n
    if (n <= 0 || n > 1000) {
        printf("So luong phan tu khong hop le!\n");
        return 1;
    }
    // nhập các phần tử của mảng
    int arr[n]; 
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    // giá trị cần tìm 
    int x;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);
    // phần tử đầu tiên bằng x
    int found = 0;
    for (int i = 0; i < n; i++) {
        if (arr[i] == x) {
            printf("Phan tu %d dau tien bang %d o vi tri %d\n", x, x, i );
            found = 1;
            break;
        }
    }
    if (!found) {
        printf("Khong tim thay phan tu %d trong mang.\n", x);
    }
    
    return 0;
}