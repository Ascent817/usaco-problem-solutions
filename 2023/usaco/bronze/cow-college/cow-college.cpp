#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

int N;
vector<int> cows;

int main() {
  cin >> N;
  cows.resize(N);

  for (int i = 0; i < N; i++) {
    cin >> cows[i];
  }
  
  sort(all(cows));

  ll profit = 0;
  ll cost = 0;

  for (int i = 0; i < N; i++) {
    if ((ll)cows[i] * (N - i) > profit) {
      cost = cows[i];
      profit = (ll)cows[i] * (N - i);
    }
  }

  cout << profit << " " << cost;
}