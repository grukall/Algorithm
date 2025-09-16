#include <iostream>
#include <vector>
#include <string.h>

using namespace std;

int dp[1001][1001];
int N, W; 
vector<pair<int, int>> incidents;

int distance(const pair<int, int> &p1, const pair<int, int> &p2)
{
   return abs(p1.first - p2.first) + abs(p1.second - p2.second);
}


//경찰차가 각각 p1_idx, p2_idx 사건을 해결한 경우
int solve(int p1_idx, int p2_idx)
{
    //두 경찰차 중 마지막 사건을 해결했으면 0을 리턴
    if (p1_idx == W || p2_idx == W)
        return 0;
    
    //이전에 계산한 값이면 리턴
    if (dp[p1_idx][p2_idx] != -1) return dp[p1_idx][p2_idx];

    //해결해야할 다음 사건 순서와 위치
    const int next_idx = max(p1_idx, p2_idx) + 1;
    const pair<int, int> incident = incidents[next_idx];

    //현재 경찰차들의 위치(마지막으로 사건을 해결한 번호로 유추)
    const pair<int, int> p1_loc = (p1_idx == 0) ? make_pair(1, 1) : incidents[p1_idx];
    const pair<int, int> p2_loc = (p2_idx == 0) ? make_pair(N, N) : incidents[p2_idx];

    //첫 번째 경찰차가 사건 위치로 출동할 경우 이동하는 거리
    int dist1 = distance(p1_loc, incident);

    //첫 번째 경찰차가 이 사건을 해결했을 때 비용(이동 거리 + 다음 index에서 사건을 해결했을 때 총 비용)
    int res1 = dist1 + solve(next_idx, p2_idx);

    int dist2 = distance(p2_loc, incident);
    int res2 = dist2 + solve(p1_idx, next_idx);

    //더 적은 값으로 리턴
    return dp[p1_idx][p2_idx] = min(res1, res2);

}


int main()
{
    cin >> N >> W;
    incidents.resize(W+1);
    for (int i = 1; i <= W; i++)
    {
        cin >> incidents[i].first >> incidents[i].second;
    }

    memset(dp, -1, sizeof(dp));
    cout << solve(0, 0) << '\n';

    int p1_idx = 0;
    int p2_idx = 0;

    for (int i = 1; i <= W; i++)
    {
        pair<int, int> next_loc = incidents[i];
        pair<int, int> p1_loc = p1_idx == 0 ? make_pair(1, 1) : incidents[p1_idx];
        pair<int, int> p2_loc = p2_idx == 0 ? make_pair(N, N) : incidents[p2_idx];

        int dist1 = distance(p1_loc, next_loc);
        int res1 = dist1 + dp[i][p2_idx];

        int dist2 = distance(p2_loc, next_loc);
        int res2 = dist2 + dp[p1_idx][i];

        if (res1 < res2)
        {
            cout << 1 << '\n';
            p1_idx = i;
        }
        else
        {
            cout << 2 << '\n';
            p2_idx = i;
        }
    }
}