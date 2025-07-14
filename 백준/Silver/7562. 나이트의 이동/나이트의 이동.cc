#include <iostream>
#include <vector>
#include <queue>
#include <string.h>

using namespace std;

bool visited[300][300] = {false,};

int dir_updown[8] = {2, 1, -1, -2, -2, -1, 1, 2};
int dir_leftright[8] = {1, 2, 2, 1, -1, -2, -2, -1};

struct block
{
    int x;
    int y;
    int lv;
};


void bfs(int l, block start, block goal)
{
    queue<block> q;
    q.push(start);
    
    while (!q.empty())
    {
        block cur = q.front();
        q.pop();

        if (cur.x == goal.x && cur.y == goal.y)
        {
            cout << cur.lv << '\n';
            return;
        }

        visited[cur.y][cur.x] = true;
        int curlv = cur.lv;

        for (int diri = 0; diri < 8; diri++)
        {
            int nx = cur.x + dir_leftright[diri];
            int ny = cur.y + dir_updown[diri];

            if (ny < 0 || ny >= l || nx < 0 || nx >= l)
                continue;
            
            if (!visited[ny][nx])
            {
                visited[ny][nx] = true;
                q.push({nx, ny, curlv+1});
            }
        }

    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    for (int i = 0; i < T; i++)
    {
        memset(visited, false, sizeof(visited));

        int l; cin >> l;
        int curx, cury; cin >> curx >> cury;
        int x, y; cin >> x >> y;
        bfs(l, {curx, cury, 0}, {x, y, 0});
    }

}