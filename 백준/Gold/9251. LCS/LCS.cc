#include <iostream>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

int map[1001][1001] = {0, };

int main()
{
    string s1, s2;
   
    getline(cin, s1);
    getline(cin, s2);

    for (int i = 1; i <= s1.length(); i++)
    {
        for (int j = 1; j <= s2.length(); j++)
        {
            map[i][j] = max(map[i][j-1], map[i-1][j]);

            if (s1[i-1] == s2[j-1])
            {
                map[i][j] = map[i-1][j-1] + 1;
            }
        }
    }

    cout << map[s1.length()][s2.length()];
}