#include <iostream>
#include <vector>
#include <queue>

using namespace std;


void topological_sort(int n, const vector<vector<int>> &graph, vector<int> &entry, vector<int> &res)
{
    priority_queue<int, vector<int>, greater<>> q;
    for (int i = 0; i < n; i++)
    {
        if (entry[i] == 0) q.push(i);
    }

    for (int i = 0; i < n; i++)
    {
        if (q.empty())
        { 
            printf("실패!\n");
            return;
        }

        int cur = q.top();
        q.pop();
        res.push_back(cur);

        for (int next : graph[cur])
        {
            entry[next] -= 1;
            if (entry[next] == 0)
                q.push(next);
        }
    }
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    
    /*
    민오는 다음의 세 가지 조건에 따라 문제를 풀 순서를 정하기로 하였다.

    1. N개의 문제는 모두 풀어야 한다.
    2. 먼저 푸는 것이 좋은 문제가 있는 문제는, 먼저 푸는 것이 좋은 문제를 반드시 먼저 풀어야 한다.
    3. 가능하면 쉬운 문제부터 풀어야 한다.

    4->2, 3->1  풀어야 햐는 순서는 3 1 4 2

    */

    int n, m; cin >> n >> m;
    vector<vector<int>> graph(n);
    vector<int> entry(n, 0);

    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        a--; b--;
        graph[a].push_back(b);
        entry[b] += 1;
    }

    vector<int> res;
    topological_sort(n, graph, entry, res);

    for (int i : res)
        cout << i+1 << ' ';
}