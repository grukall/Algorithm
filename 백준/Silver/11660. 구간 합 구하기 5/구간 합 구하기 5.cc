#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <sstream>

using namespace std;
vector<pair<long long int, long long int>> caseN[2];


int num[1025][1025] = {};

void calpannel(pair<int, int> one, pair<int, int> two)
{
    // for (int s = one.second; s <= two.second; s++)
    // {
    //     for (int f = one.first; f <= two.first; f++)
    //     {
    //         //printf("(%d, %d) = %d\n", f, s, num[f][s]);
    //         res += num[f][s];
    //     }
    // }

    cout << num[two.first][two.second] - num[two.first][one.second-1] - num[one.first-1][two.second] + num[one.first-1][one.second-1] << '\n';

   //cout << res << '\n';
}


int main()
{
    //ios::sync_with_stdio(false);
    int n, m; cin >> n >> m;

    string s;
    stringstream ss;

    cin.ignore(1);

    for (int i = 1; i <= n; i++)
    {
        ss.clear();
        getline(cin, s);
        ss.str(s);
        for (int j = 1; j <= n; j++)
        {
            int number;
            ss >> number;
            num[i][j] = number;   
        }
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            num[i][j] = num[i-1][j] + num[i][j-1] - num[i-1][j-1] + num[i][j];
        }
    }

    for (int i = 0; i < m; i++)
    {
        ss.clear();
        getline(cin, s);
        ss.str(s);

        int number1, number2;
        ss >> number1; ss >> number2;
        caseN[0].push_back(make_pair(number1, number2));
        ss >> number1; ss >> number2;
        caseN[1].push_back(make_pair(number1, number2));

        //cout << "case : " <<caseN[0][i].first << caseN[0][i].second << caseN[1][i].first << caseN[1][i].second << '\n';
        //printf("case %d : (%d, %d), (%d , %d)\n", caseN[0][i].first, caseN[0][i].second, caseN[1][i].first, caseN[1][i].second); 
    }

    for (int i = 0; i < m; i++)
    {
        calpannel(caseN[0][i], caseN[1][i]);
    }
}