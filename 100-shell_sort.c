#include "sort.h"

/**
 * shell_sort - algorithm to sort numbers with shell sort method
 * @array: unsorted array
 * @size: size of array
 */
void shell_sort(int *array, size_t size)
{
	int gap = 1, tmp = 0, i, j, n = (int)size;

	while (gap <= n)
		gap = 1 + (gap * 3); /*next value of gap sequence using Knuth method*/
	gap = (gap - 1) / 3;
	while (gap >= 1)
	{
		for (i = gap; i < n; i++)
		{
			tmp = array[i]; /*starting replacing*/
			for (j = i - gap; j >= 0 && array[j] > tmp; j -= gap)
				array[j + gap] = array[j]; /*shift fwd till replacing*/
			array[j + gap] = tmp; /*if no shifting, j=i*/
		}
		print_array(array, size);
		gap = (gap - 1) / 3;
	}
}
