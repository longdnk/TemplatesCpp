#include <bits/stdc++.h>

using namespace std;
#define ll long long int
#define ull unsigned long long int
#define ld long double
#define pb push_back
#define eb emplace_back
#define mp make_pair
#define mt make_tuple
#define fi first
#define se second
#define FORUP(i, star, end) for (int i = star; i <= end; ++i)
#define FORDOWN(i, star, end) for (int i = end; i >= star; --i)
#define FORAUTO(item, m) for (auto item : m)
#define foreach(vector) for (auto it : vector) cout << it << ' ';
#define Map_Foreach(map) for (auto it : map) cout << it.fi << ' ' << it.se << "\n";
#define REP(i, n) for (int i = 0; i < n; ++i)
#define REV(i, n) for (int i = n - 1; i >= 0; --i)
#define AutoInputArray(a, b, x) FORUP(a, 1, b) cin >> x[i];
#define AutoInputArrayFr0(a, b, x) REP(0, n) cin >> x[i];
#define whatis(x) cout << "Line " << __LINE__ << ": " << #x << " = " << (x) << ", ";
#define ShowTime() cerr << "Executed in " << clock() * 1000 / CLOCKS_PER_SEC << " ms";
#define UpCase(s) transform(s.begin(), s.end(), s.begin(), ::toupper);
#define LowCase(s) transform(s.begin(), s.end(), s.begin(), ::tolower);
#define all(x) (x).begin(), (x).end()
#define rall(x) (x).rbegin(), (x).rend()
#define len(x) (int)x.size()
#define endl "\n"

void debug_out() { cerr << endl; }
void in() { }
void out() { }
inline int getchar_unlocked() { return getchar(); }
inline int putchar_unlocked(char c) { return putchar(c); }

template <typename Head, typename... Tail> void debug_out(Head H, Tail... T) { cerr << " " << H << ","; debug_out(T...); }
template <typename A, typename B> ostream &operator<<(ostream &os, const pair<A, B> &p) { return os << p.first << " " << p.second; }
template <typename a, typename b, typename c> ostream &operator<<(ostream &os, const pair<a, pair<b, c>> &p) { return os << p.second.first << ' ' << p.second.second; }
template <typename T> void inp(T &x) { x = 0; bool neg = 0; T c = getchar_unlocked(); if (c == '-') neg = 1, c = getchar_unlocked(); while ((c < 48) || (c > 57)) c = getchar_unlocked(); for (; c < 48 or c > 57; c = getchar_unlocked()); for (; c > 47 && c < 58; c = getchar_unlocked()) x = (x << 3) + (x << 1) + (c & 15); if (neg) x *= -1; }
template <typename T> void outp(T n) { bool neg = 0; if (n < 0) n *= -1, neg = 1; char snum[109]; int i = 0; do { snum[i++] = n % 10 + '0'; n /= 10; } while (n); --i; if (neg) putchar_unlocked('-'); while (i >= 0) putchar_unlocked(snum[i--]); putchar_unlocked('\n'); }
template <typename T, typename... Args> void in(T &num, Args&... args) { inp(num); in(args...); }
template <typename T, typename... Args> void out(T first, Args... args) { outp(first); out(args...); }
#define debug(...) cerr << "(" << #__VA_ARGS__ << "):", debug_out(__VA_ARGS__)

const int maxn = 1e7 + 9, mod = 1e9 + 7, nn = 4e3 + 9, oo = 1e9 + 1e8, inf = ~(1 << 31), nmax = 1009, mm = 2e8, filerun = 0;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
}