#include <bits/stdc++.h>

using namespace std;

int main() {
  int N, M, K;
  cin >> N >> M >> K;
  vector<vector<int>> grid(N, vector<int>(M));

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < M; j++) {
      cin >> grid[i][j];
    }
  }

  for (int i = 0; i < M - (K - 1); i++) {
    for (int j = 0; j < N - (K - 1); j++) {
      int eCount = 0;
      int wCount = 0;

      for (int x = 0; x < K; x++) {
        for (int y = 0; y < K; y++) {
          if (grid[j + y][i + x] == 0) {
            eCount++;
          } else {
            wCount++;
          }
        }
      }

      if (wCount % 2 == 0) {
        cout << "true" << endl;
        return 0;
      }
    }
  }

  cout << "false" << endl;
}