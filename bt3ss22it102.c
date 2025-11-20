#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SV 100

int main() {
    SinhVien danhSachSV[MAX_SV];
    int soLuongSV = 0;
    int luaChon;

    do {
        printf("\n--- CHUONG TRINH QUAN LY SINH VIEN ---\n");
        printf("1. Them sinh vien\n");
        printf("2. Sua thong tin sinh vien\n");
        printf("3. Xoa sinh vien\n");
        printf("4. Hien thi danh sach sinh vien\n");
        printf("0. Thoat chuong trinh\n");
        printf("Moi ban chon: ");
        scanf("%d", &luaChon);
        getchar();

        switch (luaChon) {
            case 1:
                themSinhVien(danhSachSV, &soLuongSV);
                break;
            case 2:
                suaSinhVien(danhSachSV, soLuongSV);
                break;
            case 3:
                xoaSinhVien(danhSachSV, &soLuongSV);
                break;
            case 4:
                hienThiDanhSach(danhSachSV, soLuongSV);
                break;
            case 0:
                printf("Thoat chuong trinh. Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai!\n");
                break;
        }
    } while (luaChon != 0);

    return 0;
}

