#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;


int main() {
  int N;
  ll sm;
  sm = 0;
  cin >> N;

  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    sm += x - 1;
  }

  cout << sm;
}