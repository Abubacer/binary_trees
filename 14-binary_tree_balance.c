#include "binary_trees.h"

/**
 * binary_tree_height - a function that measures the height of a binary tree
 * If tree is NULL, your function must return 0.
 * @tree: a pointer to the root node of the tree to measure the height.
 *
 * Return: the height of the binary tree.
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height, right_height;

	if (tree == NULL)
		return (0);

	if (tree->left == NULL && tree->right == NULL)
		return (1);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);

	else
		return (right_height + 1);
}

/**
 * binary_tree_balance - a function that measures the balance factor
 * of a binary tree
 * If tree is NULL, function must return 0.
 * @tree: a pointer to the root node of the tree to mesure.
 *
 * Return: the balance factor od a binary tree.
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height, right_height;

	if (tree == NULL)
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	return (left_height - right_height);
}
