#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

int main() {
  int N;
  ll evens = 0;
  ll total = 1;
  cin >> N;

  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    if (x % 2 == 0) {
      evens++;
    }
  }

  for (int i = 0; i < N; i++) {
    total *= 3;
  }

  ll evenTotal = 1;
  for (int i = 0; i < evens; i++) {
    evenTotal *= 2;
  }

  cout << total - evenTotal;
}