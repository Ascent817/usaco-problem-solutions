#include <bits/stdc++.h>

using namespace std;

int main() {
  string original;
  cin >> original;
  
  string palindrome;
  vector<int> counts(26);
  pair<char, int> middleBlock = {' ', 0};

  for (char c : original) {
    counts[((int)c) - 65]++;
  }

  for (int i = 0; i < 26; i++) {
    if (counts[i] % 2 == 0) {
      if (counts[i] != 0) {
        palindrome.append(string(counts[i] / 2, (char)(i + 65)));
      }
    } else {
      if (middleBlock.first != ' ') {
        cout << "NO SOLUTION\n";
        return 0;
      } else {
        middleBlock = {(char)(i + 65), counts[i]};
        counts[i] = 0;
      }
    }
  }

  palindrome.append(string(middleBlock.second, middleBlock.first));

  for (int i = 25; i >= 0; i--) {
    if (counts[i] != 0) {
      palindrome.append(string(counts[i] / 2, (char)(i + 65)));
    }
  }

  cout << palindrome;
}