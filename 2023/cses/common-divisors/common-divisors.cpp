#include <bits/stdc++.h>
#define fi first
#define se second
#define ll long long
#define all(x) (x).begin(), (x).end()

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<int> frequency(1000001);

  for (int i = 0; i < N; i++) {
    int x;
    cin >> x;
    frequency[x]++;
  }

  int mx = 2;

  for (int i = 1; i < 1000001; i++) {
    int freq = 0;
    for (int j = i; j < 1000001; j += i) {
      freq += frequency[j];
    }

    if (freq >= 2) {
      mx = i;
    }
  }

  cout << mx;
}