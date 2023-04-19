#include <iostream>
#include <cstdio>
#include <string.h>
#include <cmath>
#include <bitset>

using namespace std;

int main()
{
  freopen("blocks.in", "r", stdin);
  freopen("blocks.out", "w", stdout);
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
    std::string binary = bitset<10>(i).to_string();
    int instance_blocks[26];
    memset(instance_blocks, 0, sizeof(instance_blocks));

    for (int j = 0; j < N; j++)
    {
      int side = binary.at((10 - N) + j) - '0';
      string word = words[j][side];
      
      for (char c : word)
      {
        instance_blocks[c - (int)'a']++;
      }
    }

    for (int k = 0; k < 26; k++)
    {
      if (instance_blocks[k] > blocks[k])
      {
        blocks[k] = instance_blocks[k];
      }
    }
  }

  for (int n : blocks)
  {
    cout << n << endl;
  }

  return 0;
}