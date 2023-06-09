#include <bits/stdc++.h>

using namespace std;

int N, M;

vector<int> set1;
vector<int> set2;

int binarySearch(int n) {
  int left, right, answer;
  answer = 0;
  left = 0;
  right = M - 1;

  while (left <= right) {
    int mid = (left + right) / 2;

    if (set2[mid] <= n) {
      answer = mid;
      left = mid + 1;
    } else {
      right = mid - 1;
    }
  }

  if (answer != M - 1) {
    return min(n - set2[answer], set2[answer + 1] - n);
  } else {
    return n - set2[answer];
  }
}

int main() {
  cin >> N >> M;

  set1.resize(N);
  set2.resize(M);

  for (int i = 0; i < N; i++) {
    cin >> set1[i];
  }

  for (int i = 0; i < M; i++) {
    cin >> set2[i];
  }

  sort(set1.begin(), set1.end());
  sort(set2.begin(), set2.end());

  int minimum = INT_MAX;

  for (int x : set1) {
    int diff = abs(binarySearch(x));

    minimum = min(diff, minimum);
  }

  cout << minimum;
}