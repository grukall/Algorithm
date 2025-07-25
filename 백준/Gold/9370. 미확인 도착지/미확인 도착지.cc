#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;
int g, h;
int n;

void dijkstra(int start, vector<vector<pair<int, int>>> &map, vector<int> &res)
{
    res.clear();
    res.resize(n, __INT_MAX__);

    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    pq.push({start, 0});
    res[start] = 0;

    while (!pq.empty())
    {
        pair<int, int> cur = pq.top();
        pq.pop();

        //이미 방문한 노드는 건너뜀
        if (cur.second > res[cur.first])
        {
            continue;
        }

        for (const auto &[next, dist] : map[cur.first])
        {
            int next_cost = cur.second + dist;
            if (next_cost < res[next])
            {
                res[next] = next_cost;
                pq.push({next, next_cost});
            }
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int T; cin >> T;
    
    for (int tc = 0; tc < T; tc++)
    {
        //후보들 중, g와h 사이의 길을 지나가야 갈 수 있는 후보지들을 추려 오름차 순으로 출력
        //-> 다익스트라 알고리즘(s출발, 모든곳 검사). 불가능한 곳 제외하고 오름차순 정렬 후 출력

        //교차로, 도로, 목적지 후보의 갯수
        int m, t; cin >> n >> m >> t;

        //s = 예술가들의 출발지, g와h 교차로 사이에 있는 도로를 지나감
        int s; cin >> s >> g >> h;

        vector<vector<pair<int, int>>> map(n+1);
        int gh_dist;
        for (int i = 0; i < m; i++)
        {
            //a와 b사이에 d의 양방향 도로
            int a, b, d; cin >> a >> b >> d;
            map[a].push_back({b, d});
            map[b].push_back({a, d});

            if ((a == g && b == h) || (a == h && b == g))
            {
                gh_dist = d;
            }
        }

        vector<int> candidates(t);
        for (int i = 0; i < t; i++)
        {
            int x; cin >> x;
            candidates[i] = x;
        }
        sort(candidates.begin(), candidates.end());

        // printf("candidates = {");
        // for (int candidate : candidates)
        // {
        //     printf("%d ", candidate);
        // }
        // printf("}, gh_dist = %d\n", gh_dist);

        vector<int> res(n+1, __INT_MAX__);
        dijkstra(s, map, res);

        //s --> g --> h --> candidates
        vector<int> res_gh(n+1, __INT_MAX__);
        dijkstra(h, map, res_gh);

        //s --> h --> g --> candidates
        vector<int> res_hg(n+1, __INT_MAX__);
        dijkstra(g, map, res_hg);

        //printf("res = ");
        for (int candidate : candidates)
        {
            int dist_gh, dist_hg;
            if (res[g] == __INT_MAX__ || res_gh[candidate] == __INT_MAX__)
            {
                dist_gh = __INT_MAX__;
            }
            // else if (g == candidate)
            // {
            //     cout << candidate << ' ';
            //     continue;
            // }
            else
            {
                dist_gh = res[g] + gh_dist + res_gh[candidate];
            }

            if (res[h] == __INT_MAX__ || res_hg[candidate] == __INT_MAX__)
            {
                dist_hg = __INT_MAX__;
            }
            // else if (h == candidate)
            // {
            //     cout << candidate << ' ';
            //     continue;
            // }
            else
            {
                dist_hg = res[h] + gh_dist + res_hg[candidate];
            }

            //gh를 거치는 최소 거리가 기본 최소거리와 일치할 때, 듀오가 hg길을 거치고 갈 수 있는 후보지들이다.
            if (res[candidate] != __INT_MAX__ && res[candidate] == min(dist_gh, dist_hg))
            {
                cout << candidate << ' ';
            }
           // else printf("No %d, %d != %d\n", candidate, res[candidate], min(dist_gh, dist_hg));
        }

        cout << '\n';
    }
}