#include <bits/stdc++.h>
#define fi first
#define se second
#define all(x) (x).begin(), (x).end()
typedef long long ll;

using namespace std;

int main() {
  ios_base::sync_with_stdio;
  cin.tie();

  int T;
  cin >> T;

  for (int c = 0; c < T; c++) {
    int N;
    cin >> N;
    int sN = (N * (N - 1)) / 2;

    vector<int> arr(sN);

    for (int i = 0; i < sN; i++) {
      cin >> arr[i];
    }

    sort(all(arr));

    int i = N - 1;
    int cr = 0;
    vector<int> original;

    while(i > 0) {
      int mn = arr[cr];
      original.push_back(mn);
      cr += i;
      i--;
    }

    original.push_back(1000000000);
    for (int i = 0; i < N; i++) {
      cout << original[i] << " ";
    }
    cout << "\n";
  }
}