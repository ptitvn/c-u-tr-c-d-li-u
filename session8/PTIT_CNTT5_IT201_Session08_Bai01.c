#include <stdio.h>

int linearSearch(int arr[], int n, int search) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == search) {
            return i + 1; 
        }
    }
    return -1; 
}
int main() {
    int n;
    printf("Nhap so luong phan tu (0 < n < 1000): ");
    scanf("%d", &n);
    
    if (n <= 0 || n >= 1000) {
        printf("So luong phan tu khong hop le.\n");
        return 1;
    }
    
    int arr[n];
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    int search;
    printf("Nhap gia tri can tim kiem: ");
    scanf("%d", &search);
    
    int result = linearSearch(arr, n, search);
    
    //Độ phức tạp thời gian của thuật toán tìm kiếm tuyến tính là O(n)

    if (result != -1) {
    
        printf("Vi tri thu: %d\n", result);
    } else {
        printf("Khong ton tai phan tu \n");
    }
    
    return 0;
}