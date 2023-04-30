#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    freopen("backforth.in", "r", stdin);
    freopen("backforth.out", "w", stdout);

    vector<int> barn1(10);
    vector<int> barn2(10);

    for (int i = 0; i < 10; i++) {
        cin >> barn1[i];
    }

    for (int i = 0; i < 10; i++) {
        cin >> barn2[i];
    }
}