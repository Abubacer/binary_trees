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
	if (tree == NULL)
		return (NULL);

	*tree = insert_value(*tree, value);

	if (*tree == NULL)
		return (NULL);

    return (balance_tree(*tree));
}

/**
 * insert_recursive - Recursive function to insert a value in an AVL Tree.
 * @root: Pointer to the current root node of the tree.
 * @value: The value to insert.
 *
 * Return: Pointer to the new root node of the tree after insertion.
 */
avl_t *insert_recursive(avl_t *root, int value)
{
    if (root == NULL)
        return avl_node_create(value);

    if (value < root->n)
        root->left = insert_recursive(root->left, value);
    else if (value > root->n)
        root->right = insert_recursive(root->right, value);
    else
        return root; // Duplicate values are not allowed

    root->height = 1 + MAX(height(root->left), height(root->right));

    return root;
}

/**
 * balance_factor - Calculates the balance factor of a node.
 * @node: Pointer to the node to calculate balance factor for.
 *
 * Return: Balance factor of the node.
 */
int balance_factor(const avl_t *node)
{
    if (node == NULL)
        return 0;

    return height(node->left) - height(node->right);
}

/**
 * balance_tree - Balances an AVL Tree after insertion.
 * @root: Pointer to the root node of the tree to balance.
 *
 * Return: Pointer to the new root node of the balanced tree.
 */
avl_t *balance_tree(avl_t *root)
{
    int bf;

    if (root == NULL)
        return NULL;

    bf = balance_factor(root);

    // Left-Left case
    if (bf > 1 && root->left != NULL && balance_factor(root->left) >= 0)
        return binary_tree_rotate_right(root);

    // Left-Right case
    if (bf > 1 && root->left != NULL && balance_factor(root->left) < 0)
    {
        root->left = binary_tree_rotate_left(root->left);
        return binary_tree_rotate_right(root);
    }

    // Right-Right case
    if (bf < -1 && root->right != NULL && balance_factor(root->right) <= 0)
        return binary_tree_rotate_left(root);

    // Right-Left case
    if (bf < -1 && root->right != NULL && balance_factor(root->right) > 0)
    {
        root->right = binary_tree_rotate_right(root->right);
        return binary_tree_rotate_left(root);
    }

    return root;
}

/**
 * height - Calculates the height of a node.
 * @node: Pointer to the node to calculate the height for.
 *
 * Return: Height of the node.
 */
size_t height(const avl_t *node)
{
    if (node == NULL)
        return 0;

    return node->height;
}

