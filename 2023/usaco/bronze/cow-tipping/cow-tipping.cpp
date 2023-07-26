#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

int N;
vector<vector<int>> cows;

bool isUntipped() {
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (cows[i][j] == 1) return false;
    }
  }
  return true;
}

void flip(int y, int x) {
  for (int i = 0; i <= y; i++) {
    for (int j = 0; j <= x; j++) {
      cows[i][j] = !cows[i][j];
    }
  }
}

int main() {
  freopen("cowtip.in", "r", stdin);
  freopen("cowtip.out", "w", stdout);

  cin >> N;
  
  cows.resize(N, vector<int>(N));

  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;

    for (int j = 0; j < N; j++) {
      cows[i][j] = s.at(j) - '0';
    }
  }

  int k = 0;
  
  while (!isUntipped()) {
    int mx = 0;
    pair<int, int> coords;
    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        if (cows[i][j] == 1) {
          if (i + j > mx) {
            mx = i + j;
            coords.fi = i;
            coords.se = j;
          }
        }
      }
    }

    flip(coords.fi, coords.se);
    k++;
  }

  cout << k;
}