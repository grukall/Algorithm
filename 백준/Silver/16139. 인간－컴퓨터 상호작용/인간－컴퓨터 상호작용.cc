#include <iostream>
#include <vector>
#include <algorithm>
#include <tuple>

using namespace std;

int main()
{
  cin.tie(NULL);
  ios::sync_with_stdio(false);
  string s; cin >> s;
  vector<vector<int>> cnt(s.size());
  for (vector<int> &row : cnt)
  {
    row.resize(26, 0);
  }

  int alphabet = s[0] - 97;
  cnt[0][alphabet]++;
  for (int i = 1; i < s.size(); i++)
  {
    for (int j = 0; j < 26; j++)
    {
      cnt[i][j] = cnt[i-1][j];
    }

    int alphabet = s[i] - 97;
    cnt[i][alphabet]++;
    //printf("alphabet : %c, index = %d, count = %d\n", s[i], alphabet, cnt[i][alphabet]);
  }


  int n; cin >> n;
  for (int i = 0; i < n; i++)
  {
    char c;
    int begin, end;
    cin >> c >> begin >> end;
    int alphabet = c - 97;
    if (begin == 0)
    {
      cout << cnt[end][alphabet] << '\n';
    }
    else
    {
      cout << cnt[end][alphabet] - cnt[begin-1][alphabet] << '\n';
    }
  }
  
}