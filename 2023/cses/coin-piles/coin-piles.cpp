#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    int a, b = 0;
    cin >> a >> b;

    if ((a + b) % 3 != 0) {
      cout << "NO\n";
      continue;
    }

    if (b - 2 * a > 0) {
      cout << "NO\n";
      continue;
    }

    if (a - 2 * b > 0) {
      cout << "NO\n";
      continue;
    }

    cout << "YES\n";
  }
}