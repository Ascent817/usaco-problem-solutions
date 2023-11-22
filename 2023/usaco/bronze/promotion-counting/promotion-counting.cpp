#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

int main() {
  freopen("promote.in", "r", stdin);
  freopen("promote.out", "w", stdout);

  int b1, b2, s1, s2, g1, g2, p1, p2;
  cin >> b1 >> b2 >> s1 >> s2 >> g1 >> g2 >> p1 >> p2;

  int p = p2 - p1;
  int g = g2 - (g1 - p);
  int s = s2 - (s1 - g);

  cout << s << "\n" << g << "\n" << p;
}