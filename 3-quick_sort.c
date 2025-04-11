#include "sort.h"
#include <stddef.h>

/**
 * swap - Intercambia dos números en un array si son diferentes.
 * @a: Primer número.
 * @b: Segundo número.
 * Return: 1 si hubo intercambio, 0 si los valores son iguales.
 */
static int swap(int *a, int *b)
{
	int tmp;

	if (*a == *b)
		return (0);

	tmp = *a;
	*a = *b;
	*b = tmp;

	return (1);
}

/**
 * partition - Implementa el esquema de partición de Lomuto.
 * @array: Array a ordenar.
 * @low: Índice inicial.
 * @high: Índice final.
 * @size: Tamaño del array.
 * Return: Índice de la partición.
 */
static int partition(int *array, int low, int high, size_t size)
{
	int pivot_val, i, j;

	pivot_val = array[high];
	i = low - 1;

	for (j = low; j < high; j++)
	{
		if (array[j] < pivot_val)
		{
			i++;
			if (swap(&array[i], &array[j]))
				print_array(array, size);
		}
	}

	i++;
	if (swap(&array[i], &array[high]))
		print_array(array, size);

	return (i);
}

/**
 * quicksort_helper - Función auxiliar recursiva para Quick Sort.
 * @array: Array a ordenar.
 * @low: Índice inicial.
 * @high: Índice final.
 * @size: Tamaño del array.
 */
static void quicksort_helper(int *array, int low, int high, size_t size)
{
	if (low < high)
	{
		int pi;

		pi = partition(array, low, high, size);

		quicksort_helper(array, low, pi - 1, size);
		quicksort_helper(array, pi + 1, high, size);
	}
}

/**
 * quick_sort - Ordena un array usando el algoritmo Quick Sort.
 * @array: Array a ordenar.
 * @size: Tamaño del array.
 */
void quick_sort(int *array, size_t size)
{
	if (array == NULL || size < 2)
		return;

	quicksort_helper(array, 0, size - 1, size);
}
