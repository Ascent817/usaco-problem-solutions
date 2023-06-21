#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

using namespace std;

int main() {
  int N;
  cin >> N;

  int cr, mx, pv;
  mx = 0;
  cr = 0;
  cin >> pv;

  for (int i = 1; i < N; i++) {
    int x;
    cin >> x;

    if (x <= pv) {
      cr++;
    } else {
      mx = max(cr, mx);
      cr = 0;
    }

    pv = x;
  }

  mx = max(cr, mx);

  cout << mx << endl;
}