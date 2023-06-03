#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<char> isPresent(N, 0);

  for (int i = 0; i < N - 1; i++) {
    int x;
    cin >> x;
    isPresent[x - 1] = 1;
  }

  for (int i = 0; i < N; i++) {
    if (isPresent[i] == 0) {
      cout << i + 1;
      return 0;
    }
  }
}