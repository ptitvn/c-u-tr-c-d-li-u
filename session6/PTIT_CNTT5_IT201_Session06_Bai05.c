#include <stdio.h>

int findMax(int arr[], int n) {
    if (n == 1) return arr[0];
    int max = findMax(arr, n - 1);
    return (arr[n - 1] > max) ? arr[n - 1] : max;
}
int findMin(int arr[], int n) {
    if (n == 1) return arr[0];
    int min = findMin(arr, n - 1);
    return (arr[n - 1] < min) ? arr[n - 1] : min;
}
int main() {
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("So luong phan tu phai la so nguyen duong.\n");
        return 1;
    }
    
    int arr[n];
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    
    int max = findMax(arr, n);
    int min = findMin(arr, n);
    
    printf("Phan tu lon nhat trong mang: %d\n", max);
    printf("Phan tu nho nhat trong mang: %d\n", min);
    
    return 0;
}