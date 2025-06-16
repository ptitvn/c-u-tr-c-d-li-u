#include <stdio.h>
#include <stdbool.h>
// cách 1 : 

bool hasDuplicateBruteForce(int arr[], int n) {
    // So sánh từng cặp phần tử trong mảng ⇒ O(n^2)
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                return true;
            }
        }
    }
    return false;
}
// cách 2 :

bool hasDuplicateUsingCount(int arr[], int n) {
    // Mảng đánh dấu tần suất xuất hiện ⇒ O(n)
    int count[1001] = {0}; 

    for (int i = 0; i < n; i++) {
        if (count[arr[i]] > 0) {
            return true; 
        }
        count[arr[i]]++;
    }
    return false;
}
//- Độ phức tạp thời gian: O(n²)
//- Độ phức tạp không gian: O(1)