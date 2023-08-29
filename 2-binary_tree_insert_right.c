#include "binary_trees.h"

/**
 * binary_tree_insert_right - a function that inserts a node
 * as the right child of another node.
 * If parent already has a right child, the new node must take its place
 * and the old right-child must be set as the right-child of the new node.
 * @parent: a pointer to the node to insert the right child in.
 * @value: the value to store in the new node.
 *
 * Return: a pointer to the new node.
 *         otherwise NULL on failure or if parent is NULL.
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_node;

	new_node = binary_tree_node(parent, value);

	if (parent == NULL)
		return (NULL);

	if (parent->right != NULL)
	{
		new_node->right = parent->right;
		parent->right->parent = new_node;
	}

	parent->right = new_node;

	return (new_node);
}
