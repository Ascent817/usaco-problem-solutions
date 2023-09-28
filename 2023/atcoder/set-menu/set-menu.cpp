#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

int main() {
  int N, M, P;

  cin >> N >> M >> P;

  vector<int> a;
  vector<int> b;

  vector<ll> pB;

  a.resize(N);
  b.resize(M);
  pB.resize(M);

  for (int i = 0; i < N; i++) {
    cin >> a[i];
  }

  for (int i = 0; i < M; i++) {
    cin >> b[i];
  }

  sort(all(b));

  ll c = 0;

  for (int i = 0; i < M; i++) {
    c += b[i];
    pB[i] = c;
  }

  ll sm = 0;

  for (int i = 0; i < N; i++) {
    ll left, right, answer;
    left = 0;
    right = M - 1;
    answer = -1;
    
    while (left <= right) {
      int mid = (left + right) / 2;
      
      if (a[i] + b[mid] <= P) {
        left = mid + 1;
        answer = mid;
      } else {
        right = mid - 1;
      }
    }

    if (answer == -1) {
      sm += (ll)M * P;
    } else {
      sm += ((ll)(a[i] * (ll)(answer + 1) + pB[answer]) + ((ll)(M - answer - 1) * P));
    }
  }

  cout << sm;
}