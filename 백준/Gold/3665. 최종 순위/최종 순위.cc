#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int topological_sort(const vector<vector<int>>& g, vector<int> entry, vector<int> &res) {
    int n = entry.size();
    queue<int> q;
    for(int i=0; i<n; ++i)
        if(entry[i] == 0)
            q.push(i);
    for(int i=0; i<n; ++i) {
        if(q.empty()) return -1;
        if(q.size() > 1) return 0;
        int cur = q.front(); q.pop();
        res.push_back(cur);
        for(int next : g[cur])
            if(--entry[next] == 0)
                q.push(next);
    }
    return 1;
}

int main() {
    int T; cin >> T;
    while(T--) {
        int n; cin >> n;
        vector<int> lastYear(n);
        for(int i=0; i<n; ++i) { cin >> lastYear[i]; lastYear[i]--; }
        vector<vector<int>> g(n);
        vector<int> entry(n, 0);
        for(int i=0; i<n; ++i)
            for(int j=i+1; j<n; ++j) {
                g[lastYear[i]].push_back(lastYear[j]);
                entry[lastYear[j]]++;
            }
        int m; cin >> m;
        while(m--) {
            int a,b; cin>>a>>b; a--; b--;
            // a->b 면 b의 indegree --, a의 ++
            auto it = find(g[a].begin(), g[a].end(), b);
            if(it != g[a].end()) {
                g[a].erase(it);
                entry[b]--;
                g[b].push_back(a);
                entry[a]++;
            } else {
                it = find(g[b].begin(), g[b].end(), a);
                g[b].erase(it);
                entry[a]--;
                g[a].push_back(b);
                entry[b]++;
            }
        }
        vector<int> res;
        int result = topological_sort(g, entry, res);
        if(result == -1) cout << "IMPOSSIBLE\n";
        else if(result == 0) cout << "?\n";
        else {
            for(int i=0; i<n; ++i)
                cout << res[i]+1 << (i+1==n?'\n':' ');
        }
    }
}
