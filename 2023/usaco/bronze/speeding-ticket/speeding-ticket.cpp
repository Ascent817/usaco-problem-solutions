#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

int main() {
  freopen("speeding.in", "r", stdin);
  freopen("speeding.out", "w", stdout);

  int N, M;
  cin >> N >> M;

  vector<int> limits(101);
  vector<int> speeds(101);

  int c = 0;
  for (int i = 0; i < N; i++) {
    int d, l;
    cin >> d >> l;
    fill_n(limits.begin() + c, d, l);
    c += d;
  }

  c = 0;
  for (int i = 0; i < M; i++) {
    int d, l;
    cin >> d >> l;
    fill_n(speeds.begin() + c, d, l);
    c += d;
  }

  int mx = 0;
  for (int i = 0; i < 100; i++) {
    mx = max(mx, speeds[i] - limits[i]);
  }
  
  cout << mx;
}