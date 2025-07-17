#include <iostream>
#include <vector>
#include <queue>

using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n+1);
    vector<int> entry(n+1, 0);
    vector<int> res;
    for (int i = 0; i < m; i++)
    {
        int a,b; cin >> a >> b;
        graph[a].push_back(b);
        entry[b] += 1;
    }


    queue<int> q;
    for (int i = 1; i <= n; i++)
    {
        if (entry[i] == 0)
            q.push(i);
    }

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();
        res.push_back(cur);
        //("front %d\n", cur);

        for (int next : graph[cur])
        {
            entry[next] -= 1;
            if (entry[next] == 0)
                q.push(next);
        }
    }

    if (res.size() < n)
        cout << "cycle!!\n";
    else
    {
        for (int i : res)
            cout << i << ' ';
    }
}