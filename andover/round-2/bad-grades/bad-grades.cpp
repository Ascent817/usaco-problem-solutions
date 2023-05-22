#include <bits/stdc++.h>

using namespace std;

int main() {
  int N;
  cin >> N;

  for(int i = 0; i < N; i++) {
    int grade;
    cin >> grade;

    if (grade >= 60) {
      cout << grade << endl;
    }
  }
}