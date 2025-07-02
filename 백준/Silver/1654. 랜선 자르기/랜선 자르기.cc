#include <bits/stdc++.h>

using namespace std;

vector<long long int> lan;
vector<long long int> num;
int main()
{
    ios_base::sync_with_stdio(false); cin.tie(NULL);
    int n, k; cin >> n >> k;
    long long int length_lan;
    lan.resize(n);
    for (int i = 0; i < n; i++) {
        cin >> length_lan;
        lan.push_back(length_lan);
    }

    long long int token = 0;
    for (long long int i : lan) {
        token += i;
    }
    token = token / k;
   // cout << "first token : " << token << '\n';

    long long int result;
    long long int token_res;
    long long int start = 1, end = token;
    while (start <= end) {
        token = (start + end) / 2;
        num.clear();
        for (long long int i : lan) {
            num.push_back(i / token);
        }

        token_res = 0;
        for (long long int i : num) {
            token_res += i;
        }
        //cout << "token_res : " << token_res << " token : " << token << '\n';
        if (token_res >= k) {
            result = token;
            start = token + 1;
        }
        else
            end = token - 1;      
    }

    cout << result;
}