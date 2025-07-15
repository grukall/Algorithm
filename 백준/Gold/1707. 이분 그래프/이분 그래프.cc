#include <iostream>
#include <vector>
#include <queue>
#include <map>

using namespace std;

bool bfs(int start, vector<vector<int>> &g, vector<bool> &visited)
{
  queue<int> q;
  q.push(start);
  visited[start] = true;

  //노드 방문 깊이, 깊이가 홀수인 그룹과 짝수인 그룹으로 나뉜다.
  vector<int> depth(visited.size(), -1);
  depth[start] = 1;

  while (!q.empty())
  {
    int cur = q.front();
    q.pop();
    //printf("cur = %d, depth = %d\n", cur, depth[cur]);

    visited[cur] = true;

    for (auto nextNode : g[cur])
    {
      //방문하는 곳은 현재 노드와 다른 집합이어야 한다.
      if ((depth[nextNode] == depth[cur]))
      { 
        //printf("depth[%d] = %d, cur depth[%d] = %d\n", nextNode, depth[nextNode] % 2, cur, depth[cur] % 2);
        return false;
      }

      if (!visited[nextNode])
      {
        depth[nextNode] = depth[cur] ^ 1;
        //printf("depth[%d] = %d\n", nextNode, depth[nextNode]);
        q.push(nextNode);
      }
    }
  }

  //모든 너비 탐색을 통과하면 이분 가능한 그래프이다.
  return true;
}

int main()
{
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int K; cin >> K;
  for (int i = 0; i < K; i++)
  {
    int v, e; cin >> v >> e;
    vector<vector<int>> g(v+1);
    vector<bool> visited(v+1);

    for (int j = 0; j < e; j++)
    {
      int a, b; cin >> a >> b;
      g[a].push_back(b);
      g[b].push_back(a);
    }

    bool bRes = true;
    for (int st = 1; st <= v; st++)
    {
      if (!visited[st] && !bfs(st, g, visited))
        {
          bRes = false;
          cout << "NO" << '\n';
          break;
        }
    }

    if (bRes == true)
      cout << "YES" << '\n';
  }
}