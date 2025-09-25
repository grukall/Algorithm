#include <iostream>
#include <string>
#include <queue>
#include <vector>
#include <algorithm> // reverse 함수를 사용하기 위해 추가

using namespace std;

// 전역 변수 대신 main 함수 내 지역 변수로 관리하는 것이 좋습니다.
// int A, B; 

void bfs(int A, int B)
{
    // 각 숫자의 방문 여부, 부모 노드, 사용된 명령어를 저장할 배열
    vector<bool> visited(10000, false);
    vector<int> parent(10000, 0);
    vector<char> command(10000, ' ');

    queue<int> q;
    q.push(A);
    visited[A] = true;

    while (!q.empty())
    {
        int cur = q.front();
        q.pop();

        if (cur == B)
        {
            string result = "";
            int temp = B;
            // B부터 A까지 역으로 경로를 추적
            while (temp != A)
            {
                result += command[temp];
                temp = parent[temp];
            }
            // 만들어진 경로는 역순이므로 뒤집어준다.
            reverse(result.begin(), result.end());
            cout << result << '\n';
            return;
        }

        // 1. D 연산
        int D = (cur * 2) % 10000;
        if (!visited[D])
        {
            visited[D] = true;
            parent[D] = cur;
            command[D] = 'D';
            q.push(D);
        }

        // 2. S 연산
        int S = (cur == 0) ? 9999 : cur - 1;
        if (!visited[S])
        {
            visited[S] = true;
            parent[S] = cur;
            command[S] = 'S';
            q.push(S);
        }

        // 3. L 연산
        int L = (cur % 1000) * 10 + (cur / 1000);
        if (!visited[L])
        {
            visited[L] = true;
            parent[L] = cur;
            command[L] = 'L';
            q.push(L);
        }

        // 4. R 연산
        int R = (cur % 10) * 1000 + (cur / 10);
        if (!visited[R])
        {
            visited[R] = true;
            parent[R] = cur;
            command[R] = 'R';
            q.push(R);
        }
    }
}

int main()
{
    cin.tie(NULL);
    ios::sync_with_stdio(false);

    int T;
    cin >> T;
    while (T--)
    {
        int A, B;
        cin >> A >> B;
        bfs(A, B);
    }
    return 0;
}