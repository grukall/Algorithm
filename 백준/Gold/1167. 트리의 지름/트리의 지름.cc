#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

vector<bool> visited;
vector<vector<pair<int, int>>> res;
int max_dist = 0;
int farthest_node = 0;

void dfs(int st, int max)
{
    visited[st] = true;

    if (max_dist < max)
    {
        max_dist = max;
        farthest_node = st;
    }

    for (const pair<int, int> &next : res[st])
    {
        if (!visited[next.first])
            dfs(next.first, max + next.second);
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int v; cin >> v;
    res.resize(v+1);
    visited.resize(v+1, false);

    for (int i = 0; i < v; i++)
    {
        int num; cin >> num;
        while (true)
        {
            int next; cin >> next;
            if (next == -1)
                break;
            
            int cost; cin >> cost;
            res[num].push_back({next, cost});
        }
    }

    //임의의 점에서 가장 먼 점 찾기
    dfs(1, 0);

    fill(visited.begin(), visited.end(), false);
    max_dist = 0;
    dfs(farthest_node, 0);

    cout << max_dist;
}