#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

int MOD = 1000000007;

vector<int> choices;
unordered_map<int, int> cache;
int N, X;

int perms(int sum) {
  int ways = 0;

  if (cache.find(sum) != end(cache)) {
    return cache[sum];
  }

  if (sum > X) {
    return 0;
  } else if (sum == X) {
    return 1;
  }

  for (int i = 0; i < N; i++) {
    ways += perms(sum + choices[i]);
    ways %= MOD;
  }

  cache[sum] = ways;
  return ways;
}

int main() {
  cin >> N >> X;
  choices.resize(N);
  cache.reserve(X);
  
  for (int i = 0; i < N; i++) {
    cin >> choices[i];
  }

  cout << perms(0) << "\n";
}