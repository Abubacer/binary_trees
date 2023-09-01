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
	avl_t *new_node, *predecessor;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		new_node = binary_tree_node(NULL, value);
		*tree = new_node;
		return (new_node);
	}

	new_node = recursive_avl_insert(*tree, NULL, value);

	if (new_node == NULL)
		return (NULL);

	predecessor = new_node->parent;

	while (predecessor != NULL)
	{
		avl_tree_rebalance(tree, predecessor, value);
		predecessor = predecessor->parent;
	}

	return (new_node);
}

/**
 * avl_tree_rebalance - rebalances an AVL Tree after insertion.
 * @root: a double pointer to the root of AVL tree.
 * @tree: a pointer to the root node of the AVL tree to balance.
 * @value: the value to store in the node to be inserted.
 *
 * Return: 0 on success.
 */
avl_t *avl_tree_rebalance(avl_t **root, avl_t *tree, int value)
{
	int balance_factor;

	balance_factor = binary_tree_balance(tree);

	if (balance_factor > 1)
	{
		if (tree->left->n > value)
		{
			if (*root == tree)
				*root = tree->left;
			binary_tree_rotate_right(tree);
		}
		else
		{
			if (*root == tree)
				*root = tree->left->right;
			binary_tree_rotate_left(tree->left);
			binary_tree_rotate_right(tree);
		}
	}
	else if (balance_factor < -1)
	{
		if (tree->right->n < value)
		{
			if (*root == tree)
				*root = tree->right;
			binary_tree_rotate_left(tree);
		}
		else
		{
			if (*root == tree)
				*root = tree->right->left;
			binary_tree_rotate_right(tree->right);
			binary_tree_rotate_left(tree);
		}
	}
}

/**
 * recursive_avl_insert - a recursive function that inserts a value in an AVl.
 * @tree: a double pointer to the root node for inserting the value.
 * @parent: a pointer to the parent of node.
 * @value: the value to store in the node to be inserted.
 *
 * Return: a pointer to the created node, or NULL on failure.
 */

avl_t *recursive_avl_insert(avl_t *tree, avl_t *parent, int value)
{
	avl_t *new_node;

	if (tree == NULL)
	{
		new_node = binary_tree_node(parent, value);

		if (parent->n > new_node->n)
			parent->left = new_node;
		else
			parent->right = new_node;

		return (new_node);
	}
	else if (value == tree->n)
		return (NULL);

	else if (value < tree->n)
		return (recursive_avl_insert(tree->left, tree, value));
	else
		return (recursive_avl_insert(tree->right, tree, value));
}
