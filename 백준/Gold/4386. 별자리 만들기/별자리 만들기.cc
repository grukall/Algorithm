#include <iostream>
#include <vector>
#include <map>
#include <algorithm>
#include <unordered_map>
#include <cmath>
#include <iomanip>

using namespace std;

#define star pair<double, double>
#define starInf tuple<double, star, star>

map<star, star> parent;
map<star, int> level;

star Find(const star &a)
{
    if (parent[a] != a)
    {
        parent[a] = Find(parent[a]);
    }

    return parent[a];
}



void Union(star a, star b)
{
    a = Find(a);
    b = Find(b);

    if (parent[a] == parent[b])
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
        parent[a] = b;
        level[b] += 1;
    }
}


void Kruscal(vector<starInf> &graph)
{
    sort(graph.begin(), graph.end());

    double cost = 0.f;
    for (const starInf &s : graph)
    {
        double distance = get<0>(s);
        star s1 = get<1>(s);
        star s2 = get<2>(s);

        if (Find(s1) != Find(s2))
        {
            cost += distance;
            Union(s1, s2);
        }
    }

    cout << fixed << setprecision(2) << cost;

}

double dist(const star &a, const star &b)
{
    return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main()
{
    cin.tie(NULL);
    ios_base::sync_with_stdio(false);
    
    int n; cin >> n;
    vector<star> stars;
    vector<starInf> graph;
    for (int i = 0; i < n; i++)
    {
        star s; cin >> s.first >> s.second;
        for (int j = 0; j < i; j++)
        {
            double distance = dist(stars[j], s);
            graph.push_back({distance, stars[j], s});
        }

        stars.push_back(s);
        parent[s] = s;
        level[s] = 0;
    }

    Kruscal(graph);
}