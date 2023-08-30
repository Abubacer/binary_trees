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

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);

	else
		return (right_height + 1);
}

/**
 * print_levelorder - a function that prints each node level order.
 * If tree or func is NULL, do nothing.
 * @tree: a pointer to the root node of the tree to print.
 * @levelorder: level order of the tree.
 * @func: a pointer to a function to call for each node.
 *
 * Return: void.
 */

void print_levelorder(const binary_tree_t *tree, int levelorder,
						void (*func)(int))
{
	if (tree == NULL)
		return;

	if (levelorder == 1)
		func(tree->n);

	else if (levelorder > 1)
	{
		print_levelorder(tree->left, levelorder - 1, func);
		print_levelorder(tree->right, levelorder - 1, func);
	}
}


/**
 * binary_tree_levelorder - a function that goes through a binary tree
 * using level-order traversal
 * If tree or func is NULL, do nothing.
 * @tree: a pointer to the root node of the tree to traverse.
 * @func: a pointer to a function to call for each node.
 * The value in the node must be passed as a parameter to this function.
 *
 * Return: void.
 */

void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int));
{
	int tree_hight, tree_len;

	tree_hight = 0;
	tree_len = 1;

	if (tree == NULL || func == NULL)
		return;

	tree_hight = binary_tree_height(tree) + 1;

	while (tree_len <= tree_height)
	{
		print_levelorder(tree, tree_len, func);
		tree_len++;
	}
}
