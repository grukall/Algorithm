#include <bits/stdc++.h>

using namespace std;

vector<int> v2;
int ct[20000001];

int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, m;
    int num;

    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> num;
        ct[num + 10000000] += 1;
    }
    
    cin >> m;
    for (int i = 0; i < m; i++) {
        cin >> num;
        v2.push_back(num);
    }

    for (int i = 0; i < m; i++) {
        cout << ct[v2[i] + 10000000];
        if (i < m - 1)
            cout << ' ';
    }
}