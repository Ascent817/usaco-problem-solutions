#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

int N;
vector<int> cows;
vector<int> stalls;

int main() {
  cin >> N;

  cows.resize(N);
  stalls.resize(N);

  for (int i = 0; i < N; i++) {
    cin >> cows[i];
  }

  for (int i = 0; i < N; i++) {
    cin >> stalls[i];
  }

  sort(all(cows));
  reverse(all(cows));

  sort(all(stalls));

  ll product = 1;
  for (int i = 0; i < N; i++) {
    for (int j = 0; j < N; j++) {
      if (stalls[j] >= cows[i]) {
        if (N - j - i > 0) {
          product *= N - j - i;
        }
        break;
      }
    }
  }

  cout << product;

}