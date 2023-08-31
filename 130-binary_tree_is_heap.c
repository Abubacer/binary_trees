#include "binary_trees.h"

/**
 * binary_tree_is_heap - afunction that checks if a binary tree is a valid
 * Max Binary Heap. Properties of a Max Binary Heap:
 * It’s a complete tree.
 * In a Max Binary Heap, the value at root must be maximum among
 * all values present in Binary Heap.
 * The last property must be recursively true for all nodes in Binary Tree.
 * @tree: A pointer to the root node of the tree to check.
 *
 * Return: 1 if tree is a valid Max Binary Heap, 0 otherwise.
 *         If tree is NULL, return 0.
 */
int binary_tree_is_heap(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	if (tree->left != NULL && tree->left->n > tree->n)
		return (0);

	if (tree->right != NULL && tree->right->n > tree->n)
		return (0);

	if (!binary_tree_is_heap(tree->left) ||
				!binary_tree_is_heap(tree->right))
		return (0);

	return (1);
}

