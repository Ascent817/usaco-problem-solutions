#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define all(x) (x).begin(), (x).end()

using namespace std;

vector<int> searchSpace;
vector<vector<int>> counts;

int query(int L, int R, int X) {
  int left, right, leftAnswer;
  left = 0;
  right = counts[X].size() - 1;
  leftAnswer = -1;
  
  while (left <= right) {
    int mid = (left + right) / 2;
    
    if (counts[X][mid] < L) {
      left = mid + 1;
      leftAnswer = mid;
    } else {
      right = mid - 1;
    }
  }

  left = 0;
  right = counts[X].size() - 1;
  int rightAnswer = -1;
  
  while (left <= right) {
    int mid = (left + right) / 2;
    
    if (counts[X][mid] <= R) {
      left = mid + 1;
      rightAnswer = mid;
    } else {
      right = mid - 1;
    }
  }

  return rightAnswer - leftAnswer;
}

int main() {
  int N, Q;
  cin >> N;

  counts.resize(N + 1);

  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    counts[x].push_back(i);
  }

  cin >> Q;

  for (int i = 0; i < Q; i++) {
    int L, R, X;
    cin >> L >> R >> X;
    cout << query(L - 1, R - 1, X) << endl;
  }
}