  #include <iostream>
  #include <vector>
  #include <algorithm>

  using namespace std;


  int main()
  {
    vector<int> card;
    int n; cin >> n;
    for (int i = 0; i < n; i++)
    {
      int temp; cin >> temp;
      card.push_back(temp);
    }

    sort(card.begin(), card.end());

    vector<int> number;
    int m; cin >> m;
    for (int i = 0; i < m; i++)
    {
      int temp; cin >> temp;
      number.push_back(temp);
    }

    for (int num : number)
    {
      if (binary_search(card.begin(), card.end(), num))
        cout << "1 ";
      else
        cout << "0 ";
    }
  }