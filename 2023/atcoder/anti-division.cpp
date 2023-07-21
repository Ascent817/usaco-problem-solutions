#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

int A, B, C, D;

int filter(ll F) {
  int R, L;

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

  int n = (B - A) + 1;

  n -= filter(C);
  n -= filter(D);
  
  cout << n;
}