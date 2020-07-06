#include <stdio.h>
#include <string.h>
#include <vector>
#include <iostream>

using namespace std;
#define MAX_BUFFER 5002
/* https://www.spoj.com/problems/ACODE/ */
int main()
{
  char buff[MAX_BUFFER];
  vector<int> output;
  while (fgets(buff, MAX_BUFFER, stdin) != NULL && buff[0] != 48)
  {
    //printf("%s",buff);
    int len = strlen(buff);
    //printf("%d\n",len);
    int dp[len];
    memset(dp, 0, len * sizeof(int));
    dp[0] = 1;
    if (buff[1] != 48)
    {
      dp[1] = dp[0];
    }

    if ((buff[1] < 55 && buff[0] == 50) || (buff[0] == 49))
    {
      dp[1] = dp[1] + 1;
    }
    for (int i = 2; i < len - 1; i++)
    {
      if (buff[i] == 48)
      {
        dp[i] = dp[i - 2];
        continue;
      }
      dp[i] = dp[i - 1];
      //compatible
      if ((buff[i] < 55 && buff[i - 1] == 50) || (buff[i - 1] == 49))
      {
        dp[i] = dp[i] + dp[i - 2];
      }
    }
    output.push_back(dp[len - 2]);
  }
  for (int i = 0; i < output.size(); i++)
  {
    printf("%d\n", output[i]);
  }
  return 0;
}