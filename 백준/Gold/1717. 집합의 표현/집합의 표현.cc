#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> ranks;

int Find(int x)
{
    if (x != parent[x])
        parent[x] = Find(parent[x]);

    return parent[x];
}

//0 1 2 3 4 5 6
//0 1 2 1 4 5 6
void Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if (x == y)
        return;

    if (ranks[x] > ranks[y])
    {
        parent[x] = y;
    }
    else if (ranks[x] < ranks[y])
    {
        parent[y] = x;
    }
    else
    {
        parent[y] = x;
        ranks[x]++;
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    parent.resize(n+1);
    for (int i = 0; i <= n; i++)
        parent[i] = i;
    
    ranks.resize(n+1, 1);

    for (int i = 0; i < m; i++)
    {
        int cal, a, b; cin >> cal >> a >> b;
        if (cal == 0)
        {
            Union(a, b);
        }
        else if (cal == 1)
        {
            if (Find(a) == Find(b))
                cout << "yes" << '\n';
            else
                cout << "no" << '\n';
        }
    }

    // 1 3 6 7
    // 2 4
}