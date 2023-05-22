#include <bits/stdc++.h>

using namespace std;

struct tower {
  int p, i;

  bool operator<(const tower& t) const {
    return i < t.i;
  }

  bool operator>(const tower& t) const {
    return i > t.i;
  }
};

int main() {
  int N, M;
  cin >> N >> M;
  
  vector<tower> towers;

  for (int j = 0; j < N; j++) {
    int p, i;
    cin >> p >> i;
    towers.push_back({p, i});
  }

  sort(towers.begin(), towers.end());

  for (int j = 0; j < M; j++) {
    int p;
    cin >> p;
    
    int max = 0;
    int cutoff = 0;
    int distance = abs(towers[0].p - p);
    
    for (int i = 1; i < M; i++) {
      int d = abs(towers[i].p - p);
      if (d < distance) {
        distance = d;
        cutoff = i;
      }
    }

    cout << max << endl;
  }
}