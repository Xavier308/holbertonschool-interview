#include "sandpiles.h"

/**
 * is_stable - Checks if a sandpile is stable.
 * @grid: The 3x3 sandpile to check.
 *
 * Return: 1 if the sandpile is stable (all values ≤ 3), 0 otherwise.
 */
int is_stable(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
				return (0);
		}
	}
	return (1);
}

/**
 * topple - Distributes grains from unstable cells in a sandpile.
 * @grid: The 3x3 sandpile to topple.
 *
 * Description: If a cell has 4 or more grains, it loses 4 grains,
 *              and each of its adjacent cells gains 1 grain.
 */
void topple(int grid[3][3])
{
	int i, j, copy_grid[3][3];

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			copy_grid[i][j] = grid[i][j];
		}
	}
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] >= 4)
			{
				copy_grid[i][j] -= 4;
				if (i + 1 < 3)
					copy_grid[i + 1][j] += 1;
				if (i - 1 >= 0)
					copy_grid[i - 1][j] += 1;
				if (j + 1 < 3)
					copy_grid[i][j + 1] += 1;
				if (j - 1 >= 0)
					copy_grid[i][j - 1] += 1;
			}
		}
	}

    /* Copy the updated values back to the original grid */
	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid[i][j] = copy_grid[i][j];
		}
	}
}

/**
 * sandpiles_sum - Adds two 3x3 sandpiles and stabilizes the result.
 * @grid1: The first sandpile (result is stored here).
 * @grid2: The second sandpile to be added.
 *
 * Description: Sums both sandpiles element-wise, then repeatedly
 *              topples the pile until it is stable. Prints the sandpile
 *              whenever toppling occurs.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] += grid2[i][j];
		}
	}
	while (!is_stable(grid1))
	{
		printf("=\n");
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (j)
					printf(" ");
				printf("%d", grid1[i][j]);
			}
			printf("\n");
		}
		topple(grid1);
	}
}
