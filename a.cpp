#include <bits/stdc++.h>

using namespace std;
typedef vector<vector<int64_t>> matrix;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    auto multiply = [&](matrix &F, matrix M) -> void {
        int64_t x, y, z, w;
        x = (int64_t) F[0][0] * M[0][0] + F[0][1] * M[1][0];
        y = (int64_t) F[0][0] * M[0][1] + F[0][1] * M[1][1];
        z = (int64_t) F[1][0] * M[0][0] + F[1][1] * M[1][0];
        w = (int64_t) F[1][0] * M[0][1] + F[1][1] * M[1][1];

        F[0][0] = x, F[0][1] = y, F[1][0] = z, F[1][1] = w;
    };

    function<auto(matrix &, int n) -> void> power = [&](matrix &f, int n) -> void {
        if (n == 0 || n == 1) {
            return;
        }
        matrix M {{ 1, 1 },
                  { 1, 0 }};

        power(f, n >> 1);
        multiply(f, f);

        if (n & 1) {
            multiply(f, M);
        }
    };

    auto fibonacci = [&](int n) -> int64_t {
        matrix f {{ 1, 1 },
                  { 1, 0 }};
        if (n == 0) {
            return 0;
        }
        power(f, n - 1);

        return f[0][0];
    };

    auto findNumber = [&](int x) -> int {
        int l = 1, r = x, mid, res = -1;
        while (l <= r) {
            mid = (r + l) >> 1;
            if (fibonacci(mid) <= x) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    };
    cout << findNumber(100) << '\n';
}