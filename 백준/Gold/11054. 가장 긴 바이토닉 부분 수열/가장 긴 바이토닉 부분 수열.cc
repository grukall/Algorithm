#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> num(n);
    for (int i = 0; i < n; i++)
        cin >> num[i];
    
    vector<int> upper(n, 1);
    vector<int> lower(n, 1);

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j <= i; j++)
        {
            if (num[j] < num[i] && upper[i] < upper[j] + 1)
            {
                upper[i] = upper[j] + 1;
            }
        }
    }

    for (int i = n-1; i >= 0; i--)
    {
        for (int j = n-1; j >= i; j--)
        {
            if (num[i] > num[j] && lower[j] + 1 > lower[i])
                lower[i] = lower[j] + 1;
        }
    }

    int res = 0;
    for (int i = 0; i < n; i++)
    {
        if (res < upper[i] + lower[i] - 1) res = upper[i] + lower[i] - 1;
    }

    cout << res;
}
