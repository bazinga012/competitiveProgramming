#include <bits/stdc++.h>

using namespace std;
int dp[5002][5002];

// Complete the commonChild function below.
int commonChild(string s1, string s2)
{
    int n = s1.length(), m = s2.length();
    memset(&dp[0][0], 0, sizeof(int) * (n + 1) * (m + 1));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            if (s1[i] == s2[j])
            {
                dp[i + 1][j + 1] = dp[i][j] + 1;
            }
            else
            {
                dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }
    return dp[n][m];
}


int main()
{
    ofstream fout(getenv("OUTPUT_PATH"));

    string s1;
    getline(cin, s1);

    string s2;
    getline(cin, s2);

    int result = commonChild(s1, s2);

    fout << result << "\n";

    fout.close();

    return 0;
}
