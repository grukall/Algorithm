#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;

int main() {
    //ios::sync_with_stdio(false);
    cin.tie(nullptr);
    
    int n;
    while (true) {
        cin >> n;
        if (n == 0) break;
        
        vector<long long> histogram(n);
        for (int i = 0; i < n; i++) {
            cin >> histogram[i];
        }
        
        stack<long long> st;
        long long maxArea = 0;
        int i = 0;
        
        while (i < n) {
            if (st.empty() || histogram[st.top()] <= histogram[i]) {
                st.push(i++);
            } else {
                long long top = st.top();
                st.pop();
                long long width = st.empty() ? i : i - st.top() - 1;
                maxArea = max(maxArea, histogram[top] * width);
            }
        }
        
        while (!st.empty()) {
            long long top = st.top();
            st.pop();
            long long width = st.empty() ? n : n - st.top() - 1;
            maxArea = max(maxArea, histogram[top] * width);
        }
        
        cout << maxArea << '\n';
    }
    return 0;
}
