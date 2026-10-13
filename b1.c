#include <stdio.h>
#include <string.h>

struct VeMayBay {
    char maPNR[10];
    char tenHanhKhach[50];
    char hangVe[15];
    float trongLuongHanhLy;
    long phiPhuThu;
};

int main() {
    struct VeMayBay ve[50];
    int n, i, viTri = -1;
    char maCanTim[10];
    float trongLuongMoi;

    printf("=== HE THONG CHECK-IN VE MAY BAY ===\n");

    do {
        printf("Nhap so luong ve (1 - 50): ");
        scanf("%d", &n);
        while (getchar() != '\n');

        if (n < 1 || n > 50) {
            printf("So luong khong hop le! Nhap lai.\n");
        }
    } while (n < 1 || n > 50);

    // Nhap danh sach ve
    for (i = 0; i < n; i++) {
        printf("\n--- Nhap thong tin ve thu %d ---\n", i + 1);

        printf("Nhap ma PNR: ");
        fgets(ve[i].maPNR, sizeof(ve[i].maPNR), stdin);
        ve[i].maPNR[strcspn(ve[i].maPNR, "\n")] = '\0';

        printf("Nhap ho ten hanh khach: ");
        fgets(ve[i].tenHanhKhach, sizeof(ve[i].tenHanhKhach), stdin);
        ve[i].tenHanhKhach[strcspn(ve[i].tenHanhKhach, "\n")] = '\0';

        printf("Nhap hang ve (Eco/Deluxe/Business): ");
        fgets(ve[i].hangVe, sizeof(ve[i].hangVe), stdin);
        ve[i].hangVe[strcspn(ve[i].hangVe, "\n")] = '\0';

        printf("Nhap trong luong hanh ly (kg): ");
        scanf("%f", &ve[i].trongLuongHanhLy);
        while (getchar() != '\n');

        // Tinh phi phu thu
        if (ve[i].trongLuongHanhLy > 7.0) {
            ve[i].phiPhuThu =
                (long)((ve[i].trongLuongHanhLy - 7.0) * 50000);
        } else {
            ve[i].phiPhuThu = 0;
        }
    }

    // Hien thi danh sach ve
    printf("\n=== DANH SACH VE MAY BAY CHUYEN BAY ===\n");

    printf("--------------------------------------------------------------------------------\n");
    printf("%-5s %-10s %-25s %-12s %-12s %-15s\n",
           "STT", "MA PNR", "HO TEN HANH KHACH",
           "HANG VE", "HANH LY(KG)", "PHI PHU THU");
    printf("--------------------------------------------------------------------------------\n");

    for (i = 0; i < n; i++) {
        printf("%-5d %-10s %-25s %-12s %-12.1f %-15ld\n",
               i + 1, ve[i].maPNR, ve[i].tenHanhKhach,
               ve[i].hangVe, ve[i].trongLuongHanhLy,
               ve[i].phiPhuThu);
    }

    printf("--------------------------------------------------------------------------------\n");

    // Tim kiem va cap nhat ve
    printf("\n=== CAP NHAT THONG TIN HANH LY ===\n");
    printf("Nhap ma PNR can cap nhat: ");
    fgets(maCanTim, sizeof(maCanTim), stdin);
    maCanTim[strcspn(maCanTim, "\n")] = '\0';

    for (i = 0; i < n; i++) {
        if (strcmp(ve[i].maPNR, maCanTim) == 0) {
            viTri = i;
            break;
        }
    }

    if (viTri != -1) {
        printf("Tim thay ve cua hanh khach: %s\n",
               ve[viTri].tenHanhKhach);

        printf("Nhap trong luong hanh ly moi (kg): ");
        scanf("%f", &trongLuongMoi);

        ve[viTri].trongLuongHanhLy = trongLuongMoi;

        if (trongLuongMoi > 7.0) {
            ve[viTri].phiPhuThu =
                (long)((trongLuongMoi - 7.0) * 50000);
        } else {
            ve[viTri].phiPhuThu = 0;
        }

        printf("Cap nhat thanh cong! Phi phu thu moi: %ld VND\n",
               ve[viTri].phiPhuThu);

        // Hien thi danh sach sau cap nhat
        printf("\n=== DANH SACH VE MAY BAY SAU CAP NHAT ===\n");

        printf("--------------------------------------------------------------------------------\n");
        printf("%-5s %-10s %-25s %-12s %-12s %-15s\n",
               "STT", "MA PNR", "HO TEN HANH KHACH",
               "HANG VE", "HANH LY(KG)", "PHI PHU THU");
        printf("--------------------------------------------------------------------------------\n");

        for (i = 0; i < n; i++) {
            printf("%-5d %-10s %-25s %-12s %-12.1f %-15ld\n",
                   i + 1, ve[i].maPNR, ve[i].tenHanhKhach,
                   ve[i].hangVe, ve[i].trongLuongHanhLy,
                   ve[i].phiPhuThu);
        }

        printf("--------------------------------------------------------------------------------\n");
    } else {
        printf("Khong tim thay ma PNR hop le!\n");
    }

    return 0;
}
