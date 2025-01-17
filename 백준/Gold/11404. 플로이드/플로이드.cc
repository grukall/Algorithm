    #include <iostream>
    #include <vector>
    #include <algorithm>
    #include <queue>

    using namespace std;

    // 최대거리는 도사거 최대일 때(n = 100), 최대 거리로 99번 이동할 경우(100000 * 99)
    #define DISTANCE_MAX  100 * (100000 * 99)
    int n; 
    vector<pair<int, int>> cities[101]; //(비용, 다음 도시)

    void bfs(int st, vector<int> &distance)
    {
        distance.resize(n+1);
        for (int i = 1; i <= n; i++)
            distance[i] = DISTANCE_MAX;
        
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<>> pq; //(비용, 다음 도시)

        //시작점 초기화
        pq.push(make_pair(0, st));

        while (!pq.empty())
        {
            int curCost = pq.top().first;
            int curCity = pq.top().second;
            pq.pop();
            //printf("curCost = %d, curCity = %d\n", curCost, curCity);

            //현재 검사하고자 하는 경로가 현재 최소 거리보다 큰 경우,
            //이 루트는 최소경로가 될 수 없으므로 건너뛴다.
            if (curCost > distance[curCity])
                continue;
            
            for (pair<int, int> bus : cities[curCity])
            {
                int busCost = bus.first;
                int nextCity = bus.second;
                //printf("bus(%d, %d)\n", busCost, nextCity);

                if (nextCity == st)
                    continue;

                //현재 버스를 타고 가는 비용이 가장 적은 비용의 방법이라면 갱신해준다.
                int newCost = curCost + busCost;
                if (newCost < distance[nextCity])
                {
                    //printf("new distance city = %d, cost = %d\n", nextCity, newCost);
                    distance[nextCity] = newCost;
                    pq.push(make_pair(newCost, nextCity));
                }
            }
        }

    }

    int main()
    {
        cin >> n;
        int m; cin >> m;


        for (int i = 0; i < m; i++)
        {
            int st, end, w; cin >> st >> end >> w;
            cities[st].push_back(make_pair(w, end));
        }

        vector<int> minimum_distance[n+1];

        for (int st = 1; st <= n; st++)
            bfs(st, minimum_distance[st]);

        for (int city = 1; city <= n; city++)
        {
            for (int nextCity = 1; nextCity <= n; nextCity++)
            {
                int dist = minimum_distance[city][nextCity];
                if (dist == DISTANCE_MAX)
                    cout << 0 << ' ';
                else
                    cout << dist << ' ';
            }
            cout << '\n';
        }
    }