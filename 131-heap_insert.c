#include "binary_trees.h"

/**
 * heap_insert - a function that inserts a value into a Max Binary Heap.
 * @root: a double pointer to the root node of the Heap to insert the value.
 * @value: the value to store in the node to be inserted.
 *
 * Return: a pointer to the created node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node, *parent;
	size_t size;
	int swap_value_ok = 1;

	if (root == NULL)
		return (NULL);

	if (*root == NULL)
	{
		new_node = binary_tree_node(NULL, value);
		*root = new_node;
		return (new_node);
	}

	size = bt_size(*root);
	parent = heap_find_parent(*root, (size - 1) / 2);
	new_node = binary_tree_node(parent, value);

	if (size % 2 == 1)
		parent->left = new_node;
	else
		parent->right = new_node;

	if (new_node == NULL)
		return (NULL);

	while (swap_value_ok == 1 && parent != NULL)
	{
		if (parent->n >= new_node->n)
			swap_value_ok = 0;
		else
		{
			new_node = swap_values(new_node, parent);
			parent = new_node->parent;
		}
	}

	return (new_node);
}
/**
 * heap_find_parent - finds the parent node for insertion.
 * @root: a pointer to the root node of the heap.
 * @idx: the index of the node to find.
 *
 * Return: a pointer to the parent node.
 */
heap_t *heap_find_parent(heap_t *root, size_t idx)
{
	heap_t *parent;
	size_t child_index;

	if (idx == 0)
		return (root);

	parent = heap_find_parent(root, (idx - 1) / 2);
	child_index = (idx - 1) % 2;

	if (child_index == 0)
		return (parent->left);
	return (parent->right);
}

/**
 * bt_size - a function that measures the size of a binary tree
 * If tree is NULL, your function must return 0.
 * @tree: a pointer to the root node of the tree to measure the height.
 *
 * Return: the size of the binary tree.
 */

size_t bt_size(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);

	return (1 + bt_size(tree->left) + bt_size(tree->right));
}

/**
 * swap_values - swaps two integer values.
 * @new: a pointer to the first value.
 * @parent: a pointer to the second value.
 */
heap_t *swap_values(heap_t *new, heap_t *parent)
{
	int tmp;

	tmp = new->n;
	new->n = parent->n;
	parent->n = tmp;

	return (parent);
}
