#include "binary_trees.h"

/**
 * binary_tree_depth - a function that measures the depth of a node
 * in a binary tree
 * If tree is NULL, your function must return 0.
 * @tree: a pointer to the root node of the tree to measure the depth.
 *
 * Return: the depth of the binary tree.
 */

size_t binary_tree_depth(const binary_tree_t *tree)
{
	size_t tree_depth;

	tree_depth = 0;

	if (tree == NULL)
		return (0);

	while (tree->parent)
	{
		tree_depth++;
		tree = tree->parent;
	}

	return (tree_depth);
}
