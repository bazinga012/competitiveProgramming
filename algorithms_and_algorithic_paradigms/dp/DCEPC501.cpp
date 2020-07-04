#include <stdio.h>
#include <stdlib.h>
#include <string.h>

using namespace std;
typedef long long ll;

ll maxll(ll a, ll b, ll c)
{
	ll d = a > b ? a : b;
	return c > d ? c : d;
}

ll func(ll *toys, ll *sum2, ll *sum3, ll *dp, int i, int n)
{
	if (i >= n)
		return 0;
	if (dp[i])
		return dp[i];

	dp[i] = maxll(toys[i] + func(toys, sum2, sum3, dp, i + 2, n), sum2[i] + func(toys, sum2, sum3, dp, i + 4, n), sum3[i] + func(toys, sum2, sum3, dp, i + 6, n));
	return dp[i];
}

int main()
{
	int t, n;
	scanf("%d", &t);
	while (t--)
	{
		scanf("%d", &n);
		ll *toys, *dp, *sum2, *sum3;
		toys = (ll *)malloc(n * sizeof(ll));
		dp = (ll *)malloc(n * sizeof(ll));

		sum2 = (ll *)malloc(n * sizeof(ll));
		sum3 = (ll *)malloc(n * sizeof(ll));

		memset(dp, 0, sizeof(ll) * n);
		memset(sum2, 0, sizeof(ll) * n);
		memset(sum3, 0, sizeof(ll) * n);

		for (int i = 0; i < n; i++)
		{
			scanf("%lld", &toys[i]);
		}

		for (int i = 0; i < n - 2; i++)
		{
			sum2[i] = toys[i] + toys[i + 1];
			sum3[i] = sum2[i] + toys[i + 2];
		}

		if (n - 1 >= 0)
			dp[n - 1] = toys[n - 1];
		if (n - 2 >= 0)
		{
			sum2[n - 2] = toys[n - 2] + toys[n - 1];
			dp[n - 2] = toys[n - 2] + dp[n - 1];
		}
		if (n - 3 >= 0)
			dp[n - 3] = toys[n - 3] + dp[n - 2];
		printf("%lld\n", func(toys, sum2, sum3, dp, 0, n));
		free(dp);
		free(toys);
	}
	return 0;
}
