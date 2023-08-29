#include "binary_trees.h"

/**
 * binary_tree_nodes - a function that counts the nodes
 * with at least 1 child in a binary tree.
 * If tree is NULL, function must return 0.
 * A NULL pointer is not a node.
 * @tree: a pointer to the root node of the tree to count the nodes.
 *
 * Return: the number of nodes in the binary tree.
 */

size_t binary_tree_nodes(const binary_tree_t *tree)
{
	size_t left_nodes, right_nodes;

	if (tree == NULL)
		return (0);

	left_nodes = binary_tree_nodes(tree->left);
	right_nodes = binary_tree_nodes(tree->right);

	if (tree->left != NULL || tree->right != NULL)
		return (left_nodes + right_nodes + 1);

	else
		return (left_nodes + right_nodes);
}
