#include <stdio.h>

void fibonacci(int n, int arr[], int index) {
    if (index >= n) {
        return; 
    }
    if (index == 0) {
        arr[index] = 0; 
    } else if (index == 1) {
        arr[index] = 1;
    } else {
        arr[index] = arr[index - 1] + arr[index - 2]; 
    }
    fibonacci(n, arr, index + 1); 
}
int main() {
    int n;
    printf("Nhap so luong so Fibonacci can tim: ");
    scanf("%d", &n);
    
    if (n <= 0) {
        printf("So luong phai lon hon 0.\n");
        return 1; 
    }
    int arr[n]; 
    fibonacci(n, arr, 0); 
    
    printf("Cac so Fibonacci dau tien la: ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]); 
    }
    printf("\n");
    
    return 0;
}