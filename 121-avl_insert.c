#include "binary_trees.h"

/**
 * avl_insert - a function that inserts a value in an AVL Tree.
 * @tree: a double pointer to the root node for inserting the value.
 * @value: the value to store in the node to be inserted.
 *
 * Return: a pointer to the created node, or NULL on failure.
 */
avl_t *avl_insert(avl_t **tree, int value)
{
	avl_t *new_node, *parent, *current;

	new_node = binary_tree_node(NULL, value);

	if (tree == NULL || new_node == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = new_node;
		return (new_node);
	}
	parent = *tree;
	current = *tree;
	while (current != NULL)
	{
		if (value < current->n)
		{
			parent = current;
			current = current->left;
		}
		else if (value > current->n)
		{
			parent = current;
			current = current->right;
		}
		else
		{
			free(new_node);
			return (NULL);
		}
	}
	if (value < parent->n)
		parent->left = new_node;
	else
		parent->right = new_node;

	new_node->parent = parent;
	balance_avl_tree(new_node);
	return (new_node);
}
/**
 * balance_avl_tree - a function that balances an AVL Tree after insertion.
 * @node: a pointer to the root node of the AVL tree.
 *
 * Return: a pointer to the new root node after balancing.
 */
avl_t *balance_avl_tree(avl_t *node)
{
	int balance_factor;

	balance_factor = binary_tree_balance(node);

	if (balance_factor > 1)
	{
		if (binary_tree_balance(node->left) < 0)
			node = binary_tree_rotate_left(node->left);

		node = binary_tree_rotate_right(node);
	}
	else if (balance_factor < -1)
	{
		if (binary_tree_balance(node->right) > 0)
			node = binary_tree_rotate_right(node->right);

		node = binary_tree_rotate_left(node);
	}

	return (node);
}
