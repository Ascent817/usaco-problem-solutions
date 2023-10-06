#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

int N, M;
vector<vector<int>> roads;
vector<bool> visited;

void bfs(int cur) {
  queue<int> q;
  q.push(cur);

  while (!q.empty()) {
    int node = q.front();
    visited[node] = true;
    q.pop();

    for (int i = 0; i < roads[node].size(); i++) {
      if (!visited[roads[node][i]])
      q.push(roads[node][i]);
    }
  }
}

int main() {
  cin >> N >> M;

  roads.resize(N);
  visited.resize(N);

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    roads[a - 1].push_back(b - 1);
    roads[b - 1].push_back(a - 1);
  }

  vector<int> ccs;
  for (int i = 0; i < N; i++) {
    if (!visited[i]) {
      bfs(i);
      ccs.push_back(i);
    }
  }

  cout << ccs.size() - 1 << "\n";

  for (int i = 1; i < ccs.size(); i++) {
    cout << ccs[i] + 1 << " " << ccs[i - 1] + 1 << "\n";
  }
}