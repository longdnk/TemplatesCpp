#include <stdio.h>
#include <math.h>

struct MatHang {
    char maHang[51];
    int donGia;
};

void NhapMatHang(MatHang &mh) {
    printf("Nhap vao ma hang: ");
    if (getchar() == '\n') {
        rewind(stdin);
    }
    fgets(mh.maHang, 51, stdin);
    printf("Nhap vao don gia: ");
    scanf("%d", &mh.donGia);
}

void NhapSoLuong(int &n) {
    printf("Nhap vao so luong mat hang: ");
    scanf("%d", &n);
}

void NhapDanhSach(MatHang a[], int n) {
    for (int i = 0; i < n; ++i) {
        printf("Nhap vao mat hang thu %d\n", i + 1);
        NhapMatHang(a[i]);
    }
}

void xuatThongTin(MatHang mh) {
    printf("Ma hang: ");
    fputs(mh.maHang, stdout);
    printf("Don gia: %d\n", mh.donGia);
}

void TimMatHang(MatHang a[], int n) {
    for (int i = 0; i < n; ++i) {
        if (a[i].donGia < 10) {
            printf("Thong tin Mat hang can tim: \n");
            xuatThongTin(a[i]);
            return;
        }
    }
    printf("Khong tim thay mat hang dung yeu cau\n");
}

int timMaxDonGia(MatHang a[], int n) {
    int max = 0;
    for (int i = 0; i < n; ++i) {
        if (max < a[i].donGia) {
            max = a[i].donGia;
        }
    }
    return max;
}

void nhapMaTran(float a[][100], int &n) {
    printf("Nhap so luong dong cot ma tran: ");
    scanf("%d", &n);
    printf("Nhap ma tran\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            printf("Nhap a[%d][%d]: ", i, j);
            scanf("%f", &a[i][j]);
        }
    }
}

bool isPrime(float x) {
//    bool flag = true;
//    int n = (int) x;
//    for (int i = 2; i * i <= n; i = i + (i & 1) + 1) {
//        if (!(n % i)) {
//            flag = false;
//            break;
//        }
//    }
//    return n > 1 && flag;
    int cnt = 0;
    for (int i = 1; i <= (int) x; ++i) {
        if ((int) x % i == 0) {
            ++cnt;
        }
    }
    if (cnt == 2) {
        return true;
    }
    return false;
}

bool laNgto(float x) {
    int cnt = 0;
    for (int i = 1; i <= (int) x; ++i) {
        if (fmod(x, i) == 0) {
            ++cnt;
        }
    }
    if (cnt == 2) {
        return true;
    }
    return false;
}

float tinhTongPTuNguyenTo(float a[][100], int n, int d) {
    --d;
    float sum = 0;
    for (int i = 0; i < n; ++i) {
//        if (isPrime(a[d][i])) {
//            sum += a[d][i];
//        }
        if (laNgto(a[d][i])) {
            printf("%.2f\n", a[d][i]);
            sum += a[d][i];
        }
    }
    return sum;
}

int main() {
    // Bai 1
    int n;
    NhapSoLuong(n);
    MatHang mh[n + 1];
    NhapDanhSach(mh, n);
    TimMatHang(mh, n);
    printf("Gia tri don gia cao nhat: %d\n", timMaxDonGia(mh, n));
    // Bai 2
    int N;
    float a[100][100];
    nhapMaTran(a, N);
    int d;
    printf("Nhap vao so dong muon tinh tong: ");
    scanf("%d", &d);
    printf("Tong cac phan tu tai dong %d la %.5f\n", d, tinhTongPTuNguyenTo(a, N, d));
}