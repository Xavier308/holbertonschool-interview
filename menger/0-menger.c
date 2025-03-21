#include <stdio.h>
#include <math.h>
#include "menger.h"

/**
 * menger - Draws a 2D Menger Sponge of a given level.
 * @level: The level of the Menger Sponge to draw.
 *
 * Description: A level N sponge is a 3x3 square of level N-1 sponges,
 * except for the center one, which is left empty. A level 0 sponge is
 * represented by the '#' character.
 */
void menger(int level)
{
	int size, row, col;
	int x, y;
	int blank;

	if (level < 0)
		return;

	size = (int)pow(3, level);
	for (row = 0; row < size; row++)
	{
		for (col = 0; col < size; col++)
		{
			blank = 0;
			x = row;
			y = col;

			while (x > 0 || y > 0)
			{
				if (x % 3 == 1 && y % 3 == 1)
				{
					blank = 1;
					break;
				}
				x /= 3;
				y /= 3;
			}

			if (blank)
				putchar(' ');
			else
				putchar('#');
		}
		putchar('\n');
	}
}
