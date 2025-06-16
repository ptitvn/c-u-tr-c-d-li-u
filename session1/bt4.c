#include <stdio.h>

// Cách 1: Tính tổng bằng vòng lặp 
int tinhTongVongLap(int n) {
    int tong = 0;
    for (int i = 1; i <= n; i++) {
        tong += i;  
    }
    return tong;
    // Độ phức tạp thời gian: O(n), vì chạy n lần lặp
}

// Cách 2: Tính tổng bằng công thức toán học: S = n * (n + 1) / 2
int tinhTongCongThuc(int n) {
    return n * (n + 1) / 2;
    // Độ phức tạp thời gian: O(1), vì chỉ thực hiện một phép tính
}

int main() {
    int n;
    printf("Nhap n: ");
    scanf("%d", &n);

    int tong1 = tinhTongVongLap(n);
    int tong2 = tinhTongCongThuc(n);

    printf("Tong bang vong lap: %d\n", tong1);
    printf("Tong bang cong thuc: %d\n", tong2);

    return 0;
}