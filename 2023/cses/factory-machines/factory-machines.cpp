#include <bits/stdc++.h>

using namespace std;

vector<long long> machineTimes;
int N, T;

long long productsMade(long long mtime) {
  long long sum = 0;
  for (long long t : machineTimes) {
    sum += mtime / t;
    if (sum > T) {
      break;
    }
  }

  return sum;
}

int main() {
  cin >> N >> T;

  machineTimes.resize(N);

  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    machineTimes[i] = x;
  }

  long long left, right, problem;
  left = 1;
  right = 1e18;

  while (left <= right) {
    long long mid = (left + right) / 2;

    if (productsMade(mid) < T) {
      left = mid + 1;
    } else {
      problem = mid;
      right = mid - 1;
    }
  }

  cout << problem;
}