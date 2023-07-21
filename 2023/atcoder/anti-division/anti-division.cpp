#include <bits/stdc++.h>
#include <numeric>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

ll A, B, C, D;

ll filter(ll F) {
  ll R, L;

  if (A % F == 0) {
    L = A;
  } else {
    L = A + (F - (F % A));
  }

  if (B % F == 0) {
    R = B;
  } else {
    R = B - (B % F);
  }

  if (L > B || R < A) {
    return 0;
  }

  return (R - L) / F + 1;
}


int main() {
  cin >> A >> B >> C >> D;

  ll n = (B - A) + 1;

  n -= filter(C);
  n -= filter(D);
  n += filter((C * D) / __gcd(C, D));
  
  cout << endl << n;
}