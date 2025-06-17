#include <stdio.h>
// Hàm để tìm các phần tử lớn hơn các phần tử đứng sau nó
void findElements(int arr[], int n) {
    printf("Cac phan tu lon hon dung sau no la: ");
    for (int i = 0; i < n; i++) {
        int isGreater = 1; 
        for (int j = i + 1; j < n; j++) {
            if (arr[i] <= arr[j]) {
                isGreater = 0; 
                break;
            }
        }
        if (isGreater) {
            printf("%d ", arr[i]);
        }
    }
    printf("\n");
}

int main() {
    int n;
    printf("Nhap so phan tu cua mang : ");
    scanf("%d", &n);

    int arr[n];
    printf("Nhap cac phan tu cua mang: ");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    findElements(arr, n);

    return 0;
}
