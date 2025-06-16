#include <stdio.h>
#include <stdbool.h>

// Cách 1: So sánh từng cặp phần tử ⇒ O(n^2)
bool hasDuplicateBruteForce(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] == arr[j]) {
                return true;
            }
        }
    }
    return false;
}

// Cách 2: Dùng mảng đánh dấu (áp dụng khi phần tử từ 0–1000) ⇒ O(n)
bool hasDuplicateUsingCount(int arr[], int n) {
    int count[1001] = {0}; // Mảng tần suất

    for (int i = 0; i < n; i++) {
        if (count[arr[i]] > 0) {
            return true;
        }
        count[arr[i]]++;
    }
    return false;
}

int main() {
    int arr[] = {3, 5, 7, 1, 3}; 
    int n = sizeof(arr) / sizeof(arr[0]);

    // Kiểm tra theo cách 1
    if (hasDuplicateBruteForce(arr, n)) {
        printf("Cách 1: Mảng có phần tử trùng lặp.\n");
    } else {
        printf("Cách 1: Mảng không có phần tử trùng lặp.\n");
    }

    // Kiểm tra theo cách 2
    if (hasDuplicateUsingCount(arr, n)) {
        printf("Cách 2: Mảng có phần tử trùng lặp.\n");
    } else {
        printf("Cách 2: Mảng không có phần tử trùng lặp.\n");
    }

    return 0;
}