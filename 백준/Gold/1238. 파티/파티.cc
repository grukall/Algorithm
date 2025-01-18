#include <iostream>
#include <vector>
#include <queue>

using namespace std; 

vector<pair<int, int>> map[1001]; //(소요 시간, 도착 마을)
int n;

void bfs_goHome(int x, vector<int> &minTime)
{
    //소요시간이 가장 작은 순서대로 정렬
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;

    pq.push(make_pair(0, x));
    while(!pq.empty())
    {
        pair<int, int> vilInf = pq.top();
        pq.pop();
        int curTime = vilInf.first;
        int curVil = vilInf.second;

        if (curTime > minTime[curVil])
            continue;
        
        for (pair<int, int> nextVilInf : map[curVil])
        {
            int nextTime = nextVilInf.first;
            int nextVil = nextVilInf.second;

            if (nextVil == x) continue;
            
            if (curTime + nextTime < minTime[nextVil])
            {
                minTime[nextVil] = curTime + nextTime;
                pq.push(make_pair(curTime + nextTime, nextVil));
            }
        }
    }
}

int bfs_goParty(int st, int x)
{
    //소요시간이 가장 작은 순서대로 정렬
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq;
    vector<int> minTime(n+1, __INT_MAX__);

    pq.push(make_pair(0, st));
    while(!pq.empty())
    {
        pair<int, int> vilInf = pq.top();
        pq.pop();
        int curTime = vilInf.first;
        int curVil = vilInf.second;

        if (curTime > minTime[curVil])
            continue;
        
        for (pair<int, int> nextVilInf : map[curVil])
        {
            int nextTime = nextVilInf.first;
            int nextVil = nextVilInf.second;

            if (curTime + nextTime < minTime[nextVil])
            {
                minTime[nextVil] = curTime + nextTime;
                pq.push(make_pair(curTime + nextTime, nextVil));
            }
        }
    }

    return minTime[x];
}


int main()
{
    int m, x; cin >> n >> m >> x;

    for (int i = 0; i < m; i++)
    {
        int st, end, t; cin >> st >> end >> t;
        map[st].push_back(make_pair(t, end));
    }

    // 1. 각 마을에서 x까지의 최단 소요시간
    // 2. x에서 출발하여 각 마을까지의 최단 소요 시간

    //1번 계산
    vector<int> goParty(n+1, __INT_MAX__);
    for (int i = 1; i <= n; i++)
    {
        //각 마을에서 파티로 가는 최단 시간
        goParty[i] = bfs_goParty(i, x);
    }

     //2번 계산
    vector<int> goHome(n+1, __INT_MAX__);
    bfs_goHome(x, goHome);

    //학생들중 가장 소요시간이 많은 학생의 소요시간을 구한다.
    int maxTime = 0;
    for (int i = 1; i <= n; i++)
        maxTime = max(maxTime, goParty[i] + goHome[i]);
    
    cout << maxTime;
}