#include <bits/stdc++.h>

using namespace std;

int main() {
  string original;
  cin >> original;
  string palindrome;
  char single = ' ';
  bool found = false;

  sort(original.begin(), original.end());

  while (original.length() > 0) {
    found = false;
    char target = original.at(0);

    for (int i = 1; i < original.length(); i++) {
      if (original.at(i) == target) {
        original.replace(0, 1, ""s);
        original.replace(i - 1, 1, ""s);
        palindrome.insert(0, 1, target);
        palindrome.insert(palindrome.length(), 1, target);
        found = true;
        break;
      }
    }

    if (!found) {
      if (single == ' ') {
        single = target;
        original.replace(0, 1, ""s);
      } else {
        cout << "NO SOLUTION\n";
        return 0;
      }
    }
  }

  if (single != ' ') {
    palindrome.insert(palindrome.length() / 2, 1, single);
  }

  cout << palindrome << endl;
}