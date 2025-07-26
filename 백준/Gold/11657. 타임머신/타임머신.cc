#include <iostream>
#include <vector>


using namespace std;

struct bus
{
    int start;
    int dest;
    int cost;
};


bool belmanford(int start, int v, int e, vector<bus> &buses, vector<long long> &distance)
{
    distance[0] = 0;

    /*
    벨만 포드 알고리즘
    최단 거리 알고리즘 중, 음의 가중치를 가진 거리를 계산에 포함할 수 있는 알고리즘이다.

    정점 st로부터 다른 모든 v-1개의 노드로의 최단 거리를 구하는데, 
    각 정점을 방문하며 모든 간선의 가중치를 반영한다.
    */

    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < e; j++)
        {
            int curNode = buses[j].start;
            int nextNode = buses[j].dest;
            int cost = buses[j].cost;

            if (distance[curNode] != __INT_MAX__ && distance[curNode] + cost < distance[nextNode])
            {
                distance[nextNode] = distance[curNode] + cost;
                //printf("distance[%d] = distance[%d] + %d\n", nextNode, curNode, cost);
                if (i == v-1)
                {
                    return false;
                }
            }
            //else printf("distance[%d] = INF or distance[%d] + %d > distance[%d]\n", curNode, curNode, cost, nextNode);
        }
    }

    return true;
}

int main()
{
    int n, m; cin >> n >> m;

    vector<long long> distance(n, __INT_MAX__);
    vector<bus> buses(m);

    for (int i = 0; i < m; i++)
    {
        int a, b, c; cin >> a >> b >> c;
        buses[i] = {a-1, b-1, c};
    }

    if (!belmanford(0, n, m, buses, distance))
    {
        cout << -1;
    }
    else
    {
        for (int city = 1; city < n; city++)
        {
            if (distance[city] == __INT_MAX__)
                cout << -1 << '\n';
            else
                cout << distance[city] << '\n';
        }
    }
}