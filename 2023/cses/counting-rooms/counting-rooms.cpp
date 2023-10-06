#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;
  
string nodes;
vector<bool> visited;
int N, M;

void bfs(int i) {
  if (nodes.at(i) == '#') {
    return;
  }
  
  visited[i] = true;

  if ((i + 1) % M != 0 && !visited[i + 1]) {
    bfs(i + 1);
  }

  if ((i % M) != 0 && !visited[i - 1]) {
    bfs(i - 1);
  }

  if (i + M < N * M && !visited[i + M]) {
    bfs(i + M);
  }

  if (i - M >= 0 && !visited[i - M]) {
    bfs(i - M);
  }
}

int main() {
  cin >> N >> M;
  visited.resize(N * M);

  for (int i = 0; i < N; i++) {
    string s;
    cin >> s;
    nodes.append(s);
  }

  int count = 0;
  for (int i = 0; i < N * M; i++) {
    if (nodes.at(i) == '.' && !visited[i]) {
      bfs(i);
      count++;
    }
  }

  std::cout << count << "\n";
}