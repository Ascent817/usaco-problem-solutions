#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

int N, L;
vector<int> cits;

int calculateH() {
  int h = 0;
  for (int i = 0; i < N; i++) {
    if (cits[i] >= cits.size() - i) {
      break;
    }
    h = cits[i];
  }
  return h;
}

int main() {
  cin >> N >> L;

  cits.resize(N);

  for (int i = 0; i < N; i++) {
    cin >> cits[i];
  }

  sort(all(cits));

  int h = calculateH();

  bool higherH = true;
  
  while (higherH) {
    int l = L;
    for (int i = N - 1; i >= N - h - 1; i--) {
      if (cits[i] >= h + 1) {
        continue;
      } else if (cits[i] + 1 >= h + 1 && l > 0) {
        l--;
      } else {
        higherH = false;
        break;
      }
    }

    if (higherH) {
      h++;
    }
  }
  
  cout << h;
}