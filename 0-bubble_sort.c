#include "sort.h"

/**
 * bubble_sort - A function that sorts an array
 *
 * @array: Input Argument
 * @size: Size Argument
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, n;
	int tmp, swap;

	for (n = size, swap = 1; n > 0 && swap; n--)
	{
		swap = 0;
		for (i = 0; (i + 1) < n; i++)
		{
			if (array[i] > array[i + 1])
			{
				tmp = array[i + 1];
				array[i + 1] = array[i];
				array[i] = tmp;
				print_array(array, size);
				swap = 1;
			}
		}
	}
}
