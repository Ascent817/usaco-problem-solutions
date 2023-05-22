#include <cstdio>
#include <iostream>
#include <vector>
#include <unordered_set>

using namespace std;

vector<int> barn1(10);
vector<int> barn2(10);
vector<int> results;

void calculateMove(int depth, vector<int> moves) {
  unordered_set<int> possibleMoves;
  for (int n : depth % 2 == 0 ? barn2 : barn1) {
    possibleMoves.insert(n);
  }

  for (int n : possibleMoves) {
    cout << n + " ";
  }
}

int main() {
  freopen("backforth.in", "r", stdin);
  freopen("backforth.out", "w", stdout);

  for (int i = 0; i < 10; i++) {
    cin >> barn1[i];
  }

  for (int i = 0; i < 10; i++) {
    cin >> barn2[i];
  }

  calculateMove(0, vector<int>(0));
}