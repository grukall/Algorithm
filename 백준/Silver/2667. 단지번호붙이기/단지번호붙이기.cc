#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int area;
int n;
vector<int> area_cnt;

void dfs(int x, int y, vector<vector<bool>> &visited, vector<vector<bool>> &map, bool &barea)
{
    if (x < 0 || x > n || y < 0 || y > n) return;

    if (visited[y][x]) return;
    if (!map[y][x]) return;

    //만약 집이 있다면 탐색 시작
    if (!barea)
    {
        area += 1;
        area_cnt.push_back(1);
        barea = true;

        //printf("\n\n---start area %d [%d][%d]\n", area, y, x);
    }
    else
    {
        area_cnt[area]++;
        //printf("area_cnt[%d] = %d, ", area, area_cnt[area]);
    }

    visited[y][x] = true;
    //printf("visited[%d][%d]\n", y, x);

    if (x+1 < n && !visited[y][x+1] && map[y][x+1])
        dfs(x+1, y, visited, map, barea);

    if (x-1 >= 0 && !visited[y][x-1] && map[y][x-1])
        dfs(x-1, y, visited, map, barea);

    if (y+1 < n && !visited[y+1][x] && map[y+1][x])
        dfs(x, y+1, visited, map, barea);

    if (y-1 >= 0 && !visited[y-1][x] && map[y-1][x])
        dfs(x, y-1, visited, map, barea);
}



int main()
{
    cin >> n;

    //printf("n = %d\n", n);
    vector<vector<bool>> visited(n, vector<bool>(n, 0));
    vector<vector<bool>> map(n, vector<bool>(n, 0));

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        { 
            char c; cin >> c;
            map[i][j] = c == '1';
        }
    }

    area = -1;
    bool b;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            b = false;
            dfs(j, i, visited, map, b);
        }
    }

    cout << area + 1 << '\n';
    sort(area_cnt.begin(), area_cnt.end());
    for (int count : area_cnt)
        cout << count << '\n';
}