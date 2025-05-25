#include <iostream>
#include <vector>

using namespace std;

#define W true
#define B false

struct chess
{
    //bool color;
    int b;
    int w;
};


//(i, j)이 B이면 (i, j + 2k-1)는 W, (i, j + 2k)는 B이어야 한다.
//

int main()
{
  cin.tie(NULL);
  ios::sync_with_stdio(false);

  int n, m, k; cin >> n >> m >> k;
  vector<vector<chess>> board(n+1);
  for (vector<chess> &row : board)
    row.resize(m+1, {0, 0});

  //k x k 크기의 체스판을 구하는 경우에도 어찌됐건 NxM 크기의 전체 체스판이 체스판의
  //조건을 만족해야 한다.
  //- 첫 번째 칸이 B인 경우
  //- 첫 번째 칸이 W인 경우
  //두 가지 경우의 체스판을 완성할 때 갈아엎어야 하는 칸이면 각 칸마다 누적합으로 구하고
  //누적합으로 이루어진 두 체스판에서 가장 작은 값을 가진 구간을 구한다.
  for (int i = 1; i <= n; i++)
  {
    string s; cin >> s;
    for (int j = 1; j <= m; j++)
    {
      char c = s[j-1];
      if (c == 'B')
      {
        //B chess인 경우 i % 2 == 1 와 j % 2 == 1 이 B여야 한다.
        if ((i % 2 == 1 && j % 2 == 0) || (i % 2 == 0 && j % 2 == 1))
        {
          board[i][j].b = board[i][j-1].b + board[i-1][j].b - board[i-1][j-1].b + 1;
          board[i][j].w = board[i][j-1].w + board[i-1][j].w - board[i-1][j-1].w;
        }
        else
        {
          board[i][j].b = board[i][j-1].b + board[i-1][j].b - board[i-1][j-1].b;
          board[i][j].w = board[i][j-1].w + board[i-1][j].w - board[i-1][j-1].w + 1;
        }
      }
      else if (c == 'W')
      {
        if ((i % 2 == 1 && j % 2 == 0) || (i % 2 == 0 && j % 2 == 1))
        {
          board[i][j].b = board[i][j-1].b + board[i-1][j].b - board[i-1][j-1].b;
          board[i][j].w = board[i][j-1].w + board[i-1][j].w - board[i-1][j-1].w + 1;
        }
        else
        {
          board[i][j].b = board[i][j-1].b + board[i-1][j].b - board[i-1][j-1].b + 1;
          board[i][j].w = board[i][j-1].w + board[i-1][j].w - board[i-1][j-1].w;
        }
      }

      // printf("board[%d][%d] = %c\n", i, j, c);
      // for(int pi = 0; pi <= n; pi++)
      // {
      //     for (int pj = 0; pj <= m; pj++)
      //     {
      //         printf("(%d %d)", board[pi][pj].b, board[pi][pj].w);
      //     }
      //     printf("\n");
      // }
      // printf("\n");
    }
  }

  int lowest = k*k;
  for (int i = k; i <= n; i++)
  {
    for (int j = k; j <= m; j++)
    {
      int temp = min(board[i][j].b - board[i-k][j].b - board[i][j-k].b + board[i-k][j-k].b,
      board[i][j].w - board[i-k][j].w - board[i][j-k].w + board[i-k][j-k].w);
      if (temp < lowest) lowest = temp;
    }
  }

  cout << lowest;
}