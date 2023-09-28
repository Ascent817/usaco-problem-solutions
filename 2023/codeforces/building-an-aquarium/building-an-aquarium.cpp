#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

bool canFill(int h, int w, vector<int> &a) {
  int sm = 0;
  for (int i = 0; i < a.size(); i++) {
    sm += max(0, h - a[i]);
    if (sm > w) {
      return false;
    }
  }
  return true;
}

int main() {
  int T;
  cin >> T;

  for (int t = 0; t < T; t++) {
    int N, W;
    cin >> N >> W;

    vector<int> a(N);

    for (int i = 0; i < N; i++) {
      cin >> a[i];
    }

    ll left, right, answer;
    left = 0;
    right = INT_MAX;
    answer = 0;
    
    while (left <= right) {
      ll mid = (left + right) / 2;
      
      if (canFill(mid, W, a)) {
        left = mid + 1;
        answer = mid;
      } else {
        right = mid - 1;
      }
    }

    cout << answer << "\n";
  }
}