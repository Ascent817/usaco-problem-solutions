#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define all(x) (x).begin(), (x).end()

using namespace std;

int main() {
  int N;
  cin >> N;

  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;

    int divisors = 0;

    for (int j = 1; j * j <= x; j++) {
      if (x % j == 0) {
        if (x / j == j) {
          divisors++;
        } else {
          divisors += 2;
        }
      }
    }

    cout << divisors << "\n";
  }
}