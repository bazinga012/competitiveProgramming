#include <iostream>
#include <cstdlib>
#include <string.h>

using namespace std;
int main()
{
	int t, r, c;
	cin >> t;
	while (t--)
	{
		cin >> r >> c;
		int **grid = (int **)malloc(r * sizeof(int *));
		for (int i = 0; i < r; i++)
		{
			grid[i] = (int *)malloc(c * sizeof(int));
		}
		//memset(grid[0], 0 , r * c * sizeof(int)); gives free(): invalid next size (fast) error
		for (int i = 0; i < r; i++)
		{
			for (int j = 0; j < c; j++)
			{
				cin >> grid[i][j];
			}
		}

		grid[r - 1][c - 1] = 1;
		for (int i = r - 2; i >= 0; i--)
		{
			grid[i][c - 1] = grid[i + 1][c - 1] - grid[i][c - 1];
			if (grid[i][c - 1] <= 0)
			{
				grid[i][c - 1] = 1;
			}
		}

		for (int i = c - 2; i >= 0; i--)
		{
			grid[r - 1][i] = grid[r - 1][i + 1] - grid[r - 1][i];
			if (grid[r - 1][i] <= 0)
			{
				grid[r - 1][i] = 1;
			}
		}

		for (int i = r - 2; i >= 0; i--)
		{
			for (int j = c - 2; j >= 0; j--)
			{
				grid[i][j] = min(grid[i + 1][j], grid[i][j + 1]) - grid[i][j];
				if (grid[i][j] <= 0)
				{
					grid[i][j] = 1;
				}
			}
		}

		cout << grid[0][0] << "\n";

		for (int i = 0; i < r; i++)
		{
			free(grid[i]);
		}
		free(grid);
	}
}