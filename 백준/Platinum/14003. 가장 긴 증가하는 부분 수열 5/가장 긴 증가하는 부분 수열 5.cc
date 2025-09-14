#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int n; cin >> n;
    vector<int> nums(n);
    vector<int> dp(n);
    vector<int> lis;
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
        if (lis.size() == 0)
        {
            lis.push_back(nums[i]);
            dp[i] = lis.size();
            //printf("lis[%d] = %d, dp[%d] = %d\n", lis.size()-1, lis.back(), i, dp[i]);
        }

        else if (lis.back() < nums[i]) 
        {
            lis.push_back(nums[i]);
            dp[i] = lis.size();
            //printf("lis[%d] = %d, dp[%d] = %d\n", lis.size()-1, lis.back(), i, dp[i]);
        }

        else
        {
            auto it = lower_bound(lis.begin(), lis.end(), nums[i]);

            //lis에서 it가 몇 번째 index인지 알고싶은데 어떻게 해야 할까
            int index = it - lis.begin(); 
            lis[index] = nums[i];
            dp[i] = index + 1;
            // printf("change lis[%d] = %d, dp[%d] = %d\n", index, lis[index], i, dp[i]);
            // for (const int list : lis)
            //     cout << list << ' ';
            // cout << '\n';
        
        }
    }

    int max = lis.size(); cout << max << '\n';
    int index = max;
    vector<int> stack;
    for (int i = n-1; i >= 0; --i)
    {
        if (dp[i] == index)
        {
            index--;
            stack.push_back(nums[i]);
        }
    }

    for (int i = stack.size()-1; i >= 0; --i)
        cout << stack[i] << ' ';
}