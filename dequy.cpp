#include <stdio.h>
#include <math.h>

// 1 + 2 + 3 + ... + n
int tinhTong(int n) {
    // giai bai toan nho nhat`
    if (n == 1) {
        return 1;
    }
    return n + tinhTong(n - 1);
}

// 1 + 3 + 5 + ... + (2 * n + 1)
int tinhTong_2(int n) {
    if (n == 1) {
        return 1;
    }
    return 2 * n - 1 + tinhTong_2(n - 1);
}

// 1 + 1 / 2 + 1 / 3 + ... + 1 / n
float tinhTong_3(int n) {
    if (n == 1) {
        return 1;
    }
    return (float) 1 / n + tinhTong_3(n - 1);
}

// 1 ^ 2 + 2 ^ 2 + 3 ^ 2 + ... + n ^ 2
int tinhTong_4(int n) {
    if (n == 1) {
        return 1;
    }
    return n * n + tinhTong_4(n - 1);
}

// 1 / 2 + 1 / 4 + ... + 1 / 2 * n
float tinhTong_5(int n) {
    if (n == 1) {
        return 1 / 2;
    }
    return (float) 1 / 2 * n + tinhTong_5(n - 1);
}

int tinhF(int n) {
    if (n == 0) {
        return 3;
    } else if (n == 1) {
        return 4;
    } else if (n == 2) {
        return 5;
    }
    return 3 * tinhF(n - 1) + 4 * tinhF(n - 2) + 5 * tinhF(n - 3);
}

// thao tac voi mang
// nhap xuat, tinh tong so le, so chan, tim kiem trong mang, dem phan tu theo dk trong mang -> de quy
void NhapMang(int a[], int n, int i) {
    if (i == n) {
        return;
    }
    printf("Nhap vao phan tu thu %d ", i);
    scanf("%d", &a[i]);
    NhapMang(a, n, i + 1);
}

void XuatMang(int a[], int n, int i) {
    if (i == n) {
        return;
    }
    printf("%d ", a[i]);
    XuatMang(a, n, i + 1);
}

int tingTongMang(int a[], int n, int i, int sum) {
    if (i == n) {
        return sum;
    }
    return tingTongMang(a, n, i + 1, sum + a[i]);
}

int tinhTongSoLe(int a[], int n, int i, int sum) {
    if (i == n) {
        return sum;
    }
    if (a[i] % 2 != 0) {
        return tinhTongSoLe(a, n, i + 1, sum + a[i]);
    }
    return tinhTongSoLe(a, n, i + 1, sum);
}

void timPhanTu(int a[], int n, int i, int x, bool timThay) {
    if (i == n) {
        if (!timThay) {
            printf("khong tim thay\n");
        }
        return;
    }
    if (a[i] == x) {
        printf("Tim thay tai vi tri %d\n", i);
        timPhanTu(a, n, i + 1, x, timThay = true);
    }
    timPhanTu(a, n, i + 1, x, timThay);
}

int demSoLe(int a[], int n, int i, int dem) {
    if (i == n) {
        return dem;
    }
    if (a[i] % 2 != 0) {
        return demSoLe(a, n, i + 1, dem + 1);
    }
    return demSoLe(a, n, i + 1, dem);
}

struct taiLieu {
    char maSo[51];
    int donGia;
};

void NhapThongTin(taiLieu &a) {
    printf("nhap ms: ");
    scanf("%s", a.maSo);
    printf("Nhap don gia: ");
    scanf("%d", &a.donGia);
}

void Xuat(taiLieu a) {
    printf("MS: %s\n", a.maSo);
    printf("Gia: %d\n", a.donGia);
}

void NhapDS(taiLieu a[], int n, int i) {
    if (i == n) {
        return;
    }
    printf("Nhap thong tin:\n");
    NhapThongTin(a[i]);
    NhapDS(a, n, i + 1);
}

void XuatDS(taiLieu a[], int n, int i) {
    if (i == n) {
        return;
    }
    Xuat(a[i]);
    XuatDS(a, n, i + 1);
}

void nhapmang(int *a, int n) { // a[] = *a, giu nguyen n
    for (int i = 0; i < n; ++i) {
        printf("Nhap phan tu thu %d: ", i);
        scanf("%d", &*(a + i)); // a[i] => *(a + i)
    }
}

void xuatmang(int *a, int n) {
    printf("Mang vua nhap\n");
    for (int i = 0; i < n; ++i) {
        printf("%d ", *(a + i));
    }
    printf("\n");
}

int TimMax(int *a, int n) {
    int max = *a;
    for (int i = 0; i < n; ++i) {
        if (max < *(a + i)) {
            max = *(a + i);
        }
    }
    return max;
}

void hoanvi(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

void sapxep(int *a, int n) {
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (*(a + i) > *(a + j)) {
                hoanvi(&a[i], &a[j]);
            }
        }
    }
}
// hoanvi(&a, &b)

void NhapThongTin(taiLieu *a) { // &a => *a
    printf("nhap ms: ");
    scanf("%s", a->maSo); // dau . thay bang dau ->
    printf("Nhap don gia: ");
    scanf("%d", &a->donGia);
}

void Xuat(taiLieu *a) {
    printf("MS: %s\n", a->maSo);
    printf("Gia: %d\n", a->donGia);
}

void NhapDS(taiLieu *a, int n) {
    for (int j = 0; j < n; ++j) {
        NhapThongTin(*(a + j));
    }
}

void XuatDS(taiLieu *a, int n) {
    for (int i = 0; i < n; ++i) {
        Xuat(*(a + i));
    }
}

int main() {
    int a[109], n;
    scanf("%d", &n);
    nhapmang(a, n);
    xuatmang(a, n);
//    int n, i = 0;
//    printf("Nhap n: ");
//    scanf("%d", &n);
//    taiLieu t[5];
//    NhapDS(t, n, i);
//    XuatDS(t, n, i);
//    int a[109], i = 0, sum = 0, dem = 0;
//    NhapMang(a, n, i);
//    XuatMang(a, n, i);
//    printf("\n");
//    printf("Tong mang: %d\n", tingTongMang(a, n, i, sum));
//    printf("Tong SO le: %d\n", tinhTongSoLe(a, n, i, sum));
//    printf("So luong so le: %d\n", demSoLe(a, n, i, dem));
//    printf("Nhap x:");
//    scanf("%d", &x);
//    timPhanTu(a, n, i, x, false);
//    int n = 5;
//    int *a = &n;
//    ++n;
//    *a += 1;
//    *&n += 1;  // n += 1
//    // *a = *&n
//    for (int i = 1; i <= n; ++i) {
//        printf("%d ", *a);
//    }
//    printf("\n");
    // & dia chi
    // * con tro
    // &a => dia chi cua a
    // *&a => gia tri cua a
    // *a = &n => con tro goi dia chi cua n
    // *a = gia tri cua n
    // khi khai bao con tro xen dia chi *a = &n => a hoac n thay doi thi ca 2 deu thay doi
}