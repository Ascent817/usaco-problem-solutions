#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
#include <bitset>

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

  for (int i = 0; i < pow(2, N); i++)
  {
    std::string binary = bitset<8>(i).to_string();
    int instance_blocks[26];
    memset(instance_blocks, 0, sizeof(instance_blocks));

    for (int j = 0; j < N; j++)
    {
      int side = binary.at((8 - N) + j) - '0';
      cout << words[j][side] << endl;
    }
    cout << endl;
  }

  return 0;
}