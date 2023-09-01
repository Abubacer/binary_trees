#include "binary_trees.h"

/**
 * array_to_heap - builds a Max Binary Heap tree from an array.
 * @array: a pointer to the first element of the array to be converted.
 * @size: the number of elements in the array.
 *
 * Return: a pointer to the root node, or NULL on failure.
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *root;
	size_t i;

	if (array == NULL || size == 0)
		return (NULL);

	root = NULL;

	for (i = 0; i < size; i++)
	{
		heap_insert(&root, array[i]);
	}

	return (root);
}
