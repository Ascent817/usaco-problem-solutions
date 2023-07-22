#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

const int MOD = 1000000007;

int main() {
  int N;
  cin >> N;

  vector<ll> arr(N);
  ll sum = 0;

  for (int i = 0; i < N; i++) {
    cin >> arr[i];
    sum += arr[i];
  }

  ll answer = 0;

  for (int i = 0; i < N; i++) {
    sum -= arr[i];
    answer += arr[i] * (sum % MOD);
    answer = answer % MOD;
  }

  cout << answer;
}