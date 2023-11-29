#include <stdio.h>
#include <string.h>

#define MAX_EMPLOYEES 100


struct Employee {
    char employeeId[10];
    char name[50];
    char position[50];
    float salary;
};


struct Employee employeeList[MAX_EMPLOYEES];
int employeeCount = 0;


void addEmployee() {
    if (employeeCount < MAX_EMPLOYEES) {
        struct Employee newEmployee;
        printf("Nhap ma nhan vien: ");
        scanf("%s", newEmployee.employeeId);
        printf("Nhap ten nhan vien: ");
        scanf("%s", newEmployee.name);
        printf("Nhap chuc vu: ");
        scanf("%s", newEmployee.position);
        printf("Nhap luong: ");
        scanf("%f", &newEmployee.salary);

        employeeList[employeeCount] = newEmployee;
        employeeCount++;

        printf("Them nhan vien thanh cong.\n");
    } else {
        printf("Danh sach nhan vien da day, khong the them moi.\n");
    }
}


void deleteEmployee(char *employeeId) {
    int found = 0;
    for (int i = 0; i < employeeCount; i++) {
        if (strcmp(employeeList[i].employeeId, employeeId) == 0) {
            for (int j = i; j < employeeCount - 1; j++) {
                employeeList[j] = employeeList[j + 1];
            }
            employeeCount--;
            found = 1;
            printf("Xoa nhan vien thanh cong.\n");
            break;
        }
    }

    if (!found) {
        printf("Khong tim thay nhan vien co ma \"%s\".\n", employeeId);
    }
}


void displayEmployeeList() {
    printf("Danh sach nhan vien:\n");
    printf("%-10s %-20s %-20s %s\n", "Ma NV", "Ten", "Chuc vu", "Luong");
    for (int i = 0; i < employeeCount; i++) {
        printf("%-10s %-20s %-20s %.2f\n", employeeList[i].employeeId, employeeList[i].name, 
                employeeList[i].position, employeeList[i].salary);
    }
}


void sortByName() {
    for (int i = 0; i < employeeCount - 1; i++) {
        for (int j = 0; j < employeeCount - i - 1; j++) {
            if (strcmp(employeeList[j].name, employeeList[j + 1].name) > 0) {
               
                struct Employee temp = employeeList[j];
                employeeList[j] = employeeList[j + 1];
                employeeList[j + 1] = temp;
            }
        }
    }
    printf("Da sap xep danh sach nhan vien theo ten.\n");
    displayEmployeeList();
}

int main() {
    int choice;

    do {
        printf("\nCHUONG TRINH QUAN LY NHAN SU\n");
        printf("1. Them nhan vien\n");
        printf("2. Xoa nhan vien\n");
        printf("3. Hien thi danh sach nhan vien\n");
        printf("4. Sap xep danh sach nhan vien theo ten\n");
        printf("0. Thoat chuong trinh\n");
        printf("Lua chon cua ban la: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                addEmployee();
                break;
            case 2: {
                char employeeId[10];
                printf("Nhap ma nhan vien can xoa: ");
                scanf("%s", employeeId);
                deleteEmployee(employeeId);
                break;
            }
            case 3:
                displayEmployeeList();
                break;
            case 4:
                sortByName();
                break;
            case 0:
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    } while (choice != 0);

    return 0;
}
