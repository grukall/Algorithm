#include <iostream>
#include <vector>

using namespace std;

void backtracking(vector<vector<bool>> &video, int sx, int sy, int size)
{
  //printf("here");
  //영역의 시작은 괄호 열기
  bool f = video[sy][sx];

  if (size == 1) 
  {
    cout << f ? 1 : 0;
    return;
  }

  //f가 영역 내 모두 같다면 리턴
  bool bf = true;
  for (int i = sy; i < sy + size; i++)
  {
    for (int j = sx; j < sx + size; j++)
    {
      if (video[i][j] != f)
      {
        bf = false;
        break;
      }
    }

    if (!bf) break;
  }

  if (bf)
  {
    cout << f ? 1 : 0;
  }
  else
  {
     cout << '(';
    int nsize = size / 2;
    backtracking(video, sx, sy, nsize);
    backtracking(video, sx + nsize, sy, nsize);
    backtracking(video, sx, sy + nsize, nsize);
    backtracking(video, sx + nsize, sy + nsize, nsize);
     cout << ')';
  }
}

int main()
{
 //cin.tie(NULL);
 //ios::sync_with_stdio(false);
 int n; cin >> n;
 vector<vector<bool>> video(n);
 for (vector<bool> &row : video)
 {
  row.resize(n);
 }

 for (int i = 0; i < n; i++)
 {
  string s; cin >> s;
  for (int j = 0; j < n; j++)
  {
    char c = s[j];
    if (c == '0') video[i][j] = false;
    else if (c == '1') video[i][j] = true;
  }
 }

 backtracking(video, 0, 0, n);
}
