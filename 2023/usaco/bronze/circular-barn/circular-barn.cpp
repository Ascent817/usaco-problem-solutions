#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

int main() {
  freopen("cbarn.in", "r", stdin);
  freopen("cbarn.out", "w", stdout);

  int n;
  cin >> n;
  vector<int> cows(n);

  for (int i = 0; i < n; ++i) {
    cin >> cows[i];
  }

  // Calculate loss

  int mn = INT_MAX;

  for (int k = 0; k < n; k++) {
    int loss = 0;
    int opening = k;

    for (int i = 0; i < n; i++) {
      int distance = (i >= opening) ? (i - opening) : ((n - opening) + i);
      loss += distance * cows[i];
    }

    mn = min(mn, loss);
  }

  cout << mn;
}