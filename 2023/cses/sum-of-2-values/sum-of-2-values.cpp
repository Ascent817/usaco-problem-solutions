#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

using namespace std;

int main() {
  int N, X;
  cin >> N >> X;

  vector<pair<int, int>> arr(N);

  for (int i = 0; i < N; i++) {
    cin >> arr[i].first;
    arr[i].second = i;
  }

  sort(arr.begin(), arr.end());

  int lptr, rptr;
  lptr = 0;
  rptr = N - 1;

  while (lptr < rptr) {
    int sum = arr[lptr].first + arr[rptr].first;

    if (sum == X) {
      cout << arr[lptr].second + 1 << " " << arr[rptr].second + 1;
      return 0;
    }

    if (sum < X) {
      lptr++;
    } else {
      rptr--;
    }
  }

  cout << "IMPOSSIBLE";
}