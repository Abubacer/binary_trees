#include "binary_trees.h"

/**
 * binary_tree_is_complete - checks if a binary tree is complete.
 * If tree is NULL, function must return 0.
 * @tree: a pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is complete, 0 otherwise.
 */

int binary_tree_is_complete(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_complete(tree, 0, binary_tree_size(tree)));
}

/**
 * is_complete - a recursive helper function to check completeness.
 * @node: the current node being checked.
 * @idx: the index of the current node.
 * @size: the number of nodes in the tree.
 *
 * Return: 1 if the subtree rooted at node is complete, 0 otherwise.
 */

int is_complete(const binary_tree_t *node, int idx, int size)
{

	if (node == NULL)
		return (1);

	if (idx >= size)
		return (0);

	return (is_complete(node->left, 2 * idx + 1, size) &&
		is_complete(node->right, 2 * idx + 2, size));
}

/**
 * binary_tree_size - a function that measures the size of a binary tree
 * If tree is NULL, your function must return 0.
 * @tree: a pointer to the root node of the tree to measure the size.
 *
 * Return: the size of the binary tree.
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t left_size, right_size;

	if (tree == NULL)
		return (0);

	left_size = binary_tree_size(tree->left);
	right_size = binary_tree_size(tree->right);

	return (left_size + right_size + 1);
}
