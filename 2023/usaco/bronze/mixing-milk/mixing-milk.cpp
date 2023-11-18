#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

int main() {
  freopen("mixmilk.in", "r", stdin);
  freopen("mixmilk.out", "w", stdout);

  vector<int> capacities(3);
  vector<int> milk(3);

  for (int i = 0; i < 3; i++) {
    cin >> capacities[i] >> milk[i];
  }

  int current_bucket = 0;

  for (int i = 0; i < 100; i++) {
    int next_bucket = (current_bucket + 1) % 3;
    int space = capacities[next_bucket] - milk[next_bucket];
    int pour_amount = space > milk[current_bucket] ? milk[current_bucket] : space;

    milk[current_bucket] -= pour_amount;
    milk[next_bucket] += pour_amount;

    current_bucket = next_bucket;
  }

  cout << milk[0] << "\n" << milk[1] << "\n" << milk[2];
}