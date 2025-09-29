#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

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

void Kruscal(vector<tuple<int, int, int>> &v, vector<int> &parent, vector<int> &level)
{
    sort(v.begin(), v.end());

    int cost = 0;
    for (const tuple<int, int, int> &t : v)
    {
        if (Find(parent, get<1>(t)) != Find(parent, get<2>(t)))
        {
            cost += get<0>(t);
            Union(parent, level, get<1>(t), get<2>(t));
        }
    }

    cout << cost << '\n';
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int V, E; cin >> V >> E;
    vector<tuple<int, int, int>> v;
    vector<int> parent(V+1);
    for (int number = 1; number <= V; number++) parent[number] = number;
    vector<int> level(V+1, 0);

    for (int j = 0; j < E; j++)
    {
        int a, b, c; cin >> a >> b >> c;
        v.push_back({c, a, b});
    }

    Kruscal(v, parent, level);
}