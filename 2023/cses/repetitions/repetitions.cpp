#include <bits/stdc++.h>

using namespace std;

int main() {
  string dna;
  char prev = ' ';
  int longest = 1;
  int current = 1;
  cin >> dna;

  for (char c : dna) {
    if (c == prev) {
      current++;
    } else {
      longest = max(current, longest);
      current = 1;
    }

    prev = c;
  }

  longest = max(current, longest);

  cout << longest << endl;
}