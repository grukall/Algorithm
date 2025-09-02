#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int updown[4] = {1, 0, -1, 0};
int rightleft[4] = {0, 1, 0, -1};
int m, n;

int ways[501][501] = {-1,};

int dfs(vector<vector<int>> &map, int y, int x)
{
//  printf("cur {%d, %d}\n", y, x);
  if (y == m-1 && x == n-1)
  {
    //printf("{%d, %d} return %d\n", y, x, 1);
    return 1;
  }
  if (ways[y][x] != -1)
  { 
    //printf("{%d, %d} return %d\n", y, x, ways[y][x]);
    return ways[y][x];
  }
  ways[y][x] = 0;

  int curh = map[y][x];
  for (int i = 0; i < 4; i++)
  {
    int nexty = y + updown[i];
    int nextx = x + rightleft[i];
    if (nexty < 0 || nexty >= m) continue;
    if (nextx < 0 || nextx >= n) continue;

    int nexth = map[nexty][nextx];

    if (nexth < curh)
    {
      ways[y][x] += dfs(map, nexty, nextx);
    }
  }

//  printf("{%d %d} = %d\n", y, x, ways[y][x]);
  return ways[y][x];
}


int main()
{
  cin.tie(0);
  ios::sync_with_stdio(false);
  memset(ways, -1, sizeof(ways));

  cin >> m >> n;
  vector<vector<int>> map(m, vector<int>(n));
  for (vector<int> &v : map)
  {
    for (int &h : v) cin >> h;
  }

  // for (vector<int> &v : map)
  // {
  //   for (int &h : v) cout << h << ' ';
  //   cout << '\n';
  // }

  cout << dfs(map, 0, 0);
} 
