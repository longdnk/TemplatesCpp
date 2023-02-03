#include <stdio.h>
#include <math.h>

void NhapMang2Chieu(int a[][100], int &n, int &m) {
    printf("Nhap so dong so cot cach nhau khoang trang: ");
    scanf("%d%d", &n, &m);
    printf("\nNhap ma tran\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("Nhap vao a[%d][%d] ", i, j);
            scanf("%d", &a[i][j]);
        }
    }
}

void XuatMang2Chieu(int a[][100], int n, int m) {
    printf("Mang 2 chieu vua nhap\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            printf("%d ", a[i][j]);
        }
        printf("\n");
    }
}

int timSoLonNhat(int a[][100], int n, int m) {
    int max = a[0][0];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (max < a[i][j]) {
                max = a[i][j];
            }
        }
    }
    return max;
}

int timSoNhoNhat(int a[][100], int n, int m) {
    int min = a[0][0];
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (min > a[i][j]) {
                min = a[i][j];
            }
        }
    }
    return min;
}

void timCacPhanTuChan(int a[][100], int n, int m) {
    printf("Cac phan tu chan trong ma tran\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] % 2 == 0) {
                printf("%d ", a[i][j]);
            }
        }
        printf("\n");
    }
}

void timCacPhanTuLe(int a[][100], int n, int m) {
    printf("Cac phan tu le trong ma tran\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] % 2 != 0) {
                printf("%d ", a[i][j]);
            }
        }
        printf("\n");
    }
}

int tongPhanTuChan(int a[][100], int n, int m) {
    int tong = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] % 2 == 0) {
                tong += a[i][j];
            }
        }
    }
    return tong;
}

int tongPhanTuLe(int a[][100], int n, int m) {
    int tong = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] % 2 != 0) {
                tong += a[i][j];
            }
        }
    }
    return tong;
}

int tongCacPhanTuMaTran(int a[][100], int n, int m) {
    int tong = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            tong += a[i][j];
        }
    }
    return tong;
}

void tongMoiDongCuaMaTran(int a[][100], int n, int m) {
    for (int i = 0; i < n; ++i) {
        int tong = 0;
        for (int j = 0; j < m; ++j) {
            tong += a[i][j];
        }
        printf("Tong cua dong thu %d cua ma tran: %d\n", (i + 1), tong);
    }
}

void tongMoiCotCuaMatran(int a[][100], int n, int m) {
    for (int i = 0; i < m; ++i) {
        int tong = 0;
        for (int j = 0; j < n; ++j) {
            tong += a[j][i];
        }
        printf("Tong cua cot thu %d cua ma tran: %d\n", (i + 1), tong);
    }
}

int demPhanTuChan(int a[][100], int n, int m) {
    int dem = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] % 2 == 0) {
                dem++;
            }
        }
    }
    return dem;
}

int demPhanTuLe(int a[][100], int n, int m) {
    int dem = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] % 2 != 0) {
                dem++;
            }
        }
    }
    return dem;
}

void inDuongCheoChinhGiuNguyenMaTran(int a[][100], int n, int m) {
    printf("Duong cheo chinh giu nguyen ma tran\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == j) {
                printf("%d ", a[i][j]);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void inDuongCheoChinh(int a[][100], int n, int m) {
    \
    printf("Duong cheo chinh\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (i == j) {
                printf("%d ", a[i][j]);
            }
        }
    }
    printf("\n");
}

void inDuongCheoPhuGiuNguyenMaTran(int a[][100], int n, int m) {
    printf("Duong cheo phu giu nguyen ma tran\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j == m - i - 1) {
                printf("%d ", a[i][j]);
            } else {
                printf(" ");
            }
        }
        printf("\n");
    }
}

void inDuongCheoPhu(int a[][100], int n, int m) {
    printf("Duong cheo phu\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (j == m - i - 1) {
                printf("%d ", a[i][j]);
            }
        }
    }
    printf("\n");
}

void timPhanTu(int a[][100], int n, int m, int &x) {
    printf("Nhap vao so can tim: ");
    scanf("%d", &x);
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (x == a[i][j]) {
                printf("Tim thay gia tri %d tai dong %d cot %d cua ma tran\n", a[i][j], i + 1, j + 1);
            }
        }
    }
}

int laNguyenTo(int n) {
    if (n < 2) {
        return 0;
    }
    int dem = 0;
    for (int i = 1; i <= n; ++i) {
        if (n % i == 0) {
            dem++;
        }
    }
    if (dem == 2) {
        return 1;
    }
    return 0;
}

int laChinhPhuong(int n) {
    int a = sqrt(n);
    if (a * a == n) {
        return 1;
    }
    return 0;
}

int laSoHoanHao(int n) {
    int sum = 0;
    for (int i = 1; i < n; ++i) {
        if (n % i == 0) {
            sum += i;
        }
    }
    return sum;
}

void timPhanTuNguyenTo(int a[][100], int n, int m) {
    printf("Cac phan tu la so nguyen to trong ma tran\n");
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (laNguyenTo(a[i][j])) {
                printf("%d ", a[i][j]);
            }
        }
    }
    printf("\n");
}

int tongSoNguyenTo(int a[][100], int n, int m) {
    int tong = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (laNguyenTo(a[i][j])) {
                tong += a[i][j];
            }
        }
    }
    return tong;
}

int demSoNguyenTo(int a[][100], int n, int m) {
    int dem = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (laNguyenTo(a[i][j])) {
                dem++;
            }
        }
    }
    return dem;
}

void inPhanTuAmDau(int a[][100], int n, int m) {
    bool laSoAm = false;
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < m; ++j) {
            if (a[i][j] < 0) {
                printf("So am dau cua ma tran la: %d ", a[i][j]);
                laSoAm = true;
                return;
            }
        }
    }
    if (laSoAm == false) {
        printf("Mang khong ton tai so am nao!!!\n");
    }
}

void inPhanTuAmCuoi(int a[][100], int n, int m) {
    bool laSoAm = false;
    for (int i = n; i >= 0; --i) {
        for (int j = m; j >= 0; --j) {
            if (a[i][j] < 0) {
                printf("So am cuoi cung cua mang la: %d\n", a[i][j]);
                laSoAm = true;
                return;
            }
        }
    }
    if (laSoAm == false) {
        printf("Khong ton tai so am trong mang\n");
    }
    printf("\n");
}

int main() {
    int a[109][100], n, m, x; // khai báo mảng 2 chiều, n là số dòng, m là số cột
    NhapMang2Chieu(a, n, m);
    XuatMang2Chieu(a, n, m);

    // Tìm số lớn nhất và nhỏ nhất của ma trận
    printf("So lon nhat cua ma tran %d\n", timSoLonNhat(a, n, m));
    printf("So nho nhat cua ma tran %d\n", timSoNhoNhat(a, n, m));
//
//    // Tìm các phần từ chãn/ lẻ của ma trận
    timCacPhanTuChan(a, n, m);
    timCacPhanTuLe(a, n, m);
//
//    // Tổng phần tử chẵn/ lẻ của ma trận / Tổng mỗi dòng của ma trận / tổng các phần tử của ma trận
    printf("Tong cac phan tu chan cua ma tran: %d\n", tongPhanTuChan(a, n, m));
    printf("Tong cac phan tu le cua ma tran: %d\n", tongPhanTuLe(a, n, m));
    printf("Tong cac phan tu cua ma tran: %d\n", tongCacPhanTuMaTran(a, n, m));
    tongMoiDongCuaMaTran(a, n, m);
    tongMoiCotCuaMatran(a, n, m);
//
//    // Đếm phần tử chẵn/lẻ của ma trận
    printf("So luong phan tu chan cua ma tran: %d\n", demPhanTuChan(a, n, m));
    printf("So luong phan tu le cua ma tran: %d\n", demPhanTuLe(a, n, m));
//
//    // in đường chéo chính, chéc phụ, đường biên, tổng đường chéo chính, phụ, biên
    inDuongCheoChinhGiuNguyenMaTran(a, n, m);
    inDuongCheoChinh(a, n, m); // chéo chính có i == j
    inDuongCheoPhuGiuNguyenMaTran(a, n, m);
    inDuongCheoPhu(a, n, m); // chéo phụ có dòng - i - 1

    // Tìm các phần tử của ma trận
    timPhanTu(a, n, m, x);

    // Số học: tìm các phần tử chính phương nguyên tố hoàn thiện trên ma trận, tổng/đếm các phần từ
    timPhanTuNguyenTo(a, n, m); // tìm kiếm theo điều kiện
    printf("Tong cac so nguyen to trong ma tran: %d\n", tongSoNguyenTo(a, n, m));
    printf("So luong so nguyen to trong ma tran: %d\n", demSoNguyenTo(a, n, m));
    inPhanTuAmDau(a, n, m);
    inPhanTuAmCuoi(a, n, m);
}