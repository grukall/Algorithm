#include <iostream>
#include <vector>


using namespace std;

int main()
{
    int n, m; cin >> n >> m;
    vector<int> trees(n);
    int biggest = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> trees[i];
        if (biggest < trees[i]) biggest = trees[i];
    }
    
    // 기준 h를 어떻게 정할까..
    int start = 1; int end = biggest;
    int res = 0;
    while (start <= end)
    {
        int middle = (start + end) / 2;
        long long int total = 0;
        // printf("\nstart = %d, end = %d, middle = %d\n", start, end, middle);
        //자르는 나무 산출
        for (int i = 0; i < n; i++)
            total += trees[i] - middle >= 0 ? trees[i] - middle : 0;
        
        //결과가 필요한 나무 크기보다 크면, h를 middle보다 1 키워본다.
        if (total >= m)
        {
            res = middle;
            start = middle + 1;
             //("많다! total = %d, res = %d\n",total, res);
        }
        // 결과가 필요한 나무크기보다 작으면, h를 middle보다 1 줄여본다.
        else
        {
            // printf("적다! total = %d, res = %d\n",total, res);
            end = middle - 1;
        }
    }

    cout << res;

}