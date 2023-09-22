#include <iostream>

using namespace std;

int lowest = 100000;
int N;

void button(int moves, int x, int option) {
  if (x == N) {
      if (moves < lowest) {
        lowest = moves;
      }
      return;
  } else {
    if (option == 0) {
        if ((3 * x + 2) <= N) {
          button(moves + 1, 3 * x + 2, 0);
          button(moves + 1, 3 * x + 2, 1);
        }
    } else {
      button(moves + 1, x + 1, 0);
      button(moves + 1, x + 1, 1);
    }
  }
}

int main() {
  int x = 1;
  cin >> N;

  button(0, x, 0);

  cout << lowest << endl;
}