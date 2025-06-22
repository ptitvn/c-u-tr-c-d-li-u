#include <stdio.h>
// hàm nhập mảng 2 chiều
void inputArray(int rows, int cols, int array[rows][cols]) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Nhap phan tu [%d][%d]: ", i, j);
            scanf("%d", &array[i][j]);
        }
    }
}
// hàm tính tổng các phần tử trong hàng k
int sumRow(int rows, int cols, int array[rows][cols], int k) {
    if (k < 0 || k >= rows) {
        return -1; // Hàng không tồn tại
    }
    int sum = 0;
    for (int j = 0; j < cols; j++) {
        sum += array[k][j];
    }
    return sum;
}

int main() {
    int rows, cols;
    printf("Nhap so hang   (rows) va so cot (cols): ");
    scanf("%d %d", &rows, &cols);    
    if (rows <= 0 || rows > 1000 || cols <= 0 || cols > 1000) {
        printf("So hang va so cot khong hop le\n");
        return 1;
    }

    int array[rows][cols];
    printf("Nhap cac phan tu cua mang 2 chieu:\n");
    inputArray(rows, cols, array);

    int k;
    printf("Nhap hang can tinh tong(k): ");
    scanf("%d", &k);

    int result = sumRow(rows, cols, array, k);
    if (result == -1) {
        printf("Hang can tinh tong khong ton tai.\n");
    } else {
        printf("Tong cac phan tu cua hang %d la: %d\n", k, result);
    }

    return 0;
}
