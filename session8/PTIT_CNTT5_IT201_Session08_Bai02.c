#include <stdio.h>

int binarySearch(int arr[], int n, int search) {
    int left = 0, right = n - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (arr[mid] == search) {
            return mid + 1;
        }
        if (arr[mid] < search) {
            left = mid + 1;
        } else {
            right = mid - 1;
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
    
    int result = binarySearch(arr, n, search);
    // độ phuức tạp thời gian của thuật toán tìm kiếm nhị phân là O(log n)
    if (result != -1) {
        printf("Phan tu vi tri thu: %d\n", result);
    } else {
        printf("Khong ton tai phan tu\n");
    }
    
    return 0;
}