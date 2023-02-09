#include <stdio.h>
#include <math.h>

struct TaiLieu {
    int maTaiLieu;
    char tenTaiLieu[31];
};

void nhapTaiLieu(TaiLieu &tl) {
    printf("Nhap vao ma tai lieu: ");
    scanf("%d", &tl.maTaiLieu);
    printf("Nhap vao ten tai lieu: ");
    if (getchar() == '\n') {
        rewind(stdin);
    }
    fgets(tl.tenTaiLieu, 31, stdin);
}

void xuatTaiLieu(TaiLieu tl) {
    printf("Ma tai lieu: %d\n", tl.maTaiLieu);
    printf("Ten tai lieu: ");
    fputs(tl.tenTaiLieu, stdout);
}

void nhapSoLuong(int &n) {
    printf("Nhap vao so luong tai lieu: ");
    scanf("%d", &n);
}

void nhapDanhSach(TaiLieu a[], int n) {
    printf("Nhap danh sach tai lieu: \n");
    for (int i = 0; i < n; ++i) {
        printf("Nhap vao thong tin tai lieu thu %d\n", i + 1);
        nhapTaiLieu(a[i]);
    }
}

void xuatDanhSach(TaiLieu a[], int n) {
    printf("Danh sach tai lieu vua nhap\n");
    for (int i = 0; i < n; ++i) {
        printf("===Thong tin tai lieu thu %d===\n", i + 1);
        xuatTaiLieu(a[i]);
        printf("\t===END===\n");
    }
}

bool timThongTin(TaiLieu a[], int n, int findCode) {
    bool flag = false;
    for (int i = 0; i < n; ++i) {
        if (a[i].maTaiLieu == findCode) {
            printf("===Thong tin tai lieu can tim===\n");
            xuatTaiLieu(a[i]);
            flag = true;
            break;
        }
    }
    return flag;
}

void nhapMang2Chieu(int a[][100], int &d, int &c) {
    printf("Nhap vao so dong, so cot ma tran cach nhau khoang trang: ");
    scanf("%d %d", &d, &c);
    printf("Nhap ma tran\n");
    for (int i = 0; i < d; ++i) {
        for (int j = 0; j < c; ++j) {
            printf("Nhap a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
    printf("Mang vua nhap\n");
    for (int i = 0; i < d; ++i) {
        for (int j = 0; j < c; ++j) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int demSoLuong(int a[][100], int d, int c) {
    int n = d - 1, dem = 0;
    for (int j = 0; j < c; ++j) {
        dem += !(a[n][j] & 1) ? 1 : 0;
    }
    return dem;
}

int main() {
    // Cau 1
    int n;
    nhapSoLuong(n);
    TaiLieu *a = (TaiLieu *) malloc(n * sizeof(TaiLieu));
    nhapDanhSach(a, n);
    xuatDanhSach(a, n);
    int findCode;
    printf("Nhap vao ma cua tai lieu can tim: ");
    scanf("%d", &findCode);
    if (!timThongTin(a, n, findCode)) {
        printf("Khong tim thay\n");
    }
    // Cau 2
    int arr[100][100], d, c;
    nhapMang2Chieu(arr, d, c);
    printf("So luong phan tu duong chan trong dong cuoi ma tran: %d\n", demSoLuong(arr, d, c));
}