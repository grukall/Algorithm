#include <iostream>
#include <vector>

using namespace std;

int main()
{

    //볼수 있는 데이터
    //이전 삼각형들의 모양
    //인접 여부
    //1
    //2->1
    //3->2
    //4->13
    //5->4
    //6->15
    //7->26
    //8->37
    //9->48
    //10->59

    //1~5까지 하드코딩, 6부터 이전꺼랑 4차이나는 삼각형 변의 합
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int t; cin >> t;
    int cur = 5;
    vector<unsigned long long int> dp(101);
    dp[1] = 1;
    dp[2] = 1;
    dp[3] = 1;
    dp[4] = 2;
    dp[5] = 2;
    for (int i = 0; i < t; i++)
    {
        int n; cin >> n;
        if (n <= cur)
        {
            cout << dp[n] << '\n';
            continue;
        }

        for (int j = cur + 1; j <= n; j++)
        {
            dp[j] = dp[j-1] + dp[j-5];
        }
        cout << dp[n] << '\n';
        cur = n;
    }
}
