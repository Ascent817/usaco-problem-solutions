#include <bits/stdc++.h>
#include <numeric>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

ll A, B, C, D;

ll gcd(ll a, ll b) {
  if (b == 0) {
    return a;
  }
  return gcd(b, a % b);
}

ll lcm(ll a, ll b) {
  return (a / gcd(a, b)) * b;
}

int main() {
  cin >> A >> B >> C >> D;

  ll m = B;
  ll a = m - m / C - m / D + m / lcm(C, D);
  m = A - 1;
  ll b = m - m / C - m / D + m / lcm(C, D);
  
  cout << a - b;
}