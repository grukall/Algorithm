#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int Find(vector<int> &parent, int a)
{
    if (parent[a] != a)
    {
        parent[a] = Find(parent, parent[a]);
    }

    return parent[a];
}

void Union(vector<int> &parent, vector<int> &level, int a, int b)
{
    a = Find(parent, a);
    b = Find(parent, b);

    if (a == b)
        return;
    
    if (level[a] < level[b])
    {
        parent[a] = b;
    }
    else if (level[a] > level[b])
    {
        parent[b] = a;
    }
    else
    {
        parent[b] = a;
        level[a] += 1;
    }
}

void Kruscal(vector<pair<int, int>> &v, vector<int> &parent, vector<int> &level)
{
    //sort는 아직 필요없다

    int cost = 0;
    for (const pair<int, int> &p : v)
    {
        if (Find(parent, p.first) != Find(parent, p.second))
        {
            cost += 1;
            Union(parent, level, p.first, p.second);
        }
    }

    cout << cost << '\n';
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T; cin >> T;
    for (int i = 0; i < T; i++)
    {
        int n, m; cin >> n >> m;
        vector<pair<int, int>> v;
        vector<int> parent(m+1);
        for (int number = 1; number <= m; number++) parent[number] = number;
        vector<int> level(m+1, 0);

        for (int j = 0; j < m; j++)
        {
            int a, b; cin >> a >> b;
            v.push_back({a, b});
        }

        Kruscal(v, parent, level);
    }
}