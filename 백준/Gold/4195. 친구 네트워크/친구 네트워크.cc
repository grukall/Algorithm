#include <iostream>
#include <unordered_map>

using namespace std;

struct val
{
    string parent;
    int ranks;
};


unordered_map<string, val> map;

string Find(string x)
{
    if (x != map[x].parent)
        map[x].parent = Find(map[x].parent);

    return map[x].parent;
}

void Union(string x, string y)
{
    x = Find(x);
    y = Find(y);

    if (x == y)
        return;

    if (map[x].ranks > map[y].ranks)
    {
        map[y].parent = x;
        map[x].ranks += map[y].ranks;
    }
    else if (map[x].ranks < map[y].ranks)
    {
        map[x].parent = y;
        map[y].ranks += map[x].ranks;
    }
    else
    {
        map[y].parent = x;
        map[x].ranks += map[y].ranks;
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    //n = 도시의 수, m = 여행 계획의 속한 도시들의 수
    int T; cin >> T;

    for (int tk = 0; tk < T; tk++)
    {
        map.clear();
        int f; cin >> f;
        for (int i = 0; i < f; i++)
        {
            string a, b; cin >> a >> b;
            if (map.find(a) == map.end())
                map[a] = {a, 1};
            if (map.find(b) == map.end())
                map[b] = {b, 1};

            Union(a, b);

            // for (auto it : map)
            // {
            //    cout << it.first << '(' << it.second.parent << ' ' << it.second.ranks << ")\n";
            // }
            // printf("\n");

            string parent = Find(a);
            cout << map[parent].ranks << '\n';
        }
    }
}