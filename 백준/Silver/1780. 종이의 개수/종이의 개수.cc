#include <iostream>
#include <vector>

using namespace std;

int n;
int pagew = 0;
int pageb = 0;
int pagem = 0;
void backtracking(vector<vector<int>> &pp, int sx, int sy, int size)
{
  //자를 크기
  //첫 번째 비트 값
  int bzero = pp[sy][sx];
  bool bPage = true;

  if (size == 1)
  {
    if (bzero == 0) pagew++;
    else if (bzero == 1) pageb++;
    else pagem++;
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
    else if (bzero == 1) pageb++;
    else pagem++;
    return;
  }

  int newsize = size / 3;
  backtracking(pp, sx, sy, newsize);
  backtracking(pp, sx + newsize, sy, newsize);
  backtracking(pp, sx + newsize * 2, sy, newsize);
  backtracking(pp, sx, sy + newsize, newsize);
  backtracking(pp, sx + newsize, sy + newsize, newsize);
  backtracking(pp, sx + newsize * 2, sy + newsize, newsize);
  backtracking(pp, sx, sy + newsize * 2, newsize);
  backtracking(pp, sx + newsize, sy + newsize * 2, newsize);
  backtracking(pp, sx + newsize * 2, sy + newsize * 2, newsize);

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
  cout << pagem << '\n' << pagew << '\n' << pageb;
}