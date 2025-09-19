#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct inf
{
    long long cost;
    vector<int> cities;
};


void fluidWarshall(vector<vector<inf>> &graph, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int a = 0; a < n; a++)
        {
            for (int b = 0; b < n; b++)
            {
                 if (graph[a][i].cost + graph[i][b].cost < graph[a][b].cost)
                 {
                    graph[a][b].cost = graph[a][i].cost + graph[i][b].cost;
                    vector<int> v(graph[a][i].cities);
                    v.pop_back();
                    v.insert(v.end(), graph[i][b].cities.begin(), graph[i][b].cities.end());
                    graph[a][b].cities = v;
                 }
            }
        }
    }
}


int main()
{
    int n, m; cin >> n >> m;
    vector<vector<inf>> graph(n, vector<inf>(n, {__INT_MAX__, vector<int>(0)}));
    for (int i = 0; i < m; i++)
    {
        int a, b; long long c; cin >> a >> b >> c;
        graph[a-1][b-1].cost = min(graph[a-1][b-1].cost, c);
        graph[a-1][b-1].cities.resize(2);
        graph[a-1][b-1].cities[0] = a;
        graph[a-1][b-1].cities[1] = b;
    }

    fluidWarshall(graph, n);

    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < n; b++)
        {
            if (graph[a][b].cost == __INT_MAX__ || a == b)
                cout << "0 ";
            else
                cout << graph[a][b].cost << ' ';
        }
        cout << '\n';
    }

    for (int a = 0; a < n; a++)
    {
        for (int b = 0; b < n; b++)
        {
            if (graph[a][b].cities.size() == 0 || a == b)
                cout << '0';
            else
            {
                cout << graph[a][b].cities.size() << ' ';
                for (const int &city : graph[a][b].cities)
                {
                    cout << city << ' ';
                }
            }
            cout << '\n';
        }
    }
}