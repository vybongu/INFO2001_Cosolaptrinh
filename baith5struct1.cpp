#include<stdio.h>
#include<string.h>


typedef struct {
  char name[50]; 
  int id;
  float gpa; 
} Student;


void inputStudent(Student *s) {
  printf("Nhap ten sinh vien: ");
  scanf("%s", s->name);
  printf("Nhap ma so sinh vien: ");
  scanf("%d", &s->id);
  printf("Nhap diem trung binh: ");
  scanf("%f", &s->gpa);
}


void displayStudent(Student s) {
  printf("Ten sinh vien: %s\n", s.name);
  printf("Ma so sinh vien: %d\n", s.id);
  printf("Diem trung binh: %.2f\n", s.gpa);
}

void updateStudent(Student *arr, int n, int id) {
  
  for (int i = 0; i < n; i++) {
    if (arr[i].id == id) {
     
      printf("Nhap thong tin moi cho sinh vien co ma so %d\n", id);
      inputStudent(&arr[i]);
      return;
    }
  }
  
  printf("Khong tim thay sinh vien co ma so %d\n", id);
}


void initStudent(Student *arr, int n) {
  
  for (int i = 0; i < n; i++) {
    printf("Nhap thong tin cho sinh vien thu %d\n", i + 1);
    inputStudent(&arr[i]);
  }
}


void addStudent(Student *arr, int *n) {
  
  if (*n == 50) {
    printf("Danh sach da day, khong the them moi\n");
    return;
  }
  
  printf("Nhap thong tin cho sinh vien moi\n");
  inputStudent(&arr[*n]);
 
  (*n)++;
}


void sortStudent(Student *arr, int n) {
  
  for (int i = 0; i < n - 1; i++) {
  
    int max = i;
    for (int j = i + 1; j < n; j++) {
      if (arr[j].gpa > arr[max].gpa) {
        max = j;
      }
    }
    
    Student temp = arr[i];
    arr[i] = arr[max];
    arr[max] = temp;
  }
}


void searchStudent(Student *arr, int n, char *name) {
  
  for (int i = 0; i < n; i++) {
    
    if (strcmp(arr[i].name, name) == 0) {
     
      displayStudent(arr[i]);
      return;
    }
  }
  
  printf("Khong tim thay sinh vien co ten %s\n", name);
}


int main() {
 
  Student students[50];
 
  int choice = 0;
  int n = 0;
  do {
   
    printf("CHUONG TRINH QUAN LI SINH VIEN\n");
    printf("1.Khoi tao danh sach:\n");
    printf("2.Them moi 1 sinh vien:\n");
    printf("3.Sua thong tin sinh vien:\n");
    printf("4.Sap xep danh sach\n");
    printf("5.Tim kiem thong tin sinh vien\n");
    printf("0.Thoat chuong trinh\n");
    printf("Lua chon cua ban la :");
   
    scanf("%d", &choice);
    
    switch (choice) {
      case 1:
        
        printf("Nhap so luong sinh vien: ");
        scanf("%d", &n);
       
        initStudent(students, n);
        break;
      case 2:
        
        addStudent(students, &n);
        break;
      case 3:
       
        int id;
        printf("Nhap ma so sinh vien can cap nhat: ");
        scanf("%d", &id);
       
        updateStudent(students, n, id);
        break;
      case 4:
       
        sortStudent(students, n);
        
        printf("Danh sach sinh vien sau khi sap xep:\n");
        for (int i = 0; i < n; i++) {
          displayStudent(students[i]);
        }
        break;
      case 5:
      
        char name[50];
        printf("Nhap ten sinh vien can tim kiem: ");
        scanf("%s", name);
