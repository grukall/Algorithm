#include <iostream>
#include <vector>
#include <queue>

using namespace std;

bool map[101][101] = {false};
bool visited[101][101] = {false,};
int n, m;

int dir_updown[4] = {1, 0, -1, 0};
int dir_leftright[4] = {0, -1, 0, 1};

struct block
{
    int x;
    int y;
    int lv;
};


void bfs()
{
    block start = {0, 0, 1};
    queue<block> q;
    q.push(start);
    
    while (!q.empty())
    {
        block cur = q.front();
        q.pop();

        if (cur.x == m-1 && cur.y == n-1)
        {
            cout << cur.lv;
            break;
        }

        visited[cur.y][cur.x] = true;
        int curlv = cur.lv;

        for (int diri = 0; diri < 4; diri++)
        {
            int nx = cur.x + dir_leftright[diri];
            int ny = cur.y + dir_updown[diri];

            if (ny < 0 || ny >= n || nx < 0 || nx >= m)
                continue;
            
            if (map[ny][nx] && !visited[ny][nx])
            {
                visited[ny][nx] = true;
                q.push({nx, ny, curlv+1});
            }
        }

    }
}

int main()
{
    cin >> n >> m;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            char c; cin >> c;
            if (c == '1') map[i][j] = true;
        }
    }

    bfs();

}