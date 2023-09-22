#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

ll FUNCTION(int x) {
  int A, B;
  A = 10;
  B = 7;
  
  ll y = A * x + B * int(log10(x) + 1);
  return y;
}

int main() {
  int graphSteps = 2000;
  for (int i = 1; i <= graphSteps; i++) {
    cout << FUNCTION(i) << "\n";
  }
}