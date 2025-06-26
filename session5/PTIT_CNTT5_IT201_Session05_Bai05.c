#include <stdio.h>
int main (){
 
    char str[100];
    printf("Nhap mot chuoi: ");
    fgets(str, sizeof(str), stdin);
    // Loại bỏ ký tự newline nếu có
    str[strcspn(str, "\n")] = 0;
    int len = 0;
    // Tính độ dài của chuỗi
    while (str[len] != '\0') {
        len++;
    }
    int isPalindrome = 1; 
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[len - i - 1]) {
            isPalindrome = 0; 
            break;
        }
    }

    if (isPalindrome) {
        printf("Palindrome valid.\n");
    } else {
        printf("Palindrome invalid.\n");
    }

    return 0;
}