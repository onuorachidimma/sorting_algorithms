#include "sort.h"
/**
 * shell_sort - A function that sorts an array
 * of integers in ascending order
 *
 * @array: Array Argument
 * @size: Array Size Argument
 */
void shell_sort(int *array, size_t size)
{
	size_t n = 1;

	while (n < size)
		n = (n * 3) + 1;

	while ((n = (n - 1) / 3) > 0)
		_ssort(array, size, n);
}
/**
 * _ssort - A shell sort function
 *
 * @a: Input Argument
 * @size: Array size Argument
 * @n: intervale Argument
 */
void _ssort(int *a, int size, int n)
{
	int tmp, i, j;

	for (i = 0; (i + n) < size; i++)
	{
		for (j = i + n; (j - n) >= 0; j = j - n)
		{
			if (a[j] < a[j - n])
			{
				tmp = a[j];
				a[j] = a[j - n];
				a[j - n] = tmp;
			}
		}
	}
	print_array(a, size);
}
