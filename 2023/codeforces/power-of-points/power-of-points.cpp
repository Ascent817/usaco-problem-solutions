#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

int main() {
  int T;
  cin >> T;

  for (int c = 0; c < T; c++) {
    int N;
    cin >> N;

    vector<pair<ll, ll>> arr(N);

    for (int i = 0; i < N; i++) {
      ll x;
      cin >> x;
      arr[i] = {x, i};
    }

    sort(all(arr));

    vector<ll> pSums(N);
    pSums[0] = arr[0].fi;

    for (int i = 1; i < N; i++) {
      pSums[i] = pSums[i - 1] + arr[i].fi;
    }

    vector<ll> ans(N);

    for (int i = 0; i < N; i++) {
      ll sum = 0;
      sum += (i + 1) * (arr[i].fi + 1);
      sum -= pSums[i];
      sum += pSums[N - 1] - pSums[i];
      sum -= (N - i - 1) * (arr[i].fi - 1);
      ans[arr[i].se] = sum;
    }

    for (int i = 0; i < N; i++) {
      cout << ans[i] << " ";
    }

    cout << "\n";
  }
}