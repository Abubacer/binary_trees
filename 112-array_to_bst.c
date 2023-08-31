#include "binary_trees.h"

/**
 * array_to_bst - a function that builds a BS Tree from an array.
 * If a value of the array is already present in the tree, this value
 * must be ignored.
 * @array: a pointer to the first element of the array to be converted.
 * @size: the number of elements in the array.
 *
 * Return: a pointer to the root node of the created BST.
 *         or NULL on failure.
 */
bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *root_node = NULL;
	size_t i;

	if (array == NULL || size == 0)
		return (NULL);

	for (i = 0; i < size; i++)
		bst_insert(&root_node, array[i]);

	return (root_node);
}
