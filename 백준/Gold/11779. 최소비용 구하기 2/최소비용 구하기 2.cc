#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <limits>

using namespace std;

int n, m;
const long long INF = numeric_limits<long long>::max();

void bfs(int st, int end, vector<vector<pair<int, int>>> &map, vector<long long> &visited, vector<int> &beforeCity)
{
    priority_queue<pair<long long, int>, vector<pair<long long, int>>, greater<pair<long long, int>>> pq;
    pq.push({0, st});
    visited[st] = 0;

    int cost = INT32_MAX;

    while (!pq.empty())
    {
        const pair<int, int> &curCity = pq.top();
        pq.pop();
        
        if (curCity.first > visited[curCity.second])
            continue;

        for (const pair<int, int> &next : map[curCity.second])
        {
            //다음에 갈 도시가 아직 방문하지 않았거나, 가는 비용이 더 적다면
            if (visited[next.first] == -1 || visited[curCity.second] + next.second < visited[next.first])
            {
                //비용 갱신 및 푸시
                visited[next.first] = visited[curCity.second] + next.second;
                pq.push({visited[next.first], next.first});

                //이전 도시 기록
                beforeCity[next.first] = curCity.second;
            }
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    cin >> n >> m;

    vector<vector<pair<int, int>>> map(n+1);
    vector<long long> visited(n+1, INF);
    vector<int> beforeCity(n+1, -1);
    for (int i = 0; i < m; i++)
    {
        int st, end, cost;
        cin >> st >> end >> cost;
        map[st].push_back({end, cost});
    }

    int st, end; cin >> st >> end;
    bfs(st, end, map, visited, beforeCity);

    vector<int> result;
    int next = end;
    while (next != st)
    {
        result.push_back(next);
        next = beforeCity[next];
    }

    result.push_back(st);

    reverse(result.begin(), result.end());

    cout << visited[end] << '\n';
    cout << result.size() << '\n';
    for (const int &city : result)
        cout << city << ' ';
}