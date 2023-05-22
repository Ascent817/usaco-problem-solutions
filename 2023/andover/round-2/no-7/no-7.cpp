#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;
  N--;
  string s = to_string(N);
  for (int i = 0; i < s.length(); i++) {
    if (s[i] == '7') {
      s[i] = '6';
      s.replace(i + 1, s.length() - (i + 1), s.length() - (i + 1), '9');
      cout << s << endl;
      return 0;
    }
  }
  cout << N << endl;
}