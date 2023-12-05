#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

int main() {
  freopen("mowing.in", "r", stdin);
  freopen("mowing.out", "w", stdout);

  int N;
  cin >> N;

  vector<pair<char, int>> steps(N);
  map<pair<int, int>, int> cutSquares;
  
  for (int i = 0; i < N; i++) {
    cin >> steps[i].fi;
    cin >> steps[i].se;
  }

  int minTime = INT_MAX;
  int x = 0;
  int y = 0;
  int t = 0;

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < steps[i].se; j++) {
      if (cutSquares.find({x, y}) != cutSquares.end()) {
        minTime = min(minTime, t - cutSquares.at({x, y}));
        cutSquares[{x, y}] = t;
      } else {
        cutSquares.insert({{x, y}, t});
      }

      if (steps[i].fi == 'N') {
        y++;
      } else if (steps[i].fi == 'S') {
        y--;
      } else if (steps[i].fi == 'E') {
        x++;
      } else if (steps[i].fi == 'W') {
        x--;
      }

      t++;
    }
  }

  if (minTime == INT_MAX) minTime = -1;

  cout << minTime;
}