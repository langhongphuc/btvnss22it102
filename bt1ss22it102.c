#include <stdio.h>
#include <string.h>
#define MAX 10 

struct Student {
	char name[20];
	int age;
	float grade; 
}; 

struct Student students[10];
int numStudents = 0;

void displayMenu(){
	printf("----------MENU----------\n");
	printf("1. Nhap thong tin hoc sinh\n");
	printf("2. Hien thi thong tin cua hoc sinh\n");
	printf("3. Tinh diem trung binh cua tat ca hoc sinh\n"); 
}

void inputStudent() {
	if(numStudents >= MAX) {
		printf("Day la danh sach hoc sinh");
		return; 
	}
	printf("Nhap ten hoc sinh:");
	scanf("%s", students[numStudents].name);
	printf("Nhap tuoi hoc sinh:");
	scanf("%d", &students[numStudents].age);
	printf("Nhap diem trung binh:");
	scanf("%d", &students[numStudents].grade);
	
	numStudents++;
	printf("Da nhap thong tin cho %d hoc sinh\n"); 
}

void displayStudents() {
	if(numStudents == 0){
		printf("Chua co thong tin sinh vien nao\n");
		return; 
	}
	printf("---Danh sach hoc sinh---\n");
	for(int i = 0; i< numStudents; i++) {
		printf("Sinh vien %d:\n", i + 1);
		printf("Ten:%s", students[i].name);
		printf("Tuoi:%d", students[i].age);
		printf("Diem:%.2f", students[i].grade); 
	}
}

void tinhTongDiemTrungBinh() {
	if(numStudents == 0) {
		printf("Chua co thong tin hoc sinh de tinh diem trung binh!");
		return; 
	}
	float tongDiem = 0;
	for(int i = 0; i < numStudents; i++) {
		tongDiem += students[i].grade; 
	}
	float diemTrungBinh = tongDiem / numStudents;
	printf("Diem trung binh cua %d hoc sinh la:%.2f\n", numStudents, tongDiem); 
}

int main() {
	int choose;
	do {
		displayMenu();
		printf("Nhap lua chon cua ban:");
		scanf("%d", &choose);
		
		switch(choose){
			case 1:
			inputStudent();
			break;
			
			case 2:
			displayStudents();
			break;
			
			case 3:
			tinhTongDiemTrungBinh();
			
			default:
			printf("Lua chon khong hop le!"); 
		} 
	} while(choose != 3);
	
	return 0; 
}
