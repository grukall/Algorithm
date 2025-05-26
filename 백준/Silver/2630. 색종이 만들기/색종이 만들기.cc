#include <iostream>
#include <vector>

using namespace std;

int n;
int pagew = 0;
int pageb = 0;
void backtracking(vector<vector<int>> &pp, int sx, int sy, int size)
{
  //자를 크기
  //첫 번째 비트 값
  bool bzero = pp[sy][sx];
  bool bPage = true;

  if (size == 1)
  {
    if (bzero == 0) pagew++;
    else pageb++;
    return;
  }

  for (int i = sy; i < sy + size; i++)
  {
    for (int j = sx; j < sx + size; j++)
    {
      if (bzero != pp[i][j])
      {
        bPage = false;
        break;
      }
    }
    if (!bPage) break;
  }

  if (bPage)
  {
    if (bzero == 0) pagew++;
    else pageb++;
    return;
  }

  int newsize = size / 2;
  backtracking(pp, sx, sy, newsize);
  backtracking(pp, sx + newsize, sy, newsize);
  backtracking(pp, sx, sy + newsize, newsize);
  backtracking(pp, sx + newsize, sy + newsize, newsize);

}

int main()
{
  cin >> n;
  vector<vector<int>> pp(n);
  
  for (vector<int> &row : pp)
    row.resize(n);
  for (int i = 0 ; i < n; i++)
  {
    for (int j = 0; j < n; j++)
    {
      cin >> pp[i][j];
    }
  }

  backtracking(pp, 0, 0, n);
  cout << pagew << '\n' << pageb;
}