#include <stdio.h>
int main (){
    int n;
    // Nhập số lượng phần tử
    printf("Nhap so luong phan tu (0 < n <= 1000): ");
    scanf("%d", &n);    
    if (n <= 0 || n > 1000) {
        printf("So luong phan tu khong hop le!\n");
        return 1;
    }
    int arr[n];
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu thu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] > arr[j]) {
                int temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
    // thuật toán tìm kiếm nhị phân
    int x;
    printf("Nhap gia tri can tim: ");
    scanf("%d", &x);
    // Tìm kiếm nhị phân
    int left = 0, right = n - 1;
    int found = 0; 
    while (left <= right) {
        int mid = left + (right - left) / 2; 
        if (arr[mid] == x) {
            printf("Phan tu ton tai trong mang");
            found = 1; 
            break;
        } else if (arr[mid] < x) {
            left = mid + 1; 
        } else {
            right = mid - 1; 
        }
    }
    if (!found) {
        printf("phan tu khong ton tai trong mang.\n");
    }
}