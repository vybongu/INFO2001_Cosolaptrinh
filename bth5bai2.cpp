#include <stdio.h>
#include <string.h>

#define MAX_STUDENTS 100


struct Student {
    char id[10];
    char name[50];
    float score;
};


struct Student studentList[MAX_STUDENTS];
int studentCount = 0;


void printStudentList() {
    printf("Danh sach sinh vien:\n");
    printf("%-10s %-20s %s\n", "ID", "Ten", "Diem");
    for (int i = 0; i < studentCount; i++) {
        printf("%-10s %-20s %.2f\n", studentList[i].id, studentList[i].name, studentList[i].score);
    }
}


void sortByName() {
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = 0; j < studentCount - i - 1; j++) {
            if (strcmp(studentList[j].name, studentList[j + 1].name) > 0) {
                // Hoán d?i v? trí
                struct Student temp = studentList[j];
                studentList[j] = studentList[j + 1];
                studentList[j + 1] = temp;
            }
        }
    }
    printf("Da sap xep danh sach sinh vien theo ten.\n");
    printStudentList();
}


void sortByScore() {
    for (int i = 0; i < studentCount - 1; i++) {
        for (int j = 0; j < studentCount - i - 1; j++) {
            if (studentList[j].score > studentList[j + 1].score) {
                // Hoán d?i v? trí
                struct Student temp = studentList[j];
                studentList[j] = studentList[j + 1];
                studentList[j + 1] = temp;
            }
        }
    }
    printf("Da sap xep danh sach sinh vien theo diem.\n");
    printStudentList();
}


void searchByName(char *name) {
    int left = 0;
    int right = studentCount - 1;
    int found = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (strcmp(studentList[mid].name, name) == 0) {
            printf("Tim thay sinh vien:\n");
            printf("%-10s %-20s %.2f\n", studentList[mid].id, studentList[mid].name, studentList[mid].score);
            found = 1;
            break;
        } else if (strcmp(studentList[mid].name, name) < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (!found) {
        printf("Khong tim thay sinh vien co ten \"%s\".\n", name);
    }
}


void searchById(char *id) {
    int left = 0;
    int right = studentCount - 1;
    int found = 0;

    while (left <= right) {
        int mid = (left + right) / 2;
        if (strcmp(studentList[mid].id, id) == 0) {
            printf("Tim thay sinh vien:\n");
            printf("%-10s %-20s %.2f\n", studentList[mid].id, studentList[mid].name, studentList[mid].score);
            found = 1;
            break;
        } else if (strcmp(studentList[mid].id, id) < 0) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }

    if (!found) {
        printf("Khong tim thay sinh vien co ID \"%s\".\n", id);
    }
}

int main() {
    int choice;

    do {
        printf("\nCHUONG TRINH QUAN LI SINH VIEN\n");
        printf("1. Khoi tao danh sach\n");
        printf("2. Them moi 1 sinh vien\n");
        printf("3. Sua thong tin sinh vien\n");
        printf("4. Sap xep danh sach\n");
        printf("5. Tim kiem thong tin sinh vien\n");
        printf("0. Thoat chuong trinh\n");
        printf("Lua chon cua ban la: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
               
                studentCount = 0;
                printf("Danh sach sinh vien da duoc khoi tao.\n");
                break;
            case 2: {
               
                if (studentCount < MAX_STUDENTS) {
                    struct Student newStudent;
                    printf("Nhap ID: ");
                    scanf("%s", newStudent.id);
                    printf("Nhap ten: ");
                    scanf("%s", newStudent.name);
                    printf("Nhap diem: ");
                    scanf("%f", &newStudent.score);

                    studentList[studentCount] = newStudent;
                    studentCount++;

                    printf("Them sinh vien thanh cong.\n");
                } else {
                    printf("Danh sach sinh vien da day, khong the them moi.\n");
                }
                break;
            }
            case 3: {
               
                char id[10];
                printf("Nhap ID sinh vien can sua: ");
                scanf("%s", id);

                int found = 0;
                for (int i = 0; i < studentCount; i++) {
                    if (strcmp(studentList[i].id, id) == 0) {
                        printf("Nhap ten moi: ");
                        scanf("%s", studentList[i].name);
                        printf("Nhap diem moi: ");
                        scanf("%f", &studentList[i].score);
                        found = 1;
                        printf("Sua thong tin sinh vien thanh cong.\n");
                        break;
                    }
                }

                if (!found) {
                    printf("Khong tim thay sinh vien co ID \"%s\".\n", id);
                }
                break;
            }
            case 4: {
              
                int sortChoice;
                printf("Sap xep theo:\n");
                printf("1. Ten\n");
                printf("2. Diem\n");
                printf("Lua chon cua ban: ");
                scanf("%d", &sortChoice);

                switch (sortChoice) {
                    case 1:
                        sortByName();
                        break;
                    case 2:
                        sortByScore();
                        break;
                    default:
                        printf("Lua chon khong hop le.\n");
                        break;
                }
                break;
            }
            case 5: {
               
                int searchChoice;
                printf("Tim kiem theo:\n");
                printf("1. Ten\n");
                printf("2. ID\n");
                printf("Lua chon cua ban: ");
                scanf("%d", &searchChoice);
                switch (searchChoice) {
                    case 1: {
                        char name[50];
                        printf("Nhap ten sinh vien can tim: ");
                        scanf("%s", name);
                        searchByName(name);
                        break;
                    }
                    case 2: {
                        char id[10];
                        printf("Nhap ID sinh vien can tim: ");
                        scanf("%s", id);
                        searchById(id);
                        break;
                    }
                    default:
                        printf("Lua chon khong hop le.\n");
                        break;
                }
                break;
            }
            case 0:
               
                printf("Cam on ban da su dung chuong trinh!\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
