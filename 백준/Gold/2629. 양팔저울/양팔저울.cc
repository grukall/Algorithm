#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

const int MAX_N = 31;
const int MAX_W = 15001; // 추의 최대 합(500*30)

vector<int> weight;
bool dp[MAX_N][MAX_W];   // dp[i][w]: i번째까지 사용해서 w의 차이를 만들 수 있는가
int n;

void solve(int idx, int w) {
    if (idx > n) return;
    if (dp[idx][w]) return;
    dp[idx][w] = true;
    solve(idx+1, w); // 추 사용 안 함
    solve(idx+1, w + weight[idx]); // 반대쪽에 올림
    solve(idx+1, abs(w - weight[idx])); // 구슬 쪽 저울에 올림
}

int main() {
    ios::sync_with_stdio(0); cin.tie(0);
    cin >> n;
    weight.resize(n);

    for (int i = 0; i < n; i++) cin >> weight[i];

    solve(0, 0);

    int m;
    cin >> m;
    for (int i = 0; i < m; i++) {
        int bead; cin >> bead;
        if (bead > MAX_W-1) cout << "N ";
        else if (dp[n][bead]) cout << "Y ";
        else cout << "N ";
    }
    return 0;
}