#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>


using namespace std;

vector<pair<int,int>> tree[10001];
vector<int> w(10001, 0);

int backtracking(pair<int, int> &curnode)
{
    int index = curnode.first;
    int curw = curnode.second;
    int cnodeCount = tree[index].size();

    // 리프 노드이면 가중치를 리턴
    if (cnodeCount <= 0)
    {
        w[index] = 0;
        //printf("leafnode[%d] = 0, return %d\n", index, curw);
        return curw;
    }

    //자식 노드가 하나라면,
    //자식 노드의 가중치를 받아 자신의 가중치를 더한 후 리턴.
    if (cnodeCount == 1)
    {
        w[index] = backtracking(tree[index].front());
        //printf("onechildnode[%d] = %d, return %d\n", index, w[index], w[index]);
        return w[index] + curw;
    }

    // 자식 노드가 둘 이상이라면,
    // 자식 중 가중치가 가장 높은 두 개의 노드를 골라 합산 후 저장한다,
    // biggest만 리턴
    priority_queue<int> cws;
    for (pair<int, int> cnode : tree[index])
        cws.push(backtracking(cnode));

    int biggest = cws.top(); cws.pop();
    int second = cws.top();

    w[index] =  biggest + second;
    //printf("twochildnode[%d] = %d, return %d\n", index, w[index], biggest);
    return biggest + curw;

}

int main()
{

    int n; cin >> n;


    //지름을 구성할 두 노드는 무조건 리프 노드이다.
    //따라서 각 리프노드에서 부모로 올라가는 백트래킹을 이용해,
    //부분트리에서 최대 가중치를 부모노드에 저장한다.
    //부분 트리의 부모 노드가 추가될 때, 부모 노드를 거치는 트리에서 가장 큰 가중치를 저장한다.

    //리프노드를 제외한 노드를 순회하며 가장 큰 가중치를 출력한다.

    for (int i = 0; i < n-1; i++)
    {
        int pnode, cnode, w; cin >> pnode >> cnode >> w;
        tree[pnode].push_back(make_pair(cnode, w));
    }

    pair<int, int> first = make_pair(1, 0);
    backtracking(first);

    int res = 0;
    for (int i = 1; i <= n; i++)
        res = max(res, w[i]);

    cout << res;
    
}