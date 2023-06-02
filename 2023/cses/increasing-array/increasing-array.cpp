#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  long long moves;
  moves = 0;
  cin >> N;
  vector<int> arr(N);

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  for (int i = 0; i < arr.size(); i++) {
    if (i != 0) {
      if (arr[i] < arr[i - 1]) {
        int diff = arr[i - 1] - arr[i];
        arr[i] += diff;
        moves += diff;
      }
    }
  }

  cout << moves << endl;
}