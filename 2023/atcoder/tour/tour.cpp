#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

int N, M;

vector<vector<int>> roads;
vector<int> visited;

int bfs(int cur) {
  
}

int main() {
  cin >> N >> M;

  roads.resize(N);
  visited.resize(N);

  for (int i = 0; i < M; i++) {
    int a, b;
    cin >> a >> b;
    roads[a - 1].push_back(b - 1);
  }


}