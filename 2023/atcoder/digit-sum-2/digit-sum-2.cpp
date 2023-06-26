#include <bits/stdc++.h>

using namespace std;

int main() {
  string N;
  cin >> N;
  int sz = N.length();

  for (int i = 1; i < sz; i++) {
    if (N[i] != '9') {
      cout << (N[0] - '0') + ((sz - 1) * 9) - 1;
      return 0;
    }
  }

  cout << (N[0] - '0') + ((sz - 1) * 9);
}