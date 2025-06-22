#include <stdio.h>
#include <stdlib.h>

// Hàm tính tổng đường chéo chính
int sumMainDiagonal(int **matrix, int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += matrix[i][i];
    }
    return sum;
}

// Hàm tính tổng đường chéo phụ
int sumSecondaryDiagonal(int **matrix, int size) {
    int sum = 0;
    for(int i = 0; i < size; i++) {
        sum += matrix[i][size-1-i];
    }
    return sum;
}

int main() {
    int rows, cols;
    
    printf("Nhap so hang: ");
    scanf("%d", &rows);
    printf("Nhap so cot: ");
    scanf("%d", &cols);

    // Kiểm tra điều kiện
    if(rows <= 0 && cols <= 0) {
        printf("So cot va so hang khong hop le\n");
        return 0;
    }
    else if(rows <= 0) {
        printf("so hang khong hop le\n");
        return 0;
    }
    else if(cols <= 0) {
        printf("So cot khong hop le\n");
        return 0;
    }

    // Cấp phát bộ nhớ cho ma trận
    int **matrix = (int**)malloc(rows * sizeof(int*));
    for(int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }

    // Nhập giá trị cho ma trận
    printf("Nhap cac phan tu khong ma tran:\n");
    for(int i = 0; i < rows; i++) {
        for(int j = 0; j < cols; j++) {
            printf("Phan tu [%d][%d]: ", i, j);
            scanf(" %d", &matrix[i][j]);
        }
    }

    // Kiểm tra và tính toán
    if(rows == cols) {
        printf("Tong duong cheo chinh = %d\n", sumMainDiagonal(matrix, rows));
        printf("Tong duong cheo phu = %d\n", sumSecondaryDiagonal(matrix, rows));
    }
    else {
        printf("Khong ton tai duong cheo chinh \n");
        printf("Khong ton tai duong cheo phu \n");
    }

    // Giải phóng bộ nhớ
    for(int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);

    return 0;
}
