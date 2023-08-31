#include "binary_trees.h"

/**
 * binary_tree_is_avl - a function that checks if a binary tree is
 * a valid AVL. Properties of an AVL Tree:
 * An AVL Tree is a BST.
 * The difference between heights of left and right subtrees cannot
 * be more than one
 * The left and right subtrees must also be AVL trees.
 * @tree: a pointer to the root node of the tree to check.
 *
 * Return: 1 if the tree is a valid AVL, 0 otherwise.
 */
int binary_tree_is_avl(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (is_valid_avl(tree, NULL, NULL));
}

/**
 * is_valid_avl - a recursive function to check if a tree is a valid AVL.
 * @node: the current node being checked.
 * @min: the minimum value constraint for the node.
 * @max: the maximum value constraint for the node.
 *
 * Return: 1 if the subtree rooted at node is a valid BST, 0 otherwise.
 */
int is_valid_avl(const binary_tree_t *node, const int *min, const int *max)
{
	int left_height, right_height;

	if (node == NULL)
		return (1);

	if ((min && node->n <= *min) || (max && node->n >= *max))
		return (0);

	left_height = binary_tree_height(node->left);
	right_height = binary_tree_height(node->right);

	if (abs(left_height - right_height) > 1)
		return (0);

	return ((is_valid_avl(node->left, min, &node->n) &&
		is_valid_avl(node->right, &node->n, max)));
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

	if (tree == NULL || (tree->left == NULL && tree->right == NULL))
		return (0);

	left_height = binary_tree_height(tree->left);
	right_height = binary_tree_height(tree->right);

	if (left_height > right_height)
		return (left_height + 1);

	else
		return (right_height + 1);
}
