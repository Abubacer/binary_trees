#include "binary_trees.h"

/**
 * binary_tree_is_bst - a function that checks if a binary tree is
 * a valid BST. Properties of a Binary Search Tree:
 * The left subtree of a node contains only nodes with values less than
 * the node’s value.
 * The right subtree of  a node contains only nodes  with values greater
 * than the node’s value.
 * The left and right subtree each must also be a binary search tree.
 * There must be no duplicate values.
 * @tree: a pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid BST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	return (is_valid_bst(tree, NULL, NULL));
}

/**
 * is_valid_bst - a recursive function to check if a tree is a valid BST.
 * @node: the current node being checked.
 * @min: the minimum value constraint for the node.
 * @max: the maximum value constraint for the node.
 *
 * Return: 1 if the subtree rooted at node is a valid BST, 0 otherwise.
 */
int is_valid_bst(const binary_tree_t *node, const int *min, const int *max)
{
	if (node == NULL)
		return (1);

	if ((min && node->n <= *min) || (max && node->n >= *max))
		return (0);

	return ((is_valid_bst(node->left, min, &node->n) &&
		is_valid_bst(node->right, &node->n, max)));
}
