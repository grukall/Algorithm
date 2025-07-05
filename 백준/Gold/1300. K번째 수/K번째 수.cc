#include <iostream>

using namespace std;

int main()
{
    int n, k; cin >> n >> k;


    int start = 1, end = k;
    while (start < end)
    {
        int cur = (start + end) / 2;
        int c = 0;
        for (int i = 1; i <= n; i++)
            c += min(n, cur / i);
  
        if (c < k)
        {
            start = cur + 1;
        }
        else if (c >= k)
        {
            end = cur;
        }
    }

    cout << end;
}