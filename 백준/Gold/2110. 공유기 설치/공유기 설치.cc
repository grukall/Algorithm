#include <iostream>
#include <vector>
#include <algorithm>
#include <unistd.h>

using namespace std;

int main()
{
    int n, c; cin >> n >> c;
    vector<int> homes(n);
    for (int i = 0; i < n; i++)
        cin >> homes[i];

    sort(homes.begin(), homes.end());

    // for (int x : homes)
    //     printf("%d ", x);
    
    //공유기 끼리의 간격을 넙혀야 하므로, 첫 번째 집과 마지막 집은 확정

    //범위중에 거리 지정
    int start = 0, end = homes[n-1] - homes[0];
     if (c == 2)
    {
        cout << end;
        return 0;
    }

    int maxLength = 0;
    while (start <= end)
    {
        int middle = (end + start) / 2;
        //2. 거리를 만족하도록 c 배치
        int count = c-1;
        int length = 0;
        int minLength = 1000000000;
        for (int i = 1; i < n; i++)
        {
            length += homes[i] - homes[i-1];
            if (length < middle) continue;

            count--;
            if (minLength > length) minLength = length;
            length = 0;
            if (count == 0) break;
        }

       // printf("(%d - %d)count = %d, middle = %d\n", start, end, count, middle);

        //갯수를 만족하지 못하면 거리를 줄임
        if (count > 0)
        {
            end = middle - 1;
            continue;
        }

        //4. 최소 거리가 최대 일때, 최댓값 갱신, c개 뽑기시 거리를 넓혀봄
        //-> 
        if (maxLength < minLength)
        {
            maxLength = minLength;
        }
        start = middle + 1;

        //sleep(1);
    }

     cout << maxLength;
}