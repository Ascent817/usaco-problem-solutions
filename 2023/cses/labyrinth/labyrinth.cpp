#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

int N, M;
pair<int, int> start, goal;
vector<vector<int>> maze;
vector<vector<pair<int, int>>> parents;
vector<vector<bool>> visited;

const vector<pair<int, int>> neighbors = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};

void bfs() {
  queue<pair<int, int>> q;
  q.push(start);

  while (!q.empty()) {
    pair<int, int> node = q.front();
    q.pop();

    visited[node.fi][node.se] = true;

    for (pair<int, int> n : neighbors) {
      pair<int, int> newCoord = {node.fi + n.fi, node.se + n.se};

      if (newCoord.fi < 0 || newCoord.se < 0 || newCoord.fi >= N || newCoord.se >= M) {
        continue;
      }

      if (maze[newCoord.fi][newCoord.se] == 'B') {
        parents[newCoord.fi][newCoord.se] = node;
        visited[newCoord.fi][newCoord.se] = true;
        return;
      }

      if (maze[newCoord.fi][newCoord.se] == '.' && !visited[newCoord.fi][newCoord.se]) {
        parents[newCoord.fi][newCoord.se] = node;
        q.push({newCoord.fi, newCoord.se});
      }
    }
  }
}

int main() {
  cin >> N >> M;
  maze.resize(N);
  parents.resize(N);
  visited.resize(N);

  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    maze[i].resize(M);
    parents[i].resize(M);
    visited[i].resize(M);

    for (int j = 0; j < M; j++) {
      if (s[j] == 'A') {
        start = {i, j};
      } else if (s[j] == 'B') {
        goal = {i, j};
      }

      maze[i][j] = s[j];
    }
  }

  bfs();
  
  if (!visited[goal.fi][goal.se]) {
    cout << "NO" << "\n";
    return 0;
  }

  cout << "YES" << "\n";

  pair<int, int> ptr = goal;
  string path;

  while (true) {

    if (ptr.fi == start.fi && ptr.se == start.se) {
      break;
    }

    if (parents[ptr.fi][ptr.se].se > ptr.se) {
      path += 'L';
    } else if (parents[ptr.fi][ptr.se].se < ptr.se) {
      path += 'R';
    } else if (parents[ptr.fi][ptr.se].fi > ptr.fi) {
      path += 'U';
    } else {
      path += 'D';
    }

    ptr = parents[ptr.fi][ptr.se];
  }

  reverse(all(path));

  cout << path.length() << "\n" << path << "\n";
}