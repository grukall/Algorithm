#include <iostream>
#include <vector>
#include <string>
#include <sstream>


using namespace std;

int main()
{
  int n; cin >> n;
  int line = n*2 - 1;
  for (int i = 0; i < n; i++)
  {
    int st = n-i;
    int end = n+i;
    for (int star = 1; star <= line; star++)
    {
      if (star < st)
        printf(" ");
      else if (star >= st && star <= end)
        printf("*");
      else
        break;
    }

    printf("\n");
  }


  for (int i = n-2; i >= 0; i--)
  {
    int st = n-i;
    int end = n+i;
    for (int star = 1; star <= line; star++)
    {
      if (star < st)
        printf(" ");
      else if (star >= st && star <= end)
        printf("*");
      else
        break;
    }

    printf("\n");
  }
}