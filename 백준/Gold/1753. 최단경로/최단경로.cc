#include <iostream>
#include <vector>
#include <queue>
#include <climits> // INT_MAX 사용

using namespace std;

vector<pair<int, int>> map[20001]; // (다음 노드, 가중치)

// 다익스트라 알고리즘 함수
void dijkstra(int start, int v)
{
    vector<int> distance(v + 1, INT_MAX); // 최단 거리 저장
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; // (거리, 노드 번호)

    // 시작 노드 초기화
    distance[start] = 0;
    pq.push({0, start});

    while (!pq.empty())
    {
        int curDist = pq.top().first;
        int curNode = pq.top().second;
        pq.pop();

        // 이미 처리된 노드인지 확인
        if (curDist > distance[curNode])
            continue;

        // 인접 노드 확인
        for (const auto& next : map[curNode])
        {
            int nextNode = next.first;
            int nextDist = curDist + next.second;

            // 더 짧은 경로 발견 시 업데이트
            if (nextDist < distance[nextNode])
            {
                distance[nextNode] = nextDist;
                pq.push({nextDist, nextNode});
            }
        }
    }

    // 결과 출력
    for (int i = 1; i <= v; i++)
    {
        if (distance[i] == INT_MAX)
            cout << "INF\n";
        else
            cout << distance[i] << '\n';
    }
}

int main()
{
    int v, e; 
    cin >> v >> e;

    int start; 
    cin >> start;

    // 간선 입력
    for (int i = 0; i < e; i++)
    {
        int u, vi, w;
        cin >> u >> vi >> w;

        // 단방향 그래프
        map[u].emplace_back(vi, w);
    }

    // 다익스트라 실행
    dijkstra(start, v);

    return 0;
}
