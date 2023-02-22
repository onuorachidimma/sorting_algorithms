#include "sort.h"
#include <stdio.h>
/**
 * print_data - A function that prints data
 *
 * @msg: Data Argument (To be printed)
 * @a: Array Argument
 * @from: Starting Argument
 * @to: Ending Argument
 */

void print_data(char *msg, int *a, int from, int to)
{
	char *sep;
	int i;

	printf("[%s]: ", msg);
	sep = "";

	for (i = from; i <= to; i++)
	{
		printf("%s%d", sep, a[i]);
		sep = ", ";
	}
	printf("\n");
}

/**
 * merge - A function that merges sort algorithm
 *
 * @a: Array Argument
 * @low: Low level Argument
 * @middle: Mid level Argument
 * @high: High Level Argument
 * @buff: Buffer Argument
 */

void merge(int *a, int low, int middle, int high, int *buff)
{
	int lo, lm, i;

	lo = i = low;
	lm = middle + 1;

	printf("Merging...\n");
	print_data("left", a, low, middle);
	print_data("right", a, middle + 1, high);

	while (lo <= middle && lm <= high)
	{
		if (a[lo] < a[lm])
			buff[i++] = a[lo++];
		else
			buff[i++] = a[lm++];
	}

	while (lo <= middle)
		buff[i++] = a[lo++];

	while (lm <= high)
		buff[i++] = a[lm++];

	for (i = low; i <= high; i++)
		a[i] = buff[i];

	print_data("Done", a, low, high);
}
/**
 * msort - A function that merges auxiliar  sort algorithm
 *
 * @array: array
 * @low: low index
 * @high: high index
 * @buffer: buffer
 */

void msort(int *array, int low, int high, int *buffer)
{
	int midle;

	if (low < high)
	{
		midle = (low + high - 1) / 2;
		msort(array, low, midle, buffer);
		msort(array, midle + 1, high, buffer);
		merge(array, low, midle, high, buffer);
	}
}
/**
 * merge_sort - A function that sorts an array of integers
 * in ascending order using the
 *
 * @array: array
 * @size: size
 */

void merge_sort(int *array, size_t size)
{
	int *buffer;

	buffer = malloc(sizeof(int) * size);
	if (!buffer)
		return;
	msort(array, 0, size - 1, buffer);
	free(buffer);
}
