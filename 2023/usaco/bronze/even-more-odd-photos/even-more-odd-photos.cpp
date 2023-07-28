#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

int main() {
  int N;
  cin >> N;
  vector<int> ids(N);

  for (int i = 0; i < N; i++) {
    cin >> ids[i];
    ids[i] %= 2;
  }

  int groups = 0;

  for (int i = 0; i < N; i++) {
    if (i % 2 == 0) {
      for (int j = i; j < N; j++) {
        if (ids[j] == 0) {
          ids[j] = -1;
          groups++;
          break;
        }
      }

      int found = 0;
      for (int j = i; j < N; j++) {
        if (ids[j] == 1) {
          found++;
          ids[j] = -1;
        }

        if (found > 1) {
          groups++;
          break;
        }
      }
    } else {
      int found = 0;
      for (int j = i; j < N; j++) {
        if (ids[j] == 1) {
          found++;
        }
      }

      if (found == 2) {
        cout << groups << endl;
        return 0;
      }

      if (found == 0) {
        cout << groups << endl;
        return 0;
      }

      for (int j = i; j < N; j++) {
        if (ids[j] == 1) {
          ids[j] = -1;
          groups++;
          break;
        }
      }
    }
  }

  cout << groups << endl;
}