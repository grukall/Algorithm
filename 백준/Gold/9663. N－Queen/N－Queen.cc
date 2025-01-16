#include <iostream>
#include <vector>


using namespace std;

int n;
int count = 0; 

void dfs(vector<int> &chess, int row)
{
    vector<int> valid(n, 1);
    //1. row번째 열에 놓을 수 있는 칸을 선별한다.
    for (int i = 0; i < row; i++)
    {
        // 이전 열에 놓인 퀸의 위치
        int queen = chess[i];

        //현재 row간의 거리 만큼 퀸이 공격할 수 있는 위치를 놓을 수 없는 위치로 설정한다.
        int far = row - i;

        valid[queen] = 0;
        if (queen + far < n)
            valid[queen + far] = 0;
        if (queen - far >= 0)
            valid[queen - far] = 0;
    }

    //2. 놓을 수 있는 칸 중 하나를 선택해 dfs 탐색한다.
    for (int i = 0; i < n; i++)
    {
        if (valid[i])
        {
            chess[row] = i;

            if (row+1 == n)
            {
                count++;
                // printf("count = %d, [", count);
                // for (int queen : chess)
                // {
                //     printf(" %d", queen);
                // }
                // printf("]\n");
            }
            else
                dfs(chess, row+1);

            chess[row] = -1;
        }
    }
}



int main()
{
    cin >> n;

    vector<int> chess(n, -1);

    dfs(chess, 0);
    cout << count;
}