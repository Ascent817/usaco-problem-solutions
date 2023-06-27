#include <bits/stdc++.h>

using namespace std;

int main() {
  for (int k = 1; k < 100; k+=2) {
    int N = k;
    vector<int> table(N * N);
    int idx = 0;

    for (int i = 1; i <= N; i++) {
      table[idx] = i * i;
      idx++;
      for (int j = 1; j < i; j++) {
        table[idx] = i * j;
        table[idx + 1] = i * j;
        idx += 2;
      }
    }

    sort(table.begin(), table.end());

    int x = table[(N * N) / 2];

    cout << k << ", " << table[(N * N) / 2] << endl;
  }
}