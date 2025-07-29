#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// bool dijkstra(int v, int e, vector<vector<pair<int, int>>> &map)
// {
//     priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
//     pq.push()
// }

void floyd_warshall(int v, vector<vector<long long>> &res)
{
    for (int i = 0; i < v; i++)
    {
        for (int st = 0; st < v; st++)
        {
            for (int end = 0; end < v; end++)
            {
                res[st][end] = min(res[st][end], res[st][i] + res[i][end]);
            }
        }
    }
}

int main()
{
    int v, e; cin >> v >> e;
    //vector<vector<pair<int, int>>> map(v);
    vector<vector<long long>> res(v, vector<long long>(v, __INT_MAX__));
    for (int i = 0; i < e; i++)
    {
        long long  a, b, c; cin >> a >> b >> c;
        //map[a].push_back({b, c});
        res[a-1][b-1] = min(res[a-1][b-1], c);
    }

    floyd_warshall(v, res);

    long long int result = __INT_MAX__;
    for (int i = 0; i < v; i++)
    {
        result = min(result, res[i][i]);
    }

    if (result == __INT_MAX__) cout << -1;
    else cout << result;

}