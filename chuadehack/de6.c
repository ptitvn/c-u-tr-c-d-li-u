#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// bước 1 tạo cấu trúc
// cấu trúc của 1 dự án
typedef struct Project{
    int id;                            
    char title[100];                
    char owner[100];           
    int priority;                    
} Project;
// cấu trúc danh sách liên kết đơn
typedef struct  SNode{
    Project data;
    struct SNode *next; // con trỏ next lưu phần tử tiếp theo 
} SNode;

// cấu trúc danh sách liên kết đôi
typedef struct DNode{
    Project data;
    struct DNode *next;
    struct DNode *prev;
} DNode;

// bước 2 tạo các hàm chức năng
// tạo hàm thêm dự án mới
int nextId = 1;
SNode* addProject(SNode* head){
    Project project; // tạo 1 biến công viêc có kiểu dữ liệu là project
    project.id = nextId++;
    printf("moi nhap ten du an:");
    fgets(project.title, sizeof(project.title), stdin);
    project.title[strcspn(project.title, "\n")] = '\0';
    printf("moi nhap quan ly du an:");
    fgets(project.owner, sizeof(project.owner), stdin);
    project.owner[strcspn(project.owner, "\n")] = '\0';
    printf("moi nhap muc do uu tien:");
    scanf("%d", &project.priority);
    getchar();
    // tạo ô nhớ 
    SNode * newNode = (SNode*)malloc(sizeof(SNode));
    newNode->data = project;
    newNode->next = head;
    head = newNode;
    return head;

}
// hàm in danh sách gấn
void printProject(SNode *head){
    SNode * temp = head;
    while (temp != NULL)
    {
        printf("ma du an %d | ten du an %s | quan ly du an %s | muc do uu tien %d\n",temp->data.id,temp->data.title,temp->data.owner,temp->data.priority);
        temp = temp->next;
    }

}
// xóa phần tử
SNode * deleteProject(SNode* head, int id) {
    SNode * temp = head;
    SNode * prev = NULL;
    while (temp != NULL) {
        if (temp->data.id == id) {
            if (prev == NULL) {
                head = temp->next;
            }
            else {
                prev->next = temp->next;
            }
            free(temp);
            return head;
        }
        prev = temp;
        temp = temp->next;

    }
    printf("Khong có cong viec theo id");
    return head;
}

DNode *updateProject(SNode *head, int id) {
    SNode * temp = head;
    int check = 0;
    while (temp != NULL) {
        if (temp->data.id == id) {
            check = 1;
            temp-> data.id = id;
            printf("Nhap ten du an moi");
            fgets(temp->data.title, sizeof(temp->data.title), stdin);
            temp->data.title[strcspn(temp->data.title, "\n")] = '\0';
            printf("Nhap quan ly du an moi");
            fgets(temp->data.owner, sizeof(temp->data.owner), stdin);
            temp->data.owner[strcspn(temp->data.owner, "\n")] = '\0';
            printf("Nhap muc do uu tien moi");
            scanf("%d", &temp->data.priority);
            getchar();
        }

        temp = temp->next;
    }
    if (check == 0) {
        printf("Khong co du an");
    }

}
// hàm đánh dấu dự án hoàn thành 
void markProjectCompleted(SNode *head, int id) {
    SNode *temp = head;
    while (temp != NULL) {
        if (temp->data.id == id) {
            printf("Du an %d da duoc danh dau la hoan thanh.\n", id);
            return;
        }
        temp = temp->next;
    }
    printf("Khong co du an voi id %d.\n", id);
}
// hàm sắp xếp dự án theo độ ưu tiên
void sortProjectsByPriority(SNode *head) {
    if (head == NULL || head->next == NULL) {
        return; // Danh sách rỗng hoặc chỉ có một phần tử
    }

    SNode *i, *j;
    Project temp;

    for (i = head; i->next != NULL; i = i->next) {
        for (j = i->next; j != NULL; j = j->next) {
            if (i->data.priority < j->data.priority) {
                // Hoán đổi dữ liệu
                temp = i->data;
                i->data = j->data;
                j->data = temp;
            }
        }
    }
}
// hàm tìm kiếm dự án theo tên
SNode* searchProjectByName(SNode *head, const char *name) {
    SNode *temp = head;
    while (temp != NULL) {
        if (strcmp(temp->data.title, name) == 0) {
            return temp; // Trả về nút tìm thấy
        }
        temp = temp->next;
    }
    return NULL; // Không tìm thấy
}


// bước 3 triển khai các hàm trong main
int main() {
    int choice;
    SNode* head = NULL;
    DNode* headD = NULL;
    do
    {
        printf("menu\n");
        printf("1. Them du an\n");
        printf("2. hien thi thong tin du an\n");
        printf("3. Xoa theo id\n");
        printf("4. Cap nhat thong tin\n");
        printf("5. danh dau du an da hoan thanh\n");
        printf("6. Sap xep du an theo do uu tien\n");
        printf("7. tim kiem du an theo ten\n");
        printf("nhap lua chon:");
        scanf("%d", &choice);
        getchar();
        switch (choice)
        {
        case 1:
            head = addProject(head);
            break;
        case 2:
            printProject(head);
            break;
        case 3:
            
                int id;
                printf("nhap id can xoa");
                scanf("%d", &id);
                getchar();
                headD = deleteProject(head,id);
            break;
        case 4:

                printf("nhap id can cap nhat");
                scanf("%d", &id);
                getchar();
                headD = updateProject(head,id);
            break;
        case 5:
         
                printf("nhap id can danh dau hoan thanh");
                scanf("%d", &id);
                getchar();
                markProjectCompleted(head, id);
            break;
        case 6:
                sortProjectsByPriority(head);
            break;
        case 7:
            {
                char name[100];
                printf("Nhap ten du an can tim: ");
                fgets(name, sizeof(name), stdin);
                name[strcspn(name, "\n")] = '\0'; // Loại bỏ ký tự newline
                SNode* foundProject = searchProjectByName(head, name);
                if (foundProject != NULL) {
                    printf("Du an tim thay: ID: %d, Ten: %s, Quan ly: %s, Uu tien: %d\n",
                           foundProject->data.id, foundProject->data.title,
                           foundProject->data.owner, foundProject->data.priority);
                } else {
                    printf("Khong tim thay du an voi ten '%s'.\n", name);
                }
            }
            break;

        default:
                printf("Khong hop le");
            break;
        }
    } while (choice != 8);

}