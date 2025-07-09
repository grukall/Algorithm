#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;



int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int n; cin >> n;
    priority_queue<int, vector<int>, greater<int>> pq;
    

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            int k; cin >> k;
            pq.push(k);
            if (pq.size() > n) pq.pop();
        }
    }

    cout << pq.top();
}