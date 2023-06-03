#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  int zeros = 0;
  long long currentPower = 5;

  while (N >= currentPower) {
    zeros += N / currentPower;
    currentPower *= 5;
  }

  cout << zeros;
}