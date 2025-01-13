#include <iostream>
#include <vector>
#include <queue>

using namespace std;

// 수빈이는 동생과 숨바꼭질을 하고 있다. 수빈이는 현재 점 N(0 ≤ N ≤ 100,000)에 있고, 동생은 점 K(0 ≤ K ≤ 100,000)에 있다. 수빈이는 걷거나 순간이동을 할 수 있다.
//  만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 순간이동을 하는 경우에는 0초 후에 2*X의 위치로 이동하게 된다.
//수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.


void bfs(int n, int k)
{
    //k가 n보다 같거나 작으면 1초씩 뒤로 가는 방법밖에 없다.
    if (k <= n)
    {
        cout << n-k;
        return;
    }

    queue<int> map;
    vector<int> visited(100001, -1);
    map.push(n);
    visited[n] = 0;

    while(!map.empty())
    {
        int cur = map.front();
        //cout << "cur : " << cur << ", visited :" << visited[cur] << '\n';

        if (cur == k)
        {
            cout << visited[cur];
            break;
        }
        
        map.pop();

       // 다음 가능한 이동 처리
        if (cur * 2 <= 100000 && visited[cur * 2] == -1) {
            map.push(cur * 2);
            visited[cur * 2] = visited[cur]; // 순간 이동은 시간 증가 없음
        }
        if (cur - 1 >= 0 && visited[cur - 1] == -1) {
            map.push(cur - 1);
            visited[cur - 1] = visited[cur] + 1; // 걷는 이동은 시간 1 증가
        }
        if (cur + 1 <= 100000 && visited[cur + 1] == -1) {
            map.push(cur + 1);
            visited[cur + 1] = visited[cur] + 1; // 걷는 이동은 시간 1 증가
        }
    }
}


int main()
{

    int n, k; cin >> n >> k;
    bfs(n, k);
}