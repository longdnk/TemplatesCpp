#include <bits/stdc++.h>

using namespace std;

int search(int a[], int n, int x) {
	for (int i = 0; i < n; ++i) {
		if (a[i] == x) {
			return i;
		}
	}
	return -1;
}

// phân tích độ phức tạp của thuật toán
// không gian: n phần tử mảng và 3 biến n, x, i => O(n + 3) = O(n)
// thời gian (số lần tính) phép gán + so sánh
// xét số phép gán tối đa
// F_g(n) = 1 + n + 1 = n + 1 => O(F_g(N)) = O(N)
// Xét số phép so sánh tối đa:
// F_g(N) = n * (1 + 1) = 2N => O(F_g(N)) = O(N)
// so sánh tối thiểu là 2 => O(1)

// so sánh trung bình
// tìm không thấy => quay lại TH tối đa
// tìm thấy: giả sử khả năng tìm thấy ở 1 vị trí nào đó là tương đương như nhau
// giả sử tìm thấy x ở vị trí i sô phép so sánh
// F_g(i) = (i + 1) * (1 + i) = 2i + 2
// số phép so sánh trung bình:
// 1 / n (n - 1 Σ i = 0) 2(i + 1) = 2 / n * (n - 1 Σ i = 0) (i + 1) = 2 / N (N Σ i = 1) i = 2 / n * (n * (n + 1)) / 2 = n + 1
// => O(F_g(N)) = O (N)

void interChangeSort(int a[], int n) {
	for (int i = 0; i < n; ++i) {
		for (int j = i + 1; j < n; ++j) {
			if (a[i] > a[j]) {
				int tmp = a[i];
				a[i] = a[j];
				a[j] = tmp;
			}
		}
	}
}
// xét số phép so sánh, để đơn giản bài toán, ta bỏ qua số phép so sánh vòng lặp, chỉ xét phép so sánh phần tử
// với phép so sánh
// n - 1 vòng lặp
// n - i - 1 vòng lặp + 1 phép so sánh
// số phép so sánh lúc này là: f(N) = (n - 2 Σ i = 0) (n - i - 1) * 1 = (n - 2 Σ i = 0) (n - i - 1)
// f(N) = (n - 1) * n - (n - 2 Σ 0) i - (n - 1)
// = (n - 1) ^ 2 - (n - 2) (n - 1) / 2 = (n - 1) * (2 * n - 2 - n + 2) / 2 = n * (n - 1) / 2 => O(n ^ 2)
// Số phép gán, để đơn giản ta bỏ qua phép gán của bài toán
// TH tối thiểu: (mảng sắp xếp tăng từ trước):
// f(N) = 0 => O(F(n)) = O (1)
// Th xấu nhất: tất cả phép so sánh đều trả về true
// f(N) = 3 * f(N) = 3 * (n * (n - 1)) / 2 => O(f(N)) = O(N ^ 2)
// TH trung bình:
// đặt k = n * (n - 1) / 2, số phép so sánh trong thuật toán
// mỗi phép so sánh trả về true => 3 phép gán
// giả sử ta trả về true / false là ngẫu nhiên
// => số phép gán trung bình mà ta có là: (k + 1) 3 + (0 + 1 + ... + k)  = 3 * (k * (k + 1)) / (k + 1) 2 = 3 / 2 K
// => số phép gán tb = 3 / 2 * (n * (n - 1)/ 2) = 3 / 4 * (n * (n - 1))

// sắp xếp
// Interchange // n ^ 2
// Selection // n ^ 2
// Insertion // n ^ 2
// Bubble // n ^ 2
// Heap => nlogn
// Merge => nlogn
// Quick =>  nlogn => so sánh

// Counting => đếm
// Radix sort => đếm
// 2022 - 1, 2021 - 2, 2019 - 2

int32_t main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
}