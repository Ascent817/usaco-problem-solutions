#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

int main() {
  ll N;
  cin >> N;
  cout << N << " ";
  while (N != 1) {
    if (N % 2 == 0) {
      N /= 2;
    } else {
      N = 3 * N + 1;
    }
    cout << N << " ";
  }
}