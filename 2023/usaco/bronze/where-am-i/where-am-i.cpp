#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

int main() {
  freopen("whereami.in", "r", stdin);
  freopen("whereami.out", "w", stdout);

  int N;
  cin >> N;
  string s;
  cin >> s;

  int L, R, mx;
  L = 0;
  R = 1;
  mx = 0;

  while (R < N) {
    string sub = s.substr(L, R - L + 1);

    if (s.find(sub, R) != -1) {
      R++;
      mx = max(mx, R - L + 1);
    } else {
      L++;
    }
  }

  cout << mx;
}