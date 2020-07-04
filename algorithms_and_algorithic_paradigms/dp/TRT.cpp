#include <iostream>
#include <stdlib.h>
using namespace std;
typedef long long ll;

ll func(ll *arr, ll **dp, ll **sum, int i, int j, int ac)
{
	if (i == j)
	{
		dp[i][i] = arr[i];
		return dp[i][i] + (ac - 1) * arr[i];
	}
	if (dp[i][j])
	{
		return dp[i][j] + (ac - 1) * sum[i][j];
	}
	ll val = max(func(arr, dp, sum, i + 1, j, ac + 1) + ac * arr[i], func(arr, dp, sum, i, j - 1, ac + 1) + ac * arr[j]);
	dp[i][j] = val - (ac - 1) * sum[i][j];
	return val;
}
int main()
{
	int n;
	ll s;
	cin >> n;
	ll arr[n];
	ll **dp;
	ll **sum;
	dp = (ll **)malloc(n * sizeof(ll *));
	sum = (ll **)malloc(n * sizeof(ll *));
	for (int i = 0; i < n; i++)
	{
		dp[i] = (ll *)malloc(n * sizeof(ll));
		sum[i] = (ll *)malloc(n * sizeof(ll));
	}

	for (int i = 0; i < n; i++)
	{
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++)
	{
		s = 0;
		for (int j = 0; j < n; j++)
		{
			dp[i][j] = 0;
			if (i < j)
			{
				sum[i][j] = 0;
				continue;
			}
			s += arr[j];
			sum[i][j] = s;
		}
	}

	cout << func(arr, dp, sum, 0, n - 1, 1);

	return 0;
}