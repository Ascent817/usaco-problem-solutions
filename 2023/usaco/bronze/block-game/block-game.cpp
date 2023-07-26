#include <string.h>
#include <cstdio>
#include <iostream>
#include <vector>

using namespace std;

vector<int> charCount(string word) {
  vector<int> counts(26);
  for (char c : word) {
    counts[c - 'a']++;
  }
  return counts;
}

int main() {
  freopen("blocks.in", "r", stdin);
  freopen("blocks.out", "w", stdout);
  int N;
  cin >> N;

  vector<int> blocks(26);
  string words[N][2];

  for (int i = 0; i < N; i++) {
    cin >> words[i][0];
    cin >> words[i][1];

    vector<int> count1 = charCount(words[i][0]);
    vector<int> count2 = charCount(words[i][1]);

    for (int l = 0; l < 26; l++) {
      blocks[l] += max(count1[l], count2[l]);
    }
  }

  for (int n : blocks) {
    cout << n << endl;
  }

  return 0;
}