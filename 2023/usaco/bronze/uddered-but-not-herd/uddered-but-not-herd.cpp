#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

int main() {
  map<char, int> alphabet;

  for (int i = 0; i < 26; i++) {
    char c = getchar();
    alphabet.insert({c, i});
  }

  string s;
  cin >> s;

  int ans = 1;

  for (int i = 1; i < s.length(); i++) {
    if (alphabet.at(s[i]) <= alphabet.at(s[i - 1])) {
      ans++;
    }
  }
  
  cout << ans;
}