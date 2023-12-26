#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
  cin.tie(0);

  int N, M;
  cin >> N >> M;

  vector<ll> cows(N);
  vector<ll> canes(M);

  for (int i = 0; i < N; i++) {
    cin >> cows[i];
  }

  for (int i = 0; i < M; i++) {
    cin >> canes[i];
    ll eaten = 0;

    for (int j = 0; j < N; j++) {
      ll remaining = canes[i] - eaten;
      ll reachable = cows[j] - eaten;
      ll eatable = min(reachable, remaining);

      if (remaining < 1) {
        break;
      }

      if (reachable < 1) {
        continue;
      }

      cows[j] += eatable;
      eaten += eatable;
    }
  }

  for (int i = 0; i < N; i++) {
    cout << cows[i] << "\n";
  }
}