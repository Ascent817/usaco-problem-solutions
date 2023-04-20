#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

int calculateM(int a, int b, vector<pair<int, int>> cows) {
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

  return max(max(count[0], count[1]), max(count[2], count[3]));
}

int main() {
  freopen("balancing.in", "r", stdin);
  // freopen("balancing.out", "w", stdout);
  
  int N, B;
  cin >> N;
  cin >> B;
  vector<pair<int, int>> cows(N);

  for (int i = 0; i < N; i++) {
    cin >> cows[i].first;
    cin >> cows[i].second;
  }

  int least = 10000;
  for (int i = 0; i < B; i+=2) {
    for (int j = 0; j < B; j+=2) {
      int M = calculateM(i, j, cows);
      if (M < least) {
        least = M;
      }
      cout << M << " ";
    }
    cout << endl;
  }

  cout << least;

  return 0;
}