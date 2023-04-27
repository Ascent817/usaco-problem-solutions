#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

vector<pair<int, int>> cows;

int calculateM(int a, int b) {
  vector<int> count(4);

  for (int i = 0; i < cows.size(); i++) {
    pair<int, int> position = cows[i];
    if (position.first > a && position.second > b) {
      count[0]++;
    } else if (position.first > a && position.second < b) {
      count[1]++;
    } else if (position.first < a && position.second > b) {
      count[2]++;
    } else {
      count[3]++;
    }
  }
  int m = max(max(count[0], count[1]), max(count[2], count[3]));
  return m;
}

int main() {
  freopen("balancing.in", "r", stdin);
  freopen("balancing.out", "w", stdout);

  int N, B;
  cin >> N;
  cin >> B;

  cows.resize(N);

  for (int i = 0; i < N; i++) {
    cin >> cows[i].first;
    cin >> cows[i].second;
  }

  int least = calculateM(1, 1);

  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      int fence = calculateM(cows[i].first + 1, cows[j].second - 1);
      if (fence < least) {
        least = fence;
      }
    }
  }

  cout << least;

  return 0;
}