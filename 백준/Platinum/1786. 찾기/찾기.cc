#include <iostream>
#include <vector>
#include <string>

using namespace std;

//str의 구간별 prefix와 suffix가 같은 갯수를 반환한다.
vector<int> getPi(const string &str)
{
    int size = str.size();
    vector<int> res(size);

    //문자 한 개는 취급 안한다.
    res[0] = 0;
    int j = 0;

    for (int i = 1; i < size; i++)
    {
        //문자가 일치하지 않지만 str이 res[j-1]까진 일치하므로 해당 위치로 이동
        while(j > 0 && str[i] != str[j])
            j = res[j-1];

        //문자가 일치하면 추가
        if(str[i] == str[j])
            res[i] = ++j;
    }

    return res;
}

vector<int> kmp(const string &s, const string &p)
{
    vector<int> ans;  
    vector<int> pi = getPi(p);

    int n = (int)s.size(), m = (int)p.size(), j = 0;

    for(int i = 0 ; i < n ; i++)
    {
        //문자가 일치하지 않지만 pi[j-1]끼진 일치하므로 해당 위치부터 다시 같은지 검사
        while (j > 0 && s[i] != p[j])
            j = pi[j-1];

        //같으면 추가
        if (s[i] == p[j])
        {   
            //문자열 전체가 같으면 결과값에 추가
            if (j == m-1)
            {        
                ans.push_back(i-m+1);
                j = pi[j];         
            }
            else j++;        
        }        
    }        
    return ans;
}


int main()
{
   string T, P;
   getline(cin, T);
   getline(cin, P);

   vector<int> res = kmp(T, P);
   cout << res.size() << '\n';

   for (int i : res)
    cout << i+1 << '\n';

}