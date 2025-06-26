#include <stdio.h>

int main(){
    
    char str[100];
    printf("Nhap chuoi ky tu so: ");
    fgets(str, sizeof(str), stdin);
    // Loại bỏ ký tự newline nếu có
    str[strcspn(str, "\n")] = 0;
    int i = 0;
    long long number = 0;
    while (str[i] != '\0') {
        if (str[i] >= '0' && str[i] <= '9') {
            number = number * 10 + (str[i] - '0');
        } else {
            printf("Chuoi ky tu so khong hop le!\n");
            return 1; 
        }
        i++;
    }
    printf("So nguyen tu chuoi ky tu so la: %lld\n", number);
    
    return 0;
}