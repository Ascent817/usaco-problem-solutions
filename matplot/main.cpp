#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

int N;
vector<int> arr;

int msum(int m) {
  int sm = 0;
  for (int i = 0; i < N; i++) {
    sm += m % arr[i];
  }
  return sm;
}

int main() {
  cin >> N;

  arr.resize(N);
  for (int i = 0; i < N; i++) {
    cin >> arr[i];
  }

  int graphSteps = 200;
  for (int i = 0; i < graphSteps; i++) {
    cout << msum(i) << "\n";
  }
}