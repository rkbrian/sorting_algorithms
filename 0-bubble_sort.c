#include "sort.h"

/**
 * bubble_sort - algorithm to sort numbers with bubble sort method
 * @array: unsorted array
 * @size: size of array
 */
void bubble_sort(int *array, size_t size)
{
	size_t i, j;
	int tmp, need_more_sort_flag;

	for (i = 0; i < size - 1; i++)
	{
		need_more_sort_flag = 0;
		for (j = 0; j < size - 1 - i; j++)
		{
			if (array[j] > array[j + 1])
			{
				tmp = array[j];
				array[j] = array[j + 1];
				array[j + 1] = tmp;
				need_more_sort_flag = 1;
				print_array(array, size);
			}
		}
		if (need_more_sort_flag == 0)
			break;
	}
}
