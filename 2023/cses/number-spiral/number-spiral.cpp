#include <bits/stdc++.h>

using namespace std;

int main() {
  int T;
  cin >> T;

  for (int i = 0; i < T; i++) {
    long x, y;
    cin >> y >> x;

    long shell = max(x, y);
    long middle = shell * shell - (shell - 1);

    if (shell % 2 == 0) {
      cout << middle - (x - y) << "\n";
    } else {
      cout << middle + (x - y) << "\n";
    }
  }
}