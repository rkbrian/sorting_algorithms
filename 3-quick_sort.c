#include "sort.h"

/**
 * quick_sort - algorithm to sort numbers with quick sort method
 * @array: unsorted array
 * @size: size of array
 */
void quick_sort(int *array, size_t size)
{
	size_t i, j, k = -1, tmp, batman = 0, robin = 0;
	int judge, jury, executioner;

	if (array == NULL || size <= 1)
		return;
	for (i = 0; i < size; i++)
		batman = batman + i;
	for (i = 0; i < size; i++)
	{
		judge = array[i];
		for (j = size - 1; array[j] != judge; j = j + k)
		{
			jury = array[j];
			if (judge > jury)
			{
				array[i] = jury, array[j] = judge;
				tmp = i, i = j; j = tmp;
				k = k * (-1);
				judge = array[i];
			}
		else if (judge == jury)
		{
			executioner = judge, robin = robin + i;
			i++;
			break;
		}
		if (judge == executioner)
			i++;
	}
}
