#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()

using namespace std;

int main() {
  int N, K;
  cin >> N >> K;

  cout << ceil((double)(N - 1) / (K - 1));
}