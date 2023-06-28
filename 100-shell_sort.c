#include "sort.h"

/**
 * swap_ints - Swap two integers in an array.
 * @a: Represents the first integer to swap.
 * @b: Represents the second integer to swap.
 */
void swap_ints(int *m, int *n)
{
	int tmp;

	tmp = *m;
	*m = *n;
	*n = tmp;
}

/**
 * shell_sort - Sort an array of integers in ascending
 *              order using the shell sort algorithm.
 * @array: Represents an array of integers.
 * @size: Represents the size of the array.
 *
 * Description: This uses the Knuth interval sequence.
 */
void shell_sort(int *array, size_t size)
{
	size_t gap, i, j;

	if (array == NULL || size < 2)
		return;

	for (gap = 1; gap < (size / 3);)
		gap = gap * 3 + 1;

	for (; gap >= 1; gap /= 3)
	{
		for (i = gap; i < size; i++)
		{
			j = i;
			while (j >= gap && array[j - gap] > array[j])
			{
				swap_ints(array + j, array + (j - gap));
				j -= gap;
			}
		}
		print_array(array, size);
	}
}
