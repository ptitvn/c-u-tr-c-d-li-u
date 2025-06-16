#include <stdio.h>
int main () {
    int * mallocArray(int n ){
        int * arr = (int * )malloc(n * sizeof(int));
        for (int i = 0; i < n; i++) {
            arr[i]=i;
        }
        return arr;
    }
    return 0;
}
// độ phức tạp không gian của đoạn mã này là O(n) vì mảng được cấp phát động có kích thước n và chiếm O(n) bộ nhớ.