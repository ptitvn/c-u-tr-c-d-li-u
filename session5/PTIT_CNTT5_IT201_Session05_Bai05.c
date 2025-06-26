#include <stdio.h>

int isPalindrome(char str[], int start, int end) {
    if (start >= end) {
        return 1;
    }
    if (str[start] != str[end]) {
        return 0; 
    }
    return isPalindrome(str, start + 1, end - 1);
}
int main() {
    char str[100];
    printf("Nhap chuoi: ");
    fgets(str, sizeof(str), stdin);
    
    // Loại bỏ ký tự newline nếu có
    str[strcspn(str, "\n")] = 0;
    
    int length = 0;
    while (str[length] != '\0') {
        length++;
    }
    
    if (isPalindrome(str, 0, length - 1)) {
        printf("la chuoi doi xung.\n");
    } else {
        printf(" khong phai la chuoi doi xung.\n");
    }
    
    return 0;
}