#include <iostream>
#include <vector>

using namespace std;

int n;
vector<vector<int>> startlink;

int smallist = __INT_MAX__;
void backtracking(vector<bool> &selected, int size, int before)
{
    // printf("selected  = {");
    // for (int i = 0; i < selected.size(); i++)
    // {
    //     if (selected[i])
    //         printf("%d, ", i);
    // }
    // printf("}\n");
    if (size >= n/2)
    {
        vector<int> start;
        vector<int> link;
        for (int i = 0; i < n; i++)
        {
            if (selected[i])
                start.push_back(i);
            else
                link.push_back(i);
        }
        int res_start = 0, res_link = 0;
        for (int i = 0; i < start.size(); i++)
        {
            for (int j = i + 1; j < start.size(); j++)
            {
                int first = start[i];
                int second = start[j];
                res_start += startlink[first][second] + startlink[second][first];
            }
        }
        for (int i = 0; i < link.size(); i++)
        {
            for (int j = i + 1; j < link.size(); j++)
            {
                int first = link[i];
                int second = link[j];
                res_link += startlink[first][second] + startlink[second][first];
            }
        }

        if (abs(res_start - res_link) < smallist)
            smallist = abs(res_start - res_link);
        return;

    }

    for (int i = before+1; i < n; i++)
    {
        if (!selected[i])
        {
            selected[i] = true;
            backtracking(selected, size+1, i);
            selected[i] = false;
        }
    }
}
int main()
{
    cin >> n;
    startlink.resize(n);
    for (vector<int> &row : startlink)
        row.resize(n);
    
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> startlink[i][j];
        }
    }
    
    vector<bool> selected(n, false);
    backtracking(selected, 0, 0);

    cout << smallist;
    //1. nCn/2 조합을 모두 찾는다.
    //2. startlink 값의 따로 패턴은 존재하지 않는다 -> startlink의 모든 조합을 다 찾아봐야 한다.
    //3. 모든 조합을 효과적으로 추출하는 방법이 필요하다.

    // for (int i = 0; i < n; i++)
    // {
    //     for (int j = 0; j < n; j++)
    //     {
    //         cout << startlink[i][j] << ' ';
    //     }
    //     cout << '\n';
    // }
}
