#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);

  int t;
  cin >> t;

  for (int T = 0; T < t; T++) {
    int n, k;
    cin >> n >> k;
    vector<pair<int, int>> monsters(n);

    for (int i = 0; i < n; i++) {
      int x;
      cin >> x;
      if (x % k == 0) {
        monsters[i] = {k, -i};
      } else {
        monsters[i] = {x % k, -i};
      }
    }

    sort(all(monsters));
    vector<int> order(n);

    for (int i = n - 1; i >= 0; i--) {
      order[n - i - 1] = -monsters[i].se;
    }

    for (int i = 0; i < n; i++) {
      cout << order[i] + 1 << " ";
    }
    cout << "\n";
  }
}