#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define all(x) (x).begin(), (x).end()

using namespace std;

ll A, B, X;

ll quote(ll n) {
  return A * n + B * int(log10(n) + 1);
}

int main() {
  cin >> A >> B >> X;

  ll left, right, answer;
  left = 0;
  right = 1000000000;
  answer = 0;

  while (left <= right) {
    ll mid = (left + right) / 2;

    if (quote(mid) <= X) {
      left = mid + 1;
      answer = mid;
    } else {
      right = mid - 1;
    }
  }

  cout << answer << endl;
}