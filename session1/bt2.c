#include <stdio.h>
int main() {
    void printDouble(int n){
        int i =1;
        while(i<n) {
            printf("%d\n",i);
            i *=2;
        }

    }
    return 0;
}
// độ phức tạp thời gian của đoạn mã này là O(log n) vì vòng lặp while chạy logarit cơ số 2 của n lần.