#include <iostream>
#include <vector>

using namespace std;

struct matrix {
    int r;                       // 행
    int c;                       // 열
    unsigned long long cnt;      // 최소 연산 횟수
};

int main() {
    int N; 
    cin >> N;

    vector<vector<matrix>> dp(N, vector<matrix>(N));

    // 입력 (행, 열) 저장 + 단일 행렬은 연산 비용 0
    for (int i = 0; i < N; i++) {
        cin >> dp[0][i].r >> dp[0][i].c;
        dp[0][i].cnt = 0;
    }

    // range: 몇 개의 행렬을 곱하는지 (2개부터 N개까지)
    for (int range = 1; range < N; range++) {
        for (int start = 0; start + range < N; start++) {
            int end = start + range;
            dp[range][start].cnt = __INT_MAX__;

            // 모든 분할점 k에 대해 최소 비용 계산
            for (int k = start; k < end; k++) {
                unsigned long long cost = dp[k - start][start].cnt +
                                          dp[end - (k + 1)][k + 1].cnt +
                                          (unsigned long long)dp[k - start][start].r *
                                          dp[k - start][start].c *
                                          dp[end - (k + 1)][k + 1].c;

                if (cost < dp[range][start].cnt) {
                    dp[range][start].cnt = cost;
                    dp[range][start].r = dp[k - start][start].r;
                    dp[range][start].c = dp[end - (k + 1)][k + 1].c;
                }
            }
        }
    }

    cout << dp[N - 1][0].cnt << "\n";
    return 0;
}
