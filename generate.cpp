//
// Created by longdnk on 2/2/2023.
//
#include <bits/stdc++.h>

using namespace std;

int32_t main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    freopen("Makefile", "w", stdout);
    string s;
    cin >> s;
    cout << "run:\n";
    cout << "\tg++ -std=c++17 -Ofast -O2 -O3 -m64 -Wall -Wextra -march=native -finline-functions -funroll-loops -unroll-loops " + s + ".cpp -o " + s + ".exe " + "&& start cmd /c " + s + ".exe " + " ^& echo. ^& pause";
}