#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

int main() {
  freopen("diamond.in", "r", stdin);
  freopen("diamond.out", "w", stdout);

  int N, K;
  cin >> N >> K;
  vector<int> diamonds(N);

  for (int i = 0; i < N; i++) {
    cin >> diamonds[i];
  }

  sort(all(diamonds));

  int L = 0;
  int R = 0;
  int mx = 0;

  while (R < N) {
    if (diamonds[R] - diamonds[L] <= K) {
      mx = max(1 + R - L, mx);
      R++;
    } else {
      L++;
    }
  }

  cout << mx << "\n";
}