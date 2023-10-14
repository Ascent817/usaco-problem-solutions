#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

int main() {
  freopen("reduce.in", "r", stdin);
  freopen("reduce.out", "w", stdout);

  int N;
  cin >> N;
  vector<int> xcows(N);
  vector<int> ycows(N);
  set<pair<int, int>> cows;

  for (int i = 0; i < N; i++) {
    cin >> xcows[i] >> ycows[i];
    cows.insert({xcows[i], ycows[i]});
  }

  sort(all(xcows));
  sort(all(ycows));

  int xh1, xh2, xl1, xl2, yh1, yh2, yl1, yl2;

  xh1 = xcows[N - 1];
  xh2 = xcows[N - 2];
  xl1 = xcows[0];
  xl2 = xcows[1];

  yh1 = ycows[N - 1];
  yh2 = ycows[N - 2];
  yl1 = ycows[0];
  yl2 = ycows[1];

  vector<int> fences = {(xh2 - xl1) * (yh1 - yl1), (xh1 - xl2) * (yh1 - yl1), (xh1 - xl1) * (yh1 - yl2), (xh1 - xl1) * (yh2 - yl1)};

  if (cows.find({xh1, yh1}) != cows.end()) {
    fences.push_back((xh2 - xl1) * (yh2 - yl1));
  } else if (cows.find({xh1, yl1}) != cows.end()) {
    fences.push_back((xh2 - xl1) * (yh1 - yl2));
  } else if (cows.find({xl1, yh1}) != cows.end()) {
    fences.push_back((xh1 - xl2) * (yh2 - yl1));
  } else if (cows.find({xl1, yl1}) != cows.end()) {
    fences.push_back((xh1 - xl2) * (yh1 - yl2));
  }

  int ans = *min_element(all(fences));

  cout << ans << "\n";
}