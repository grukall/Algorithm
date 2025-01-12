#include <iostream>
#include <vector>

using namespace std;

int main()
{
    int n, k; cin >> n >> k;

    vector<pair<int, int>> bag(n);
    for (int i = 0; i < n; i++)
        cin >> bag[i].first >> bag[i].second;

    vector<int> dp(k+1, 0);

    for (int i = 0; i < n; i++)
    {
        for (int j = k; j >= bag[i].first; j--)
        {
            dp[j] = max(dp[j], dp[j-bag[i].first] + bag[i].second);
        }
    }

    cout << dp[k];
}