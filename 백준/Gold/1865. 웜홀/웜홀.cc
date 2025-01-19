#include <iostream>
#include <vector>
#include <queue>
#include <limits>


//벨만 포드 알고리즘(가중치가 음수인 간선이 포함된 그래프)
//효과 : 최단 거리, 음의 순환 존재 여부
//https://www.acmicpc.net/board/view/72995

using namespace std;

struct edge
{
    int startNode;
    int endNode;
    int time;

    edge(int s, int e, int t)
        : startNode(s), endNode(e), time(t) {}
};

vector<edge> edges;
vector<bool> res;

bool bellman_ford(int n, int start)
{

    //vector<long long int> dis(n+1, numeric_limits<long long>::max());

    //1. 시작노드는 0으로 초기화
    //dis[start] = 0;

    //0으로 설정 -> 시작점 설정이므로 모든 정점을 0으로 초기화하면 모든 정점을 동시에 탐색하는 효과를 가진다.
    //이 방법이면 모든 정점이 이어져 있지 않더라도 음의 순환을 탐지할 수 있다.
    //하지만 최단거리는 시작 정점이 1개가 아니므로 이 알고리즘에선 유효하지 않는다.
    vector<long long int> dis(n+1, 0);

    //2. O(NE) 만큼 순회하며 최단거리 구하기
    // n-1번만 검사해야 한다.
    for (int i = 1; i < n; i++)
    {
        for (const auto &curEdge : edges)
        {
            int startNode = curEdge.startNode;
            int endNode = curEdge.endNode;
            int time = curEdge.time;

            //정점을 무한대로 초기화했다면 값이 오버플로우 되는지 확인하는 조건이 추가되어야 한다.
            if (dis[endNode] > dis[startNode] + time)
            {
                dis[endNode] = dis[startNode] + time;
            }
        }
    }

    //3. 음의 사이클이 있는지 확인하기.
    // 음수 사이클 탐지에서 두 번째 검사가 중요한 이유
    // 음수 사이클 탐지는 최단 거리 계산과는 별개의 작업입니다. 음수 사이클을 탐지하지 않으면, 잘못된 최단 거리 값으로 알고리즘이 끝날 수 있습니다.
    // 예를 들어:
    // 그래프에 음수 사이클이 있으면, 첫 번째 반복만으로는 이를 탐지할 수 없습니다.
    // 두 번째 반복에서 음수 사이클을 확인해야 "해당 그래프에 음수 사이클이 있다"는 것을 정확히 알 수 있습니다.
    for (const auto &curEdge : edges)
    {
        int startNode = curEdge.startNode;
        int endNode = curEdge.endNode;
        int time = curEdge.time;

        if (dis[endNode] > dis[startNode] + time)
        {
            return true;
        }
    }

    return false;
}


int main()
{
    ios::sync_with_stdio(false);
    int TC; cin >> TC;

    for (int i = 0; i < TC; i++)
    {
        int n, m, w; cin >> n >> m >> w;
        for (int j = 0; j < m; j++)
        {
            int s, e, t; cin >> s >> e >> t;
            edges.push_back(edge(s, e, t));
            edges.push_back(edge(e, s, t));
        }

         for (int j = 0; j < w; j++)
        {
            int s, e, t; cin >> s >> e >> t;
            edges.push_back(edge(s, e, -t));
        }

        res.push_back(bellman_ford(n, 0));
        edges.clear();
    }

    for (bool result : res)
    {
        if (result == true) cout << "YES\n";
        else cout << "NO\n";
    }
}