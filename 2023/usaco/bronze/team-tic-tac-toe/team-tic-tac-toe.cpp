#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

int main() {
  freopen("tttt.in", "r", stdin);
  freopen("tttt.out", "w", stdout);

  vector<vector<int>> board(3, vector<int>(3));
  
  for (int i = 0; i < 3; i++) {
    string s;
    cin >> s;
    for (int j = 0; j < 3; j++) {
      board[i][j] = s.at(j) - 'A';
    }
  }

  vector<vector<pair<int, int>>> lines = {
    {{0, 0}, {0, 1}, {0, 2}},
    {{1, 0}, {1, 1}, {1, 2}},
    {{2, 0}, {2, 1}, {2, 2}},
    {{0, 0}, {1, 0}, {2, 0}},
    {{0, 1}, {1, 1}, {2, 1}},
    {{0, 2}, {1, 2}, {2, 2}},
    {{0, 0}, {1, 1}, {2, 2}},
    {{0, 2}, {1, 1}, {2, 0}}
  };

  set<int> singleWins;
  set<pair<int, int>> teamWins;
  
  for (int i = 0; i < 8; i++) {
    vector<pair<int, int>> tri = lines[i];
    if (board[tri[0].fi][tri[0].se] == board[tri[1].fi][tri[1].se] && board[tri[1].fi][tri[1].se] == board[tri[2].fi][tri[2].se]) {
      singleWins.insert(board[tri[0].fi][tri[0].se]);
    } else if (board[tri[0].fi][tri[0].se] == board[tri[1].fi][tri[1].se] || board[tri[1].fi][tri[1].se] == board[tri[2].fi][tri[2].se] || board[tri[0].fi][tri[0].se] == board[tri[2].fi][tri[2].se]) {
      pair<int, int> team;
      if (board[tri[0].fi][tri[0].se] == board[tri[1].fi][tri[1].se]) {
        team = {board[tri[0].fi][tri[0].se], board[tri[2].fi][tri[2].se]};
      } else {
        team = {board[tri[0].fi][tri[0].se], board[tri[1].fi][tri[1].se]};
      } 

      if (team.fi > team.se) {
        int temp = team.fi;
        team.fi = team.se;
        team.se = temp;
      }

      teamWins.insert(team);
    }
  }

  cout << singleWins.size() << "\n" << teamWins.size();
}