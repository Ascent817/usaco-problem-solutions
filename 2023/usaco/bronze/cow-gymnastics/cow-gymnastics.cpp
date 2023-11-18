#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

int main() {
  freopen("gymnastics.in", "r", stdin);
  freopen("gymnastics.out", "w", stdout);

  int K, N;
  cin >> K >> N;

  vector<vector<int>> previous(N + 1, vector<int>(N + 1));
  vector<vector<int>> current(N + 1, vector<int>(N + 1));
  vector<vector<int>> pairArr(N + 1, vector<int>(N + 1, 1));

  vector<int> session(N);

  for (int i = 0; i < N; i++) {
    cin >> session[i];
  }

  for (int i = 0; i < N; i++) {
    int e = session[i];
    for (int k = 0; k < N; k++) {
      if (k == i) {
        previous[e][e] = 0;
        continue;
      }

      if (k < i) {
        previous[e][session[k]] = -1;
      } else {
        previous[e][session[k]] = 1;
      }
    }
  }

  int pairs = 0;

  for (int o = 0; o < K - 1; o++) {
    // Get session
    for (int i = 0; i < N; i++) {
      cin >> session[i];
    }
    
    // Generate comparison array
    for (int i = 0; i < N; i++) {
      int e = session[i];
      for (int k = 0; k < N; k++) {
        if (k == i) {
          current[e][e] = 0;
          continue;
        }

        if (k < i) {
          current[e][session[k]] = -1;
        } else {
          current[e][session[k]] = 1;
        }
      }
    }

    // Compare
    for (int i = 1; i < N + 1; i++) {
      for (int j = 1; j < N + 1; j++) {
        if (previous[i][j] != current[i][j]) {
          pairArr[i][j] = 0;
        }
      }
    }

    previous = current;
    current.resize(N + 1, vector<int>(N + 1));
  }

  for (int i = 1; i < N + 1; i++) {
    for (int j = 1; j < N + 1; j++) {
      if (pairArr[i][j] == 1) {
        pairs++;
      }
    }
  }

  pairs = (pairs - N) / 2;

  cout << pairs;
}