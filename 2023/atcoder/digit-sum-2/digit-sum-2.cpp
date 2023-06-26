#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

int main() {
  string N;
  cin >> N;

  for (int i = 1; i < N.length(); i++) {
    char c = N[i] - '0';
    if (c != 9) {
      N[i - 1]--;
      fill(N.begin() + i, N.end(), '9');
      int sum = 0;

      for (int j = 0; j < N.length(); j++) {
        sum += N[j] - '0';
      }

      cout << sum;
      return 0;
    }
  }
}