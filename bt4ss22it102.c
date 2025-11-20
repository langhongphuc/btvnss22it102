#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_ORDERS 100
#define MAX_STRING_LENGTH 50

typedef struct {
    int ngay;
    int thang;
    int nam;
} NgayDatHang;

typedef struct {
    char maDonHang[MAX_STRING_LENGTH];
    char tenKhachHang[MAX_STRING_LENGTH];
    NgayDatHang ngayDatHang;
    double tongTien;
    char trangThai[MAX_STRING_LENGTH];
} DonHang;

DonHang danhSachDonHang[MAX_ORDERS];
int soDonHang = 0;

void xoaXuongDong(char *str) {
    str[strcspn(str, "\n")] = 0;
}

void nhapThongTinDonHang() {
    if (soDonHang >= MAX_ORDERS) {
        printf("Danh sach don hang da day.\n");
        return;
    }

    printf("--- Nhap thong tin don hang moi ---\n");
    printf("Ma don hang: ");
    fgets(danhSachDonHang[soDonHang].maDonHang, MAX_STRING_LENGTH, stdin);
    xoaXuongDong(danhSachDonHang[soDonHang].maDonHang);

    printf("Ten khach hang: ");
    fgets(danhSachDonHang[soDonHang].tenKhachHang, MAX_STRING_LENGTH, stdin);
    xoaXuongDong(danhSachDonHang[soDonHang].tenKhachHang);

    printf("Ngay dat hang (ngay thang nam): ");
    scanf("%d %d %d", &danhSachDonHang[soDonHang].ngayDatHang.ngay,
          &danhSachDonHang[soDonHang].ngayDatHang.thang,
          &danhSachDonHang[soDonHang].ngayDatHang.nam);

    printf("Tong tien: ");
    scanf("%lf", &danhSachDonHang[soDonHang].tongTien);
    
    while (getchar() != '\n'); 

    strcpy(danhSachDonHang[soDonHang].trangThai, "Dang xu ly");
    printf("Trang thai mac dinh: Dang xu ly\n");

    soDonHang++;
    printf("Don hang da duoc them thanh cong!\n");
}

void hienThiDonHang() {
    if (soDonHang == 0) {
        printf("Chua co don hang nao de hien thi.\n");
        return;
    }

    printf("--- Danh sach don hang ---\n");
    for (int i = 0; i < soDonHang; i++) {
        printf("----------------------------\n");
        printf("Ma don hang: %s\n", danhSachDonHang[i].maDonHang);
        printf("Ten khach hang: %s\n", danhSachDonHang[i].tenKhachHang);
        printf("Ngay dat hang: %d/%d/%d\n", danhSachDonHang[i].ngayDatHang.ngay,
               danhSachDonHang[i].ngayDatHang.thang,
               danhSachDonHang[i].ngayDatHang.nam);
        printf("Tong tien: %.2f\n", danhSachDonHang[i].tongTien);
        printf("Trang thai: %s\n", danhSachDonHang[i].trangThai);
    }
    printf("----------------------------\n");
}

void capNhatTrangThai() {
    char ma[MAX_STRING_LENGTH];
    printf("Nhap ma don hang can cap nhat: ");
    fgets(ma, MAX_STRING_LENGTH, stdin);
    xoaXuongDong(ma);

    for (int i = 0; i < soDonHang; i++) {
        if (strcmp(danhSachDonHang[i].maDonHang, ma) == 0) {
            int luaChon;
            printf("Chon trang thai moi:\n");
            printf("1. Da giao\n");
            printf("2. Huy\n");
            printf("Nhap lua chon: ");
            scanf("%d", &luaChon);
            while (getchar() != '\n'); // Xóa b? ð?m

            if (luaChon == 1) {
                strcpy(danhSachDonHang[i].trangThai, "Da giao");
                printf("Da cap nhat trang thai don hang %s thanh 'Da giao'.\n", ma);
            } else if (luaChon == 2) {
                strcpy(danhSachDonHang[i].trangThai, "Huy");
                printf("Da cap nhat trang thai don hang %s thanh 'Huy'.\n", ma);
            } else {
                printf("Lua chon khong hop le.\n");
            }
            return;
        }
    }
    printf("Khong tim thay don hang voi ma %s.\n", ma);
}

void xoaDonHang() {
    char ma[MAX_STRING_LENGTH];
    printf("Nhap ma don hang can xoa: ");
    fgets(ma, MAX_STRING_LENGTH, stdin);
    xoaXuongDong(ma);

    for (int i = 0; i < soDonHang; i++) {
        if (strcmp(danhSachDonHang[i].maDonHang, ma) == 0) {
            for (int j = i; j < soDonHang - 1; j++) {
                danhSachDonHang[j] = danhSachDonHang[j+1];
            }
            soDonHang--;
            printf("Da xoa don hang voi ma %s.\n", ma);
            return;
        }
    }
    printf("Khong tim thay don hang voi ma %s.\n", ma);
}

void sapXepDonHang() {
    int luaChon;
    printf("Chon cach sap xep:\n");
    printf("1. Tang dan\n");
    printf("2. Giam dan\n");
    printf("Nhap lua chon: ");
    scanf("%d", &luaChon);
    while (getchar() != '\n');

    for (int i = 0; i < soDonHang - 1; i++) {
        for (int j = 0; j < soDonHang - i - 1; j++) {
            int canHoanVi = 0;
            if (luaChon == 1 && danhSachDonHang[j].tongTien > danhSachDonHang[j+1].tongTien) {
                canHoanVi = 1;
            }
            if (luaChon == 2 && danhSachDonHang[j].tongTien < danhSachDonHang[j+1].tongTien) {
                canHoanVi = 1;
            }

            if (canHoanVi) {
                DonHang temp = danhSachDonHang[j];
                danhSachDonHang[j] = danhSachDonHang[j+1];
                danhSachDonHang[j+1] = temp;
            }
        }
    }
    printf("Da sap xep danh sach don hang theo tong tien.\n");
}

void timKiemDonHang() {
    char ma[MAX_STRING_LENGTH];
    printf("Nhap ma don hang can tim: ");
    fgets(ma, MAX_STRING_LENGTH, stdin);
    xoaXuongDong(ma);

    for (int i = 0; i < soDonHang; i++) {
        if (strcmp(danhSachDonHang[i].maDonHang, ma) == 0) {
            printf("--- Thong tin don hang --- \n");
            printf("Ma don hang: %s\n", danhSachDonHang[i].maDonHang);
            printf("Ten khach hang: %s\n", danhSachDonHang[i].tenKhachHang);
            printf("Ngay dat hang: %d/%d/%d\n", danhSachDonHang[i].ngayDatHang.ngay,
                   danhSachDonHang[i].ngayDatHang.thang,
                   danhSachDonHang[i].ngayDatHang.nam);
            printf("Tong tien: %.2f\n", danhSachDonHang[i].tongTien);
            printf("Trang thai: %s\n", danhSachDonHang[i].trangThai);
            return;
        }
    }
    printf("Khong tim thay don hang voi ma %s.\n", ma);
}

void hienThiMenu() {
    printf("\n--- CHUONG TRINH QUAN LY DON HANG ---\n");
    printf("1. Nhap thong tin don hang moi\n");
    printf("2. Hien thi tat ca don hang\n");
    printf("3. Cap nhat trang thai don hang\n");
    printf("4. Xoa don hang\n");
    printf("5. Sap xep don hang theo tong tien\n");
    printf("6. Tim kiem don hang theo ma\n");
    printf("7. Thoat\n");
    printf("Nhap lua chon cua ban: ");
}

int main() {
    int luaChon;
    do {
        hienThiMenu();
        scanf("%d", &luaChon);
        while (getchar() != '\n');

        switch (luaChon) {
            case 1:
                nhapThongTinDonHang();
                break;
            case 2:
                hienThiDonHang();
                break;
            case 3:
                capNhatTrangThai();
                break;
            case 4:
                xoaDonHang();
                break;
            case 5:
                sapXepDonHang();
                break;
            case 6:
                timKiemDonHang();
                break;
            case 7:
                printf("Tam biet!\n");
                break;
            default:
                printf("Lua chon khong hop le. Vui long chon lai.\n");
                break;
        }
    } while (luaChon != 7);

    return 0;
}

