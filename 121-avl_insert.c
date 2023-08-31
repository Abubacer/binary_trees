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
	avl_t *new_node;

	if (tree == NULL)
		return (NULL);

	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}

	if (value == (*tree)->n)
		return (NULL);

	if (value < (*tree)->n)
	{
		new_node = avl_insert(&((*tree)->left), value);

		if (new_node == NULL)
			return (NULL);

		(*tree)->left = new_node;
	}
	else
	{
		new_node = avl_insert(&((*tree)->right), value);

		if (new_node == NULL)
			return (NULL);

		(*tree)->right = new_node;
	}

	return (balance_avl_tree(*tree));
}

/**
 * balance_avl_tree - a function that balances an AVL Tree after insertion.
 * @tree: a pointer to the root node of the AVL tree.
 *
 * Return: a pointer to the new root node after balancing.
 */
avl_t *balance_avl_tree(avl_t *tree)
{
	int balance_factor;

	balance_factor = binary_tree_balance(tree);

	if (balance_factor > 1)
	{
		if (binary_tree_balance(tree->left) >= 0)
			return (binary_tree_rotate_right(tree));

		else
		{
			tree->left = binary_tree_rotate_left(tree->left);
			return (binary_tree_rotate_right(tree));
		}
	}
	if (balance_factor < -1)
	{
		if (binary_tree_balance(tree->right) <= 0)
			return (binary_tree_rotate_left(tree));

		else
		{
			tree->right = binary_tree_rotate_right(tree->right);
			return (binary_tree_rotate_left(tree));
		}
	}

	return (tree);
}
