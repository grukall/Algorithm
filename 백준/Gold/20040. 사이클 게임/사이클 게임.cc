#include <iostream>
#include <vector>

using namespace std;

vector<int> parents;
vector<int> ranks;

int Find(int x)
{
    if (x != parents[x])
        parents[x] = Find(parents[x]);

    return parents[x];
}

bool Union(int x, int y)
{
    x = Find(x);
    y = Find(y);

    if (x == y)
    {
        return true;
    }

    if (ranks[x] < ranks[y])
    {
        parents[x] = y;
    }
    else if (ranks[x] > ranks[y])
    {
        parents[y] = x;
    }
    else
    {
        parents[y] = x;
        ranks[x]++;
    }

    return false;
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n, m; cin >> n >> m;
    parents.resize(n);
    for (int i = 0; i < n; i++)
        parents[i] = i;
    
    ranks.resize(n, 1);

    for (int i = 0; i < m; i++)
    {
        int a, b; cin >> a >> b;
        if (Union(a, b))
        {
            cout << i+1;
            return 0;
        }
    }

    cout << 0;
}