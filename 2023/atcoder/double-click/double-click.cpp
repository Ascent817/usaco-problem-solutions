#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, D;
  cin >> N >> D;

  int prev;
  int current;
  cin >> prev;

  for (int i = 1; i < N; i++) {
    cin >> current;
    if (current - prev <= D) {
      cout << current << endl;
      return 0;
    }
    prev = current;
  }

  cout << -1 << endl;
}