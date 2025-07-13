#include <iostream>
#include <vector>
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
        sort(begin(v), end(v), greater());

    int count = 1;
    dfs(r, graph, visited, count);

    // 방문하지 않은 노드에 대해 0 출력
    for (int i = 1; i <= n; ++i) {
            cout << visited[i] << '\n';
    }

}