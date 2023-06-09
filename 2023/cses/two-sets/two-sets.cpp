#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  long long target = (((double)N / 2) * (N + 1));
  long long partialSum = target / 2;
  set<long long> set1;

  if (target % 2 != 0) {
    cout << "NO" << endl;
    return 0;
  }

  long long sum = 0;

  for (int i = N; i > 0; i--) {
    if (sum < partialSum) {
      if (sum + i < partialSum) {
        set1.insert(i);
        sum += i;
      } else {
        set1.insert(partialSum - sum);
        sum += partialSum - sum;
      }
    } else {
      cout << "YES" << endl;
      cout << set1.size() << endl;

      for (int e : set1) {
        cout << e << " ";
      }

      cout << endl << N - set1.size() << endl;

      for (int j = 1; j < N; j++) {
        if (set1.find(j) == set1.end()) {
          cout << j << " ";
        }
      }

      cout << endl;
      return 0;
    }
  }

  cout << "NO" << endl;
}