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

  return max(max(count[0], count[1]), max(count[2], count[3]));
}

pair<int, int> getNext(int a, int b) {
  int least = calculateM(a, b);
  for (int i = a - 2; i < a + 3; i+=2) {
    for (int j = b - 2; j < b + 3; j+=2) {
      if (calculateM(a + i, b + j) < least) {
        pair<int, int> pos;
        pos.first = a + i;
        pos.second = b + j;
        return pos;
      }
    }
  }
  pair<int, int> pos;
  pos.first = a + rand() % 3 - 1;
  pos.second = b + rand() % 3 - 1;
  return pos;
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

  bool converged = false;
  int a = (N - 1) / 2;
  int b = (N - 1) / 2;
  int least = calculateM(a, b);
  vector<int> adj(4);

  while (!converged) {
    pair<int, int> next = getNext(a, b);
    if (calculateM(next.first, next.second) < least) {
      least = calculateM(next.first, next.second);
      a = next.first;
      b = next.second;
    } else {
      converged = true;
    }
  }

  cout << least;

  return 0;
}