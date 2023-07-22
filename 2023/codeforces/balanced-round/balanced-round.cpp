#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

ll judge() {
  int N, K;
  cin >> N >> K;

  vector<int> problems(N);

  for (int j = 0; j < N; j++) {
    cin >> problems[j];
  }

  sort(all(problems));

  int mx = 0;
  int cur = 1;
  int p = problems[0];
  for (int j = 1; j < N; j++) {
    if ((problems[j] - p) > K) {
      mx = max(mx, cur);
      cur = 1;
    } else {
      cur++;
    }
    p = problems[j];
  }
  mx = max(mx, cur);
  return N - mx;
}

int main() {
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);

  int t;
  cin >> t;

  for (int i = 0; i < t; i++) {
    cout << judge() << "\n";
  }
}