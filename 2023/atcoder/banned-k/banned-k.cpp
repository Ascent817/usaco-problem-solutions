#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> balls(N);
  vector<int> freqs(N + 1, 0);

  for (int i = 0; i < N; i++) {
    cin >> balls[i];
    freqs[balls[i]]++;
  }

  ll count = 0;
  for (int i = 0; i <= N; i++) {
   count += ((ll)freqs[i] * (freqs[i] - 1)) / 2;
  }

  for (int i = 0; i < N; i++) {
    cout << count - freqs[balls[i]] + 1 << "\n";
  }
}