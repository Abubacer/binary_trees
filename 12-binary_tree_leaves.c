#include "binary_trees.h"

/**
 * binary_tree_leaves - a function that counts the leaves in binary tree.
 * If tree is NULL, function must return 0.
 * A NULL pointer is not a leaf.
 * @tree: a pointer to the root node of the tree to count the leaves.
 *
 * Return: the number of leaves in the binary tree.
 */

size_t binary_tree_leaves(const binary_tree_t *tree)
{
	size_t left_leaves, right_leaves;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	left_leaves = binary_tree_leaves(tree->left);
	right_leaves = binary_tree_leaves(tree->right);

	return (left_leaves + right_leaves);
}
