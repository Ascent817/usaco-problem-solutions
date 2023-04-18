#include <iostream>
#include <cstdio>
#include <string.h>

using namespace std;

int main()
{
  freopen("blocks.in", "r", stdin);
  // freopen("blocks.out", "w", stdout);

  int N;
  cin >> N;

  int blocks[26];
  memset(blocks, 0, sizeof(blocks));
  string words[N][2];
  
  for (int i = 0; i < N; i++)
  {
    cin >> words[i][0];
    cin >> words[i][1];
  }

  return 0;
}