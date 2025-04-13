#include <iostream>
#include <sstream>
#include <algorithm>
#include <vector>
#include <queue>
#include <map>
using namespace std;

struct word
{
   string w;
   int count;

   word(string a, int b) {
      w = a;
      count = b; 
   }

   bool operator<(const word &d) const {
      if (count != d.count)
         return count < d.count;
      else if (w.size() != d.w.size())
         return w.size() < d.w.size();
      else
         return w > d.w;
   }

   bool operator>(const word &d) const {
      if (count != d.count)
         return count > d.count;
      else if (w.size() != d.w.size())
         return w.size() > d.w.size();
      else
         return w < d.w;
   }
};

word* find(vector<word>& words, const string& s)
{
   for (word& w : words)
   {
      if (w.w == s) return &w;
   }
   return nullptr;
}

int main()
{
   cin.tie(NULL);
   ios::sync_with_stdio(false);
   int n, m; cin >> n >> m;
   cin.ignore();


   stringstream ss;
   map<string, int> words;
   priority_queue<word, vector<word>> pq;
   for (int i = 0; i < n; i++)
   {
      string s; getline(cin, s);
      if (s.size() >= m)
      {
         // if (word *w = find(words, s))
         // {
         //    w->count++;
         // }
         // else words.push_back({s,0});
         if (words.find(s) != words.end())
            words[s]++;
         else
            words[s] = 0;
      }
   }

   for (const auto& pair : words) {
      pq.push({pair.first, pair.second});
  }

   // sort(words.begin(), words.end(), [](word a, word b) {
   //    if (a.count != b.count)
   //       return a.count > b.count;
   //    else if (a.w.size() != b.w.size())
   //       return a.w.size() > b.w.size();
   //    else
   //       return a.w < b.w;
   // });

   // for (word w : words)
   // {
   //    cout << w.w << '\n';
   // }

   while (!pq.empty())
   {
      cout << pq.top().w << '\n';
      pq.pop();
   }
   
}
