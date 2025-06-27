#include <stdio.h>

int convertToInt(char str[], int index) {
    if (str[index] == '\0') {
        return 0;
    }
    
    return (str[index] - '0') + 10 * convertToInt(str, index + 1);
}
int main() {
    char str[100];
    printf("Nhap chuoi ky tu so: ");
    fgets(str, sizeof(str), stdin);
    
    str[strcspn(str, "\n")] = 0;
    
    int result = convertToInt(str, 0);
    printf("So nguyen tu chuoi '%s' la: %d\n", str, result);
    
    return 0;

}
