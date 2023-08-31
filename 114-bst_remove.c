#include "binary_trees.h"

/**
 * bst_remove - a function that removes a node from a Binary Search Tree.
 * Once located, the node containing a value equals to value must be
 * removed and freed.
 * If the node to be deleted has two children, it must be replaced with
 * its first in-order successor.
 * @root: the root node of the tree where the node will be removed.
 * @value: The value to remove in the tree.
 *
 * Return: Pointer to the new root node of the tree after removing the value.
 */
bst_t *bst_remove(bst_t *root, int value)
{
	bst_t *tmp, *successor_node;

	if (root == NULL)
		return (NULL);

	if (value < root->n)
		root->left = bst_remove(root->left, value);
	else if (value > root->n)
		root->right = bst_remove(root->right, value);
	else
	{
		if (root->left == NULL)
		{
			tmp = root->right;
			free(root);
			return (tmp);
		}

		else if (root->right == NULL)
		{
			tmp = root->left;
			free(root);
			return (tmp);
		}

		successor_node = bst_minval_node(root->right);
		root->n = successor_node->n;
		root->right = bst_remove(root->right, successor_node->n);
	}

	return (root);
}

/**
 * bst_minval_node - returns the node with the minimum value in a BST.
 * @node: a pointer to the root node of the tree.
 *
 * Return: a pointer to the node with the minimum value.
 */
bst_t *bst_minval_node(bst_t *node)
{
	bst_t *current_node = node;

	while (current_node->left)
		current_node = current_node->left;

	return (current_node);
}
