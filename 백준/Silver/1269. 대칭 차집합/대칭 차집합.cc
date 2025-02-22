  #include <iostream>
  #include <vector>
  #include <algorithm>
  #include <queue>

  using namespace std;


  int main()
  {
    int a, b; cin >> a >> b;
    priority_queue<int, vector<int>, greater<>> na;
    priority_queue<int, vector<int>, greater<>> nb;

    for (int i = 0; i < a; i++)
    {
      int temp; cin >> temp;
      na.push(temp);
    }

    for (int i = 0; i < b; i++)
    {
      int temp; cin >> temp;
      nb.push(temp);
    }

    int count = 0;
    while (!na.empty() && !nb.empty())
    {
      //printf("na = %d, nb = %d\n", na.top(), nb.top());
      if (na.top() > nb.top())
      {
        count++;
        nb.pop();
      }
      else if (na.top() < nb.top())
      {
        count++;
        na.pop();
      }
      else
      {
        na.pop();
        nb.pop();
      }
    }

    while(!na.empty())
    {
      na.pop();
      count++;
    }

    while(!nb.empty())
    {
      nb.pop();
      count++;
    }
    cout << count;
  }