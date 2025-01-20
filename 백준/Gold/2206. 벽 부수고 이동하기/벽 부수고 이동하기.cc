#include <iostream>
#include <vector>
#include <queue>
#include <unistd.h>
#include <cstring>
#include <tuple>

using namespace std;
int n, m;
int map[1001][1001];
int visited[1001][1001][2];  // [행][열][벽 파괴 여부]

void bfs()
{
    queue<tuple<int, int, int>> q;  // (N, M, 벽 파괴 여부)
    q.push({1, 1, 0});
    visited[1][1][0] = 1;

    //우 하 왼 상상
    int dx[4] = {1, 0, -1, 0};
    int dy[4] = {0, 1, 0, -1};

    while (!q.empty())
    {
        //printf("hreer");
        auto [y, x, broken] = q.front();
       //printf("visit (%d, %d, %d), visited = %d\n", y, x, broken, visited[y][x][broken]);
        //sleep(1);
        if (x == m && y == n)
        {
            cout << visited[y][x][broken];
            return;
        }
        q.pop();

        //우 아래 왼 위 순으로.
        
        for (int way = 0; way < 4; way++)
        {
            int nx = x + dx[way];
            int ny = y + dy[way];

            if (nx < 1 || nx > m || ny < 1 || ny > n)
                continue;

            //이동할 곳이 벽이고, 아직 가지 않았고, 벽을 부순 적이 없다면
            if (map[ny][nx] == 1 && broken == 0 && visited[ny][nx][1] == 0)
            {
                visited[ny][nx][1] = visited[y][x][0] + 1;
                q.push({ny, nx, 1});
            }
            else if (map[ny][nx] == 0 && visited[ny][nx][broken] == 0) //이동할 수 있는 곳이고, 이동한 곳을 아직 방문한 적이 없다면
            {
                visited[ny][nx][broken] = visited[y][x][broken] + 1;
                q.push({ny, nx, broken});
            }
        }
    }

    cout << -1;
}

int main()
{
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
    {
        string row;
        cin >> row;
        for (int j = 1; j <= m; j++)
        {
            map[i][j] = row[j - 1] - '0';
        }
    }

    memset(visited, 0, sizeof(visited));

    bfs();
}