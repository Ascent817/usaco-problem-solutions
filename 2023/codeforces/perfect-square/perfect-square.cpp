#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

int main() {
  ios_base::sync_with_stdio(false);
	cin.tie(NULL);

  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    int N;
    cin >> N;
    vector<vector<int>> square(N, vector<int>(N));

    for (int i = 0; i < N; i++) {
      for (int j = 0; j < N; j++) {
        char c;
        cin >> c;
        square[i][j] = c;
      }
    }

    int operations = 0;

    for (int i = 0; i < N / 2; i++) {
      for (int j = 0; j < N / 2; j++) {
        int mx = max(square[i][j], max(square[(N - 1) - j][i], max(square[j][(N - 1) - i], square[(N - 1) - i][(N - 1) - j])));

        operations += mx - square[i][j];
        operations += mx - square[(N - 1) - j][i];
        operations += mx - square[j][(N - 1) - i];
        operations += mx - square[(N - 1) - i][(N - 1) - j];
      }
    }

    std::cout << operations << "\n";
  }
}