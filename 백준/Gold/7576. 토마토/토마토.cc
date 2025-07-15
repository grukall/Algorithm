#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int dir_td[4] = {1, 0, -1, 0};
int dir_rl[4] = {0, 1, 0, -1};
int n, m;

void bfs(vector<vector<int>> &box, vector<vector<int>> &visited, vector<pair<int, int>> &tmts, int total)
{
  queue<pair<int, int>> q;
  for (pair<int, int> tmt : tmts)
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
    pair<int, int> cur = q.front();
    q.pop();
    //printf("cur [%d][%d]\n", cur.second, cur.first);

    for (int dir_cnt = 0; dir_cnt < 4; dir_cnt++)
    {
      //북동남서 순서로
      int x = cur.first + dir_rl[dir_cnt];
      int y = cur.second + dir_td[dir_cnt];

      //토마토가 있고 방문한 적이 없으면.
      if (x >= 0 && y >= 0 && x < m && y < n
         && box[y][x] == 0 && !visited[y][x])
      {
        visited[y][x] = visited[cur.second][cur.first] + 1;
        q.push({x, y});
        total--;
        //printf("visit [%d][%d], day = %d, total = %d\n", y, x, visited[y][x], total);
        if (total == 0)
        {
          //모든 토마토 방문, 조기 종료
          cout << visited[y][x];
          return;
        }
      }
    }
  }

  cout << -1;
}

int main()
{
  cin >> m >> n;
  vector<vector<int>> box(n, vector<int>(m, 0));
  vector<vector<int>> visited(box);
  vector<pair<int, int>> tmts;
  int total = 0;

  for (int i = 0; i < n; i++)
  {
    for (int j = 0; j < m; j++)
    {
      cin >> box[i][j];

      //printf("box[%d][%d] = %d\n", n, m, box[i][j]);
      
      if (box[i][j] >= 0) total++;

      //익은 토마토면 탐색 시작 지점 등록
      if (box[i][j] == 1)
        tmts.push_back({j, i});
    }
  }

  bfs(box, visited, tmts, total);
}