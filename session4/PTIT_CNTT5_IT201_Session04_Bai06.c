#include <stdio.h>
int main (){
    //Khởi tạo cấu trúc Student có các thuộc tính: id, name, age
    struct Student {
        int id;
        char name[50];
        int age;
    };
    // Nhập thông tin cho 5 sinh viên.
    struct Student students[5];
    for (int i = 0; i < 5; i++) {
        printf("Nhap thong tin sinh vien thu %d:\n", i + 1);
        printf("ID: ");
        scanf("%d", &students[i].id);
        printf("Name: ");
        scanf(" %[^\n]", students[i].name);
        printf("age: ");
        scanf("%d", &students[i].age);
    }
    // Tiến hành tìm kiếm sinh viên theo ID.
    int searchId;
    printf("Nhap ID sinh vien can tim: ");
    scanf("%d", &searchId);
    int found = 0;
    for (int i = 0; i < 5; i++) {
        if (students[i].id == searchId) {
            printf("Thong tin sinh vien co ID %d:\n", searchId);
            printf("Name: %s\n", students[i].name);
            printf("age: %d\n", students[i].age);
            found = 1; 
            break; 
    }
    }
    if (!found) {
        printf("Sinh vien khong ton tai.\n");
    }
}