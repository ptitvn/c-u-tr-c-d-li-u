#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Hàm tìm số lớn nhất trong mảng 2 chiều
int findMax(int **matrix, int rows, int cols) {
    int max = INT_MIN;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] > max) {
                max = matrix[i][j];
            }
        }
    }
    return max;
}

// Hàm tìm số nhỏ nhất trong mảng 2 chiều
int findMin(int **matrix, int rows, int cols) {
    int min = INT_MAX;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            if (matrix[i][j] < min) {
                min = matrix[i][j];
            }
        }
    }
    return min;
}

int main() {
    int rows, cols;
    
    printf("Nhap so hang (rows): ");
    scanf("%d", &rows);
    printf("Nhap so cot (cols): ");
    scanf("%d", &cols);
    
    // Kiểm tra điều kiện hợp lệ
    if (rows <= 0 || cols <= 0 || rows >= 1000 || cols >= 1000) {
        if (rows <= 0 && cols <= 0) {
            printf("So cot va so hang khong hop le\n");
        } else if (rows <= 0) {
            printf("So hang khong hop le\n");
        } else if (cols <= 0) {
            printf("So cot khong hop le\n");
        } else {
            printf("So hang hoac so cot vuot qua gioi han\n");
        }
        return 0;
    }
    
    // Cấp phát bộ nhớ cho ma trận
    int **matrix = (int **)malloc(rows * sizeof(int *));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int *)malloc(cols * sizeof(int));
    }
    
    // Nhập giá trị cho ma trận
    printf("Nhap cac phan tu cua ma tran:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Phan tu [%d][%d]: ", i, j);
            scanf("%d", &matrix[i][j]);
        }
    }
    
    // Tìm và in kết quả
    printf("max = %d\n", findMax(matrix, rows, cols));
    printf("min = %d\n", findMin(matrix, rows, cols));
    
    // Giải phóng bộ nhớ
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
    
    return 0;
}
