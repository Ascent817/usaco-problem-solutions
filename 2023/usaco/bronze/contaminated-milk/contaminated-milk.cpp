#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

struct DrinkEvent {
  int person;
  int milk;
  int time;
};

int main() {
  freopen("badmilk.in", "r", stdin);
  freopen("badmilk.out", "w", stdout);

  int N, M, D, S;
  cin >> N >> M >> D >> S;

  vector<DrinkEvent> drinkevents;
  unordered_map<int, int> sickevents;
  
  for (int i = 0; i < D; i++) {
    int p, m, t;
    cin >> p >> m >> t;
    drinkevents.push_back({p, m, t});
  }

  for (int i = 0; i < S; i++) {
    int p, t;
    cin >> p >> t;
    sickevents.insert({p, t});
  }

  vector<set<int>> sickdrinkers(M + 1);
  vector<set<int>> healthydrinkers(M + 1);

  for (DrinkEvent de : drinkevents) {
    if (sickevents.find(de.person) != sickevents.end()) {
      // Person got sick, but before or after drinking this milk?
      if (sickevents.at(de.person) > de.time) {
        sickdrinkers[de.milk].insert(de.person);
      } else {
        healthydrinkers[de.milk].insert(de.person);
      }
    } else {
      healthydrinkers[de.milk].insert(de.person);
    }
  }

  // Find the milk with the most confirmed sick people.
  // After all, only one milk is bad, so it must have the max amount of sick people.

  int mx = 0;
  int badmilk = 0;

  for (int i = 1; i <= M; i++) {
    if (sickdrinkers[i].size() > mx) {
      mx = sickdrinkers[i].size();
      badmilk = i;
    }
  }

  cout << sickdrinkers[badmilk].size() + healthydrinkers[badmilk].size();
}