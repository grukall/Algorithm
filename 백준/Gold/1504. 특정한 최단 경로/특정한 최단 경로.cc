#include <iostream>
#include <vector>
#include <queue>

using namespace std;

vector<vector<pair<int, int>>> map;

int dijkstra(int start, int end, int v)
{
    vector<int> distance(v+1, __INT_MAX__);
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    
    distance[start] = 0;
    pq.push({start, 0});

    while (!pq.empty())
    {
        pair<int, int> cur = pq.top();
        pq.pop();

        int v = cur.first;
        int cd = cur.second;
       // printf("cur = %d, cd = %d\n", v, cd);

        if (cd > distance[v])
            continue;
        
        for (const auto &[next, cost] : map[v])
        {
            int next_dist = cd + cost;
            if (next_dist < distance[next])
            {
                distance[next] = next_dist;
                //printf("distance[%d] = %d\n", next, next_dist);
                pq.push({next, next_dist});
            }
        }
    }

    if (distance[end] == __INT_MAX__)
        return -1;
    return distance[end];
}


int main()
{
    int n, e; cin >> n >> e;
    map.resize(n+1);
    for (int i = 0; i < e; i++)
    { 
        int a, b, c; cin >> a >> b >> c;
        map[a].push_back({b, c});
        map[b].push_back({a, c});
    }

    int v1, v2; cin >> v1 >> v2;

    //0~v1 + v1~v2 + v2~n
    int res = 0;
    int r = dijkstra(1, v1, n);
    if (r == -1)
    {
        cout << -1;
        return 0;
    }
    else res += r;

    r = dijkstra(v1, v2, n);
    if (r == -1)
    {
        cout << -1;
        return 0;
    }
    else res += r;

    r = dijkstra(v2, n, n);
    if (r == -1)
    {
        cout << -1;
        return 0;
    }
    else res += r;

    int res2 = 0;

    
    r = dijkstra(1, v2, n);
    if (r == -1)
    {
        cout << -1;
        return 0;
    }
    else res2 += r;
    
    r = dijkstra(v2, v1, n);
    if (r == -1)
    {
        cout << -1;
        return 0;
    }
    else res2 += r;
    
    r = dijkstra(v1, n, n);
    if (r == -1)
    {
        cout << -1;
        return 0;
    }
    else res2 += r;

    res = min(res, res2);
    cout << res;
}