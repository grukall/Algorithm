#include <iostream>
#include <vector>

using namespace std;

int main()
{
    // cin.tie(NULL);
    // ios::sync_with_stdio(false);
    int n; cin >> n;

    vector<int> balloons(n);
    vector<bool> visited(n, 0);
    for (int i = 0; i < n; i++)
    {
        cin >> balloons[i];
    }

    int remain = n;
    int nextbln = 0;
    while (remain > 0)
    {
        //풍선을 터트린다.
        int num = balloons[nextbln];
        cout << nextbln+1 << ' ';
        visited[nextbln] = true;
        remain--;
        if (remain == 0)
            break;

        // printf("visited : [");
        // for (bool visit : visited)
        // {
        //     printf("%c ", visit ? '0' : '*');
        // }
        // printf("]\n");

        //다음 풍선을 고른다.
        //만약 이동해야 할 거리가 remain보다 크다면
        //루프하는 거리를 제외한다.

        if (num > 0)
        {
            while (visited[nextbln])
            {
                nextbln++;
                if (nextbln == n)
                    nextbln = 0;
            }
            num -= 1;
        }
        else
        {
            while (visited[nextbln])
            {
                nextbln--;
                if (nextbln < 0)
                    nextbln = n-1;
            }
            num += 1;
        }

        int temp = abs(num);
        temp = temp % remain;

        //printf("num = %d, remain = %d, temp = %d\n",num, remain, temp);

        if (num > 0)
        {
            while (temp)
            {
                nextbln++;
                if (nextbln == n)
                    nextbln = 0;
                if (!visited[nextbln])
                    temp--;
            }   
        }
        else
        {
            while (temp)
            {
                nextbln--;
                if (nextbln < 0)
                    nextbln = n-1;
                if (!visited[nextbln])
                    temp--;
            }   
        }

    }
}
