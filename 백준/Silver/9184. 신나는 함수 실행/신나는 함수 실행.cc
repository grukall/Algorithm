#include <iostream>
#include <vector>

using namespace std;

int main()
{
    //cin.tie(NULL);
    ios::sync_with_stdio(false);

    int w[21][21][21];

    for (int a1 = 0; a1 <= 20; a1++)
    {
        for (int b1 = 0; b1 <= 20; b1++)
        {
            for (int c1 = 0; c1 <= 20; c1++)
            {
                //printf("{%d, %d, %d} = ", a1, b1, c1);
                if (a1 <= 0 || b1 <= 0 || c1 <= 0)
                {
                    w[a1][b1][c1] = 1;
                }
                else if (a1 < b1 && b1 < c1)
                {
                    w[a1][b1][c1] = w[a1][b1][c1-1] + w[a1][b1-1][c1-1] - w[a1][b1-1][c1];
                }
                else
                {
                    w[a1][b1][c1] = w[a1-1][b1][c1] + w[a1-1][b1-1][c1] + w[a1-1][b1][c1-1] - w[a1-1][b1-1][c1-1];
                }
                //printf("%d\n", w[a1][b1][c1]);
            }
        }
    }

    while(true)
    {
        int a, b, c; cin >> a >> b >> c;
        if (a == -1 && b == -1 && c == -1)
            break;
        
        if (a <= 0 || b <= 0 || c <= 0)
            printf("w(%d, %d, %d) = %d\n", a, b, c, 1);
        else if (a > 20 || b > 20 || c > 20)
            printf("w(%d, %d, %d) = %d\n", a, b, c, w[20][20][20]);
        else
            printf("w(%d, %d, %d) = %d\n", a, b, c, w[a][b][c]);
    }

    return 0;
}
