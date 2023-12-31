#include "binary_trees.h"

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
 * binary_tree_is_perfect - checks if a binary tree is perfect.
 * If tree is NULL, function must return 0.
 * @tree: a pointer to the root node of the tree to checks.
 *
 * Return: 1 if the binary tree is perfect, and 0 otherwise.
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	size_t get_height, nodes_numbers;

	if (tree == NULL)
		return (0);

	get_height = binary_tree_height(tree);
	nodes_numbers = (1 << get_height) - 1;

	return (binary_tree_size(tree) == nodes_numbers);
}
