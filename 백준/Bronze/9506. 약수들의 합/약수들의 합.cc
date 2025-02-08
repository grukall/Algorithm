  #include <stdio.h>

  int main()
  {
    int n;
    int input[100000];
    int count = 0;
    while (true)
    {
      scanf("%d", &n);
      if (n == -1)
        break;

      input[count] = n;
      count++; 
    }


    for (int i = 0; i < count; i++)
    {
      int curNum = input[i];
      if (curNum == 6)
      {
        printf("6 = 1 + 2 + 3\n");
      }
      else if (curNum == 28)
      {
        printf("28 = 1 + 2 + 4 + 7 + 14\n");
      }
      else if (curNum == 496)
      {
        printf("496 = 1 + 2 + 4 + 8 + 16 + 31 + 62 + 124 + 248\n");
      }
      else if (curNum == 8128)
        printf("8128 = 1 + 2 + 4 + 8 + 16 + 32 + 64 + 127 + 254 + 508 + 1016 + 2032 + 4064\n");
      else
        printf("%d is NOT perfect.\n", curNum);
    }
  }

  //   vector<int> input;
  //   for (int n = 3; n < 100000; n++)
  //     input.push_back(n);

  //   vector<int> divisor[100000];
  //   for (int i = 0; i < input.size(); i++)
  //   {
  //     int count = 1;
  //     int curNum = input[i];
  //     divisor[i].push_back(1);

  //     for (int num = 2; num <= curNum / 2; num++)
  //     {
  //       if (curNum % num == 0)
  //       {
  //         count += num;
  //         divisor[i].push_back(num);
  //       }
  //     }

  //     if (count == curNum && curNum != 1)
  //     {
  //       printf("%d = ", curNum);
  //       for (int j = 0; j < divisor[i].size(); j++)
  //       {
  //         if (j == 0)
  //           printf("%d", divisor[i][j]);
  //         else
  //           printf(" + %d", divisor[i][j]);
  //       }

  //       printf("\n");
  //     }
  //     // else
  //     //   printf("%d is NOT perfect.\n", curNum);
  //   }
  // }