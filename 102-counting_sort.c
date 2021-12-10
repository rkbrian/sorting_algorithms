#include "sort.h"

/**
 * counting_sort - lgorithm to sort numbers with counting sort method
 * @array: unsorted array, minimum value 0
 * @size: size of array
 */
void counting_sort(int *array, size_t size)
{
	int *count_arr = NULL, len = (int)size;
	int i, j = 0, k = 0, zero_flag = 0;

	for (i = 0; i < len; i++)
	{
		if (k < array[i])
			k = array[i];
		if (array[i] == 0) /* min=0 conflict with init 0 */
			zero_flag = 1;
	}
	count_arr = (int *)malloc(sizeof(int) * (k + 1));
	if (count_arr == NULL)
		return;
	for (i = 0; i < k + 1; i++) /* init counting array */
		count_arr[i] = 0;
	for (i = 0; i < len; i++)
	{
		if (array[i] != 0)
			count_arr[array[i] - 1] = array[i];
	}
	if (zero_flag) /* to control j the iteration before next ordered value */
		array[j] = 0, j++, zero_flag = 0;
	for (i = 0; i < k + 1; i++)
	{
		if (i > 0)
			printf(", ");
		printf("%d", j);
		if (count_arr[i] > 0)
			array[j] = count_arr[i], j++;
	}
	printf("\n");
	if (count_arr)
		free(count_arr);
}
