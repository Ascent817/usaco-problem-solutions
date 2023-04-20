#include <cstdio>
#include <iostream>

using namespace std;

int main() {
  freopen("shell.in", "r", stdin);
  freopen("shell.out", "w", stdout);

  int N;
  cin >> N;

  int moves[N][3];

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < 3; j++) {
      cin >> moves[i][j];
    }
  }

  int maxPoints = 0;

  for (int i = 1; i < 4; i++) {
    int points = 0;
    int current = i;  // 1 2 3
    for (int j = 0; j < N; j++) {
      if (moves[j][0] == current) {
        current = moves[j][1];
      } else if (moves[j][1] == current) {
        current = moves[j][0];
      }

      if (moves[j][2] == current) {
        points++;
      }
    }

    if (points > maxPoints) {
      maxPoints = points;
    }
  }

  cout << maxPoints;

  return 0;
}