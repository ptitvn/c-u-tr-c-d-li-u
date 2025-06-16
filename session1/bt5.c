#include <stdio.h>

// Hàm hoán đổi giá trị hai phần tử
void hoanDoi(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Hàm sắp xếp mảng bằng thuật toán Bubble Sort
void sapXepBubbleSort(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                hoanDoi(&arr[j], &arr[j + 1]);  
            }
        }
    }
    // Độ phức tạp thời gian: O(n^2) 
}

void inMang(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

int main() {
    int n;
    printf("Nhap so luong phan tu: ");
    scanf("%d", &n);

    int arr[n];
    printf("Nhap cac phan tu:\n");
    for (int i = 0; i < n; i++) {
        printf("arr[%d] = ", i);
        scanf("%d", &arr[i]);
    }

    printf("Mang truoc khi sap xep: ");
    inMang(arr, n);

    sapXepBubbleSort(arr, n);

    printf("Mang sau khi sap xep: ");
    inMang(arr, n);

    return 0;
}