#include <stdio.h>

void sortString(char *str) {
    int n = 0;
    while (str[n] != '\0') n++; 

    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - i - 1; j++) {
            if (str[j] > str[j + 1]) {
                char temp = str[j];
                str[j] = str[j + 1];
                str[j + 1] = temp;
            }
        }
    }
}
int main() {
    char str[100];
    
    printf("Nhap chuoi ky tu: ");
    fgets(str, sizeof(str), stdin);
    
    int len = 0;
    while (str[len] != '\0') len++;
    if (len > 0 && str[len - 1] == '\n') {
        str[len - 1] = '\0';
        len--;
    }

    if (len == 0) {
        printf("Chuoi khong hop le.\n");
        return 1;
    }
    printf("Chuoi truoc khi sap xep: %s\n", str);
    
    sortString(str);
    
    printf("Chuoi sau khi sap xep: %s\n", str);
    
    return 0;
}