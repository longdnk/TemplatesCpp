//
// Created by longdnk on 2/2/2023.
//
#include <bits/stdc++.h>

using namespace std;

struct option {
    int num;
    string content;
};

int32_t main() {
//    ios::sync_with_stdio(false);
//    cin.tie(nullptr);
//    cout.tie(nullptr);
    int opt;
    while (1) {
        cout << "Select OS to generate: " << '\n';
        cout << "1. Linux + MacOS" << '\n';
        cout << "2. Windows" << '\n';
        cin >> opt;
        if (opt == 1 || opt == 2) {
            break;
        } else {
            cout << "Check again!!!\n";
        }
    }
    cout << "Input name file: ";
    freopen("Makefile", "w", stdout);
    string s;
    cin >> s;
    cout << "ext:\n";
    vector<option> options {
            { 1, "\tg++ -std=c++17 -Ofast -O2 -O3 -m64 -Wall -Wextra -march=native -finline-functions -funroll-loops "
                 "-unroll-loops " + s + ".cpp -o " + s },
            { 2, "\tg++ -std=c++17 -Ofast -O2 -O3 -m64 -Wall -Wextra -march=native -finline-functions -funroll-loops "
                 "-unroll-loops " + s + ".cpp -o " + s + ".exe " +
                 "&& start cmd /c " + s + ".exe " + " ^& echo. ^& pause" },
    };
    cout << options[opt - 1].content << '\n';
}