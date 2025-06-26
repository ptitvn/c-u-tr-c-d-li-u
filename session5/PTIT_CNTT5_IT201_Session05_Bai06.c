#include <stdio.h>
int main (){
    int n;
    printf("Nhap so luong phan tu cua mang: ");
    scanf("%d", &n);
    if (n <= 0) {
        printf("Khong hop le! \n");
        return 1; 
    }
    int arr[n];
    printf("Nhap cac phan tu cua mang:\n");
    for (int i = 0; i < n; i++) {
        printf("Phan tu %d: ", i + 1);
        scanf("%d", &arr[i]);
    }
    long long sum = 0;
    for (int i = 0; i < n; i++) {
        sum += arr[i];
    }
    printf("Tong cac phan tu trong mang la: %lld\n", sum);
    return 0;
}