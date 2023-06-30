#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

int main() {
  int A, B, W;
  cin >> A >> B >> W;
  W *= 1000;

  int mn = INT_MAX;
  int mx = 0;

  for (int i = 1; i <= 1000000; i++) {
    if (A * i <= W && W <= B * i) {
      mn = min(mn, i);
      mx = max(mx, i);
    }
  }

  if (mx == 0) {
    cout << "UNSATISFIABLE";
    return 0;
  }

  cout << mn << " " << mx;
}