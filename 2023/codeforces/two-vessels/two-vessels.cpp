#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;


int main() {
  ios_base::sync_with_stdio;
  cin.tie();

  int T;
  cin >> T;

  for (int l = 0; l < T; l++) {
    int a, b, c;
    cin >> a >> b >> c;
    a *= 2;
    b *= 2;
    c *= 2;

    if (a == b) {
      cout << 0 << "\n";
      continue;
    }

    int diff = abs(((a - b) / 2));
    int moves = diff % c == 0 ? diff / c : diff / c + 1;
    cout << moves << "\n";
  }
}