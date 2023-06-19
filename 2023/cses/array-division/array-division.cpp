#include <bits/stdc++.h>

using namespace std;

int N, K;
vector<int> arr;

int greedy(long long mx) {
  int divs = 1;
  long long currentSum = 0;

  for (int i = 0; i < N; i++) {
    if (currentSum + arr[i] <= mx) {
      currentSum += arr[i];
    } else {
      currentSum = arr[i];
      divs++;
    }
  }

  return divs;
}

int main() {
  
  cin >> N >> K;
  arr.resize(N);

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  long long left, right, answer;

  left = 0;
  for (int i = 0; i < N; i++) {
    left = max(left, (long long)arr[i]);
  }

  right = 0;
  for (int i = 0; i < N; i++) {
    right += arr[i];
  }
  answer = 0;

  while (left <= right) {
    long long mid = (left + right) / 2;
    int divs = greedy(mid);

    if (divs <= K) {
      right = mid - 1;
      answer = mid;
    } else {
      left = mid + 1;
    }
  }

  cout << answer << endl;
}