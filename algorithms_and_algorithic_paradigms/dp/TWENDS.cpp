#include <iostream>
#include <stdlib.h>
#include <string.h>
using namespace std;
typedef long long ll;

ll func(int *arr, ll **dp, int i, int j)
{
	if (i >= j)
		return 0;
	if (dp[i][j])
		return dp[i][j];
	dp[i][j] = max(arr[i] + (arr[i + 1] >= arr[j] ? func(arr, dp, i + 2, j) : func(arr, dp, i + 1, j - 1)), arr[j] + (arr[i] >= arr[j - 1] ? func(arr, dp, i + 1, j - 1) : func(arr, dp, i, j - 2)));
	return dp[i][j];
}
int main()
{
	int n, v, k = 0;
	ll total, first_player_max_score, second_player_score, result;
	cin >> n;
	while (n != 0)
	{
		int *arr = (int *)malloc(n * sizeof(int));
		;
		total = 0;
		ll **dp;
		dp = (ll **)malloc(n * sizeof(ll *));
		for (int i = 0; i < n; i++)
		{
			dp[i] = (ll *)malloc(n * sizeof(ll));
		}

		for (int i = 0; i < n; i++)
		{
			cin >> v;
			arr[i] = v;
		}
		for (int i = 0; i < n; i++)
		{
			total += (ll)arr[i];
		}
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				dp[i][j] = 0;
		}

		first_player_max_score = func(arr, dp, 0, n - 1);
		second_player_score = total - first_player_max_score;
		result = first_player_max_score - second_player_score;
		cout << "In game " << k + 1 << ", the greedy strategy might lose by as many as " << result << " points.\n";
		cin >> n;
		k++;
	}
	return 0;
}