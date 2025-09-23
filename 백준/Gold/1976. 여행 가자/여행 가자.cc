#include <iostream>
#include <vector>

using namespace std;

vector<int> parent;
vector<int> ranks;

int Find(int x)
{
    //printf("Find %d\n", x);
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
        parent[y] = x;
    }
    else if (ranks[x] < ranks[y])
    {
        parent[x] = y;
    }
    else
    {
        parent[y] = x;
        ranks[x]++;
    }
}

int main()
{
    // cin.tie(NULL);
    // ios::sync_with_stdio(false);

    //n = 도시의 수, m = 여행 계획의 속한 도시들의 수
    int n, m; cin >> n >> m;
    parent.resize(n);
    ranks.resize(n, 1);
    for (int i = 0; i < n; i++)
    {
        parent[i] = i;
    }


    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
           int road; cin >> road;
           if (road == 1)
           {
                Union(i, j);
                // printf("parent = ");
                // for (const int parents : parent)
                // {
                //     printf("%d ", parents);
                // }
                // printf("\n");
           }
        }
    }

    int nextCity;
    int TripPparent;
    for (int i = 0; i < m; i++)
    {
        cin >> nextCity; nextCity -= 1;
        //printf("city = %d, parent[%d] = %d\n", nextCity, nextCity, parent[nextCity]);
        if (i == 0)
            TripPparent = parent[nextCity];
        else
        {
            if (parent[nextCity] != TripPparent)
            {
                cout << "NO";
                return 0;
            }
        }
    }

    cout << "YES";


}