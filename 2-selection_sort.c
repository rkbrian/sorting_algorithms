#include "sort.h"

/**
 * selection_sort - algorithm to sort numbers with selection sort method
 * @array: unsorted array
 * @size: size of array
 */
void selection_sort(int *array, size_t size)
{
	size_t i, j, winner;
	int hall_of_fame;

	if (array == NULL || size <= 1)
		return;
	for (i = 0; i < size - 1; i++)
	{
		hall_of_fame = array[i];
		for (j = i + 1; j < size; j++)
		{
			if (hall_of_fame > array[j])
				hall_of_fame = array[j], winner = j;
		}
		if  (hall_of_fame != array[i])
		{
			array[winner] = array[i];
			array[i] = hall_of_fame;
			print_array(array, size);
		}
	}
}
