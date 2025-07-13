#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

void dfs(int n, vector<vector<int>> &graph, vector<int> &visited, int &count)
{
    visited[n] = count;
    count += 1;

    vector<int> &v = graph[n];
    for (int next : v)
    {
        if (!visited[next])
        {
            dfs(next, graph, visited, count);
        }
    }
}

void bfs(int start, vector<vector<int>> &graph, vector<int> &visited, int &count)
{
    visited[start] = count;
    count += 1;

    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        for (int next : graph[cur])
        {
            if (!visited[next])
            {
                q.push(next);
                visited[next] = count;
                //printf("viisted[%d] = %d\n", next, count);
                count += 1;
            }
        }
    }
}

int main()
{
    int n, m, r; cin >> n >> m >> r;
    vector<vector<int>> graph(n+1);
    vector<int> visited(n+1, 0);

    for (int i = 0; i < m; i++)
    {
        int u, v; cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    for (vector<int> &v : graph)
        sort(begin(v), end(v), greater<int>());

    int count = 1;
    bfs(r, graph, visited, count);

    for (int i = 1; i <= n; ++i) {
            cout << visited[i] << '\n';
    }

}