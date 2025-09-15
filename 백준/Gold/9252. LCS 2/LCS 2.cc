#include <iostream>
#include <vector>
#include <sstream>

using namespace std;

int map[1001][1001] = {0, };

int main()
{
    string s1, s2;
   
    getline(cin, s1);
    getline(cin, s2);
    if (s2.length() > s1.length())
    {
        string temp;
        temp = s2;
        s2 = s1;
        s1 = temp;
    }

    vector<vector<pair<int, int>>> dp(s1.length()+1);

    for (int i = 1; i <= s1.length(); i++)
    {
        for (int j = 1; j <= s2.length(); j++)
        {
            map[i][j] = max(map[i][j-1], map[i-1][j]);

            if (s1[i-1] == s2[j-1])
            {
                map[i][j] = map[i-1][j-1] + 1;
                dp[i].push_back({map[i][j], j});
            }
        }
    }

    int index = map[s1.length()][s2.length()];
    cout << index << '\n';

    int s1Index = s2.length()+1;
    vector<char> stack;
    for (int i = dp.size()-1; i >= 1; --i)
    {
       // printf("dp[%d] = ", i);
        for (const pair<int, int> &p : dp[i])
        {
            if (p.first == index && p.second < s1Index)
            {
                stack.push_back(s1[i-1]);
                index--;
                s1Index = p.second;
            }

           // printf("{%d, %d} ", p.first, p.second);
        }
        //printf("\n");
    }

    for (int i = stack.size()-1; i >= 0; --i)
        cout << stack[i];

}