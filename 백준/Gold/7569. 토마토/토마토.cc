#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dir_h[6] = {0, 0, 0, 0, 1, -1};
int dir_td[6] = {1, 0, -1, 0, 0, 0};
int dir_rl[6] = {0, 1, 0, -1, 0, 0};
int n, m, h;

struct tmt
{
  int x;
  int y;
  int z;
};

void bfs(vector<vector<vector<int>>> &box, vector<vector<vector<int>>> &visited, vector<tmt> &tmts, int total)
{
  queue<tmt> q;
  for (tmt tmt : tmts)
  {
    q.push(tmt);
    //visited[tmt.second][tmt.first] = 1;
    total--;
    //printf("start [%d][%d], day = %d, total = %d\n", tmt.second, tmt.first, visited[tmt.second][tmt.first], total);
  }

  if (total == 0)
  {
    //익은 토마토밖에 없음
    cout << 0;
    return;
  }

  while (!q.empty())
  {
    tmt cur = q.front();
    q.pop();
    //printf("cur [%d][%d]\n", cur.second, cur.first);

    for (int dir_cnt = 0; dir_cnt < 6; dir_cnt++)
    {
      //북동남서 순서로
      int x = cur.x + dir_rl[dir_cnt];
      int y = cur.y + dir_td[dir_cnt];
      int z = cur.z + dir_h[dir_cnt];

      //토마토가 있고 방문한 적이 없으면.
      if (x >= 0 && y >= 0 && z >= 0 && x < m && y < n && z < h
         && box[z][y][x] == 0 && !visited[z][y][x])
      {
        visited[z][y][x] = visited[cur.z][cur.y][cur.x] + 1;
        q.push({x, y, z});
        total--;
        //printf("visit [%d][%d], day = %d, total = %d\n", y, x, visited[y][x], total);
        if (total == 0)
        {
          //모든 토마토 방문, 조기 종료
          cout << visited[z][y][x];
          return;
        }
      }
    }
  }

  cout << -1;
}

int main()
{
  cin >> m >> n >> h;
  vector<vector<vector<int>>> box(h, vector<vector<int>>(n, vector<int>(m, 0)));
  vector<vector<vector<int>>> visited(box);
  vector<tmt> tmts;
  int total = 0;

  for (int ch = 0; ch < h; ch++)
  {
    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m; j++)
      {
        cin >> box[ch][i][j];

        //printf("box[%d][%d] = %d\n", n, m, box[i][j]);
        
        if (box[ch][i][j] >= 0) total++;

        //익은 토마토면 탐색 시작 지점 등록
        if (box[ch][i][j] == 1)
          tmts.push_back({j, i, ch});
      }
    }
  }

  bfs(box, visited, tmts, total);
}