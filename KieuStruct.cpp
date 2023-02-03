#include <stdio.h>
#include <math.h>
#include <string.h>

struct SinhVien {
    char maSV[100];
    char hoTen[100];
    int tuoi;
    float diemTB;
    char gioiTinh; // x là nữ, y là nam
};

void NhapSoLuong(int &n) {
    printf("Nhap so luong sv: ");
    scanf("%d", &n);
}

void NhapSinhVien(SinhVien &sv) {
    if (getchar() == '\n') {
        fflush(stdin);
    }
    printf("Nhap vao ma sv: ");
    fflush(stdin);
    fgets(sv.maSV, 100, stdin);
    printf("Nhap vao ho ten sv: ");
    fflush(stdin);
    fgets(sv.hoTen, 100, stdin);
    while (1) {
        printf("Nhap gioi tinh: ");
        fflush(stdin);
        scanf("%c", &sv.gioiTinh);
        if (sv.gioiTinh == 'x' || sv.gioiTinh == 'y') {
            break;
        } else {
            printf("Nhap lai\n");
        }
    }
    printf("Nhap vao tuoi: ");
    scanf("%d", &sv.tuoi);
    printf("Nhap vao diem TB: ");
    scanf("%f", &sv.diemTB);
}

void XuatThongTin(SinhVien sv) {
    printf("Ma sv: ");
    puts(sv.maSV);
    printf("Ten sv: ");
    puts(sv.hoTen);
    printf("Tuoi: %d\n", sv.tuoi);
    printf("Diem TB: %f\n", sv.diemTB);
    if (sv.gioiTinh == 'x') {
        printf("Gioi tinh: Nam\n");
    } else {
        printf("Gioi tinh: Nu\n");
    }
}

void NhapDSSinhVien(SinhVien a[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("Nhap vao thong tin sv thu %d\n", i + 1);
        NhapSinhVien(a[i]);
    }
}

void XuatDS(SinhVien a[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("Thong tin sv thu %d\n", i + 1);
        XuatThongTin(a[i]);
    }
}

void timSinhVienLaNam(SinhVien a[], int n) {
    for (int i = 0; i < n; ++i) {
        if (a[i].gioiTinh == 'y') {
            XuatThongTin(a[i]);
        }
    }
}

void timSinhVienLaNu(SinhVien a[], int n) {
    for (int i = 0; i < n; ++i) {
        if (a[i].gioiTinh == 'x') {
            XuatThongTin(a[i]);
        }
    }
}

void timSinhVienTheoTen(SinhVien a[], int n, char s[100]) {
    printf("Nhap vao ten sv muon tim: ");
    fgets(s, 100, stdin);
    for (int i = 0; i < n; ++i) {
        if (strcmp(a[i].hoTen, s) == 0) {
            XuatThongTin(a[i]);
        }
    }
}

void HoanVi(SinhVien &a, SinhVien &b) {
    SinhVien tmp = a;
    a = b;
    b = tmp;
}

void sapXepTheoTuoi(SinhVien a[], int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (a[i].tuoi < a[j].tuoi) {
                HoanVi(a[i], a[j]);
            }
        }
    }
}

void sapXepTheoTen(SinhVien a[], int n) { //  tăng dần theo bản chữ cái
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (strcmp(a[i].hoTen, a[j].hoTen) == -1) { // xếp giảm dần thì thay thành 1
                HoanVi(a[i], a[j]);
            }
        }
    }
}

int main() {
    int n;
    SinhVien a[1000];
    NhapSoLuong(n);
    NhapDSSinhVien(a, n);
    XuatDS(a, n);
    // tìm theo 1 thông tin không phải dạng chuỗi
    // sap xep
}