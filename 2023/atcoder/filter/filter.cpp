#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  int x = 0;

  for (int i = 0; i < N; i++) {
    cin >> x;

    if (x % 2 == 0) {
      cout << x << " ";
    }
  }
}