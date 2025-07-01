#include <stdio.h>

void insertionSort(int arr[], int n) {
    for (int i = 1; i < n; i++) {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}
int linearSearch(int arr[], int n, int search) {
    for (int i = 0; i < n; i++) {
        if (arr[i] == search) {
            return i + 1; 
        }
    }
    return -1; 
}
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
    
    printf("Mang ban dau:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    insertionSort(arr, n);
    
    printf("Mang sau khi sap xep:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    
    int search;
    printf("Nhap gia tri can tim kiem: ");
    scanf("%d", &search);
    
    int linearResult = linearSearch(arr, n, search);
    if (linearResult != -1) {
        printf("Tim thay phan tu tuyen tinh o vi tri thu: %d\n", linearResult);
    } else {
        printf(" Khong ton tai phan tu tuyen tinh \n");
    }
    
    int binaryResult = binarySearch(arr, n, search);
    if (binaryResult != -1) {
        printf("tim thay phan tu nhi phan o vi tri thu: %d\n", binaryResult);
    } else {
        printf("Khong ton tai phan tu nhi phan\n");
    }
    
    return 0;
}