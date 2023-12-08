#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

int main() {
  int N;
  cin >> N;

  vector<string> blocks(4);

  for (int i = 0; i < 4; i++) {
    cin >> blocks[i];
  }

  for (int i = 0; i < N; i++) {
    bool isPossible = false;
    vector<int> order = {0, 1, 2, 3};
    string word;
    cin >> word;

    do {
      bool possible = true;

      for (int j = 0; j < word.length(); j++) {
        if (blocks[order[j]].find(word.at(j)) == -1) possible = false;
      }

      if (possible) {
        isPossible = true;
        break;
      }
    } while (next_permutation(all(order)));
    
    cout << (isPossible ? "YES" : "NO") << "\n"; 
  }
}