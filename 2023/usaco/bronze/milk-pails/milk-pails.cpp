#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

int X, Y, M;

int loss(int a) {
  return M - (X * a) - (Y * floor((M - (X * a)) / Y));
}

int main() {
  freopen("pails.in", "r", stdin);
  freopen("pails.out", "w", stdout);

  cin >> X >> Y >> M;

  int mn = INT_MAX;
  for (int i = 0; i <= floor(M / X); i++) {
    mn = min(loss(i), mn);
  }

  cout << M - mn;
}