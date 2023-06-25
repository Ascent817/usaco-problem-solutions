#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> arr(N);
  long double sum = 0;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    sum += arr[i];
  }

  sum *= sum / 2;

  for (int i = 0; i < N; i++) {
    sum -= (long double)(arr[i] * arr[i]) / 2;
  }

  cout << sum;
}