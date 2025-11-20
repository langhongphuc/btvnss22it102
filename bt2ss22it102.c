#include <stdio.h>
#include <string.h>
#define MAX_CONTACTS 100
#define NAME_LENGTH 50
#define PHONE_LENGTH 15
#define EMAIL_LENGTH 50

struct Contact {
    char name[NAME_LENGTH];
    char phoneNumber[PHONE_LENGTH];
    char email[EMAIL_LENGTH];
};

struct Contact contacts[MAX_CONTACTS];
int contactCount = 0;

void addContact() {
    if (contactCount >= MAX_CONTACTS) {
        printf("Danh ba da day. Khong the them lien he moi.\n");
        return;
    }

    printf("Nhap ten: ");
    getchar(); 
    fgets(contacts[contactCount].name, NAME_LENGTH, stdin);
    contacts[contactCount].name[strcspn(contacts[contactCount].name, "\n")] = '\0';

    printf("Nhap so dien thoai: ");
    fgets(contacts[contactCount].phoneNumber, PHONE_LENGTH, stdin);
    contacts[contactCount].phoneNumber[strcspn(contacts[contactCount].phoneNumber, "\n")] = '\0';

    printf("Nhap email: ");
    fgets(contacts[contactCount].email, EMAIL_LENGTH, stdin);
    contacts[contactCount].email[strcspn(contacts[contactCount].email, "\n")] = '\0';

    contactCount++;
    printf("Da them lien he thanh cong!\n");
}

void displayAllContacts() {
    if (contactCount == 0) {
        printf("Danh ba trong.\n");
        return;
    }

    printf("\n--- Danh sach lien he ---\n");
    for (int i = 0; i < contactCount; i++) {
        printf("Lien he %d:\n", i + 1);
        printf("  Ten: %s\n", contacts[i].name);
        printf("  So dien thoai: %s\n", contacts[i].phoneNumber);
        printf("  Email: %s\n", contacts[i].email);
        printf("-------------------------\n");
    }
}


void searchContactByName() {
    char searchName[NAME_LENGTH];
    int found = 0;

    printf("Nhap ten can tim kiem: ");
    getchar(); 
    fgets(searchName, NAME_LENGTH, stdin);
    searchName[strcspn(searchName, "\n")] = '\0';

    printf("\n--- Ket qua tim kiem ---\n");
    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].name, searchName) == 0) {
            printf("Tim thay lien he:\n");
            printf("  Ten: %s\n", contacts[i].name);
            printf("  So dien thoai: %s\n", contacts[i].phoneNumber);
            printf("  Email: %s\n", contacts[i].email);
            printf("-------------------------\n");
            found = 1;
        }
    }

    if (!found) {
        printf("Khong tim thay lien he co ten \"%s\".\n", searchName);
    }
}

void deleteContactByName() {
    char deleteName[NAME_LENGTH];
    int foundIndex = -1;

    printf("Nhap ten can xoa: ");
    getchar(); 
    fgets(deleteName, NAME_LENGTH, stdin);
    deleteName[strcspn(deleteName, "\n")] = '\0';

    for (int i = 0; i < contactCount; i++) {
        if (strcmp(contacts[i].name, deleteName) == 0) {
            foundIndex = i;
            break;
        }
    }

    if (foundIndex != -1) {
        for (int i = foundIndex; i < contactCount - 1; i++) {
            contacts[i] = contacts[i + 1];
        }
        contactCount--;
        printf("Da xoa lien he co ten \"%s\" thanh cong!\n", deleteName);
    } else {
        printf("Khong tim thay lien he co ten \"%s\" de xoa.\n", deleteName);
    }
}

int getMenuChoice() {
    int choice;
    printf("\n--- MENU DANH BA ---\n");
    printf("1. Them lien he moi\n");
    printf("2. Hien thi tat ca lien he\n");
    printf("3. Tim kiem theo ten\n");
    printf("4. Xoa lien he theo ten\n");
    printf("5. Thoat\n");
    printf("Nhap lua chon cua ban: ");
    scanf("%d", &choice);
    return choice;
}

int main() {
    int choice;
    do {
        choice = getMenuChoice();
        switch (choice) {
            case 1:
                addContact();
                break;
            case 2:
                displayAllContacts();
                break;
            case 3:
                searchContactByName();
                break;
            case 4:
                deleteContactByName();
                break;
            case 5:
                printf("Thoat chuong trinh.\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    } while (choice != 5);

    return 0;
}

