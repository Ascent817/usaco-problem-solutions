#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  int target = (int)(((float)N / 2) * (N + 1));
  int partialSum = target / 2;
  set<int> set1;

  if (target % 2 != 0) {
    cout << "NO" << endl;
    return 0;
  }

  int sum = 0;

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
}