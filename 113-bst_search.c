#include "binary_trees.h"

/**
 * bst_search - afunction that searches for a value in a BST.
 * @tree: a pointer to the root node of the BST to search.
 * @value: the value to search for in the tree.
 *
 * Return: a pointer to the node containing the value, or NULL if not found.
 */
bst_t *bst_search(const bst_t *tree, int value)
{
	if (tree == NULL)
		return (NULL);

	if (value == tree->n)
		return ((bst_t *)tree);

	if (value < tree->n)
		return (bst_search(tree->left, value));
	else
		return (bst_search(tree->right, value));
}
