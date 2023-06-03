#include <bits/stdc++.h>

using namespace std;

int main() {
  long N;
  cin >> N;

  set<long> numbers;

  for (int i = 0; i < N; i++) {
    long x;
    cin >> x;
    numbers.insert(x);
  }

  cout << numbers.size();
}