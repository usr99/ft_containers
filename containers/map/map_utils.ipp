/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_utils.ipp                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/08 15:48:16 by mamartin          #+#    #+#             */
/*   Updated: 2021/09/08 18:43:50 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "map.hpp"

namespace ft
{
	template <class Key, class T, class Compare, class Alloc>
	pair<typename map<Key, T, Compare, Alloc>::iterator, bool>
	map<Key, T, Compare, Alloc>::_insert(btree *root, const value_type &val)
	{
		pair<iterator, bool> ret;

		// insert
		if (_key_comp(val.first, root->data.first))
		{
			if (root->left && root->left != _end)
			{
				ret = _insert(root->left, val);
				if (ret.second == false)
					return (ret);
			}
			else
			{
				root->left = _create_node(btree(root, val)); // create node
				ret = make_pair(iterator(root->left), true);
			}
			if (!_is_balanced(root))
			{
				if (_key_comp(val.first, root->left->data.first))
					root = _rotate_right(root);
				else
					root = _rotate_left_right(root);
			}
		}
		else if (_key_comp(root->data.first, val.first))
		{
			if (root->right && root->right != _end)
			{
				ret = _insert(root->right, val);
				if (ret.second == false)
					return (ret);
			}
			else
			{
				root->right = _create_node(btree(root, val)); // create node
				ret = make_pair(iterator(root->right), true);
			}
			if (!_is_balanced(root))
			{
				if (_key_comp(root->right->data.first, val.first))
					root = _rotate_left(root);
				else
					root = _rotate_right_left(root);
			}
		}
		else
			return (make_pair(iterator(root), false));

		return (ret);
	}

	template <class Key, class T, class Compare, class Alloc>
	void
	map<Key, T, Compare, Alloc>::_append_end_node(btree *node)
	{
		node->right = _end;
		_end->parent = node;
		_end->right = node;
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::btree*
	map<Key, T, Compare, Alloc>::_create_node(const btree &val)
	{
		btree *node;
		node = node_alloc(_alloc).allocate(1);
		node_alloc(_alloc).construct(node, val);
		return (node);
	}

	template <class Key, class T, class Compare, class Alloc>
	bool
	map<Key, T, Compare, Alloc>::_is_balanced(btree *node) const
	{
		int balance = node->balance_factor();

		if (balance < -1 || balance > 1)
			return (false);
		return (true);
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::btree*
	map<Key, T, Compare, Alloc>::_rotate_left(btree *root)
	{
		btree *pivot = root->right;

		root->right = pivot->left;
		if (pivot->left)
			pivot->left->parent = root;

		pivot->left = root;
		pivot->parent = root->parent;
		root->parent = pivot;

		if (pivot->parent)
		{
			if (pivot->parent->left == root)
				pivot->parent->left = pivot;
			else if (pivot->parent->right == root)
				pivot->parent->right = pivot;
		}
		else
			_root = pivot;

		root->balance_factor();
		root = pivot;
		return (root);
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::btree*
	map<Key, T, Compare, Alloc>::_rotate_right(btree *root)
	{
		btree *pivot = root->left;

		root->left = pivot->right;
		if (pivot->right)
			pivot->right->parent = root;

		pivot->right = root;
		pivot->parent = root->parent;
		root->parent = pivot;

		if (pivot->parent)
		{
			if (pivot->parent->left == root)
				pivot->parent->left = pivot;
			else if (pivot->parent->right == root)
				pivot->parent->right = pivot;
		}
		else
			_root = pivot;

		root->balance_factor();
		root = pivot;
		return (root);
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::btree*
	map<Key, T, Compare, Alloc>::_rotate_left_right(btree *root)
	{
		_rotate_left(root->left);
		root = _rotate_right(root);
		return (root);
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::btree*
	map<Key, T, Compare, Alloc>::_rotate_right_left(btree *root)
	{
		_rotate_right(root->right);
		root = _rotate_left(root);
		return (root);
	}

	template <class Key, class T, class Compare, class Alloc>
	typename map<Key, T, Compare, Alloc>::btree*
	map<Key, T, Compare, Alloc>::_find(btree *root, const key_type &k) const
	{
		if (!root || root == _end)
			return (_end);

		if (_key_comp(k, root->data.first))
			return _find(root->left, k);
		else if (_key_comp(root->data.first, k))
			return _find(root->right, k);
		else
			return (root);
	}

	template <class Key, class T, class Compare, class Alloc>
	void
	map<Key, T, Compare, Alloc>::_erase(btree *node)
	{
		btree *tmp = node;
		btree *child;

		if (!node->left && !node->right) // no child
		{
			node = node->parent; // save starting node for later rebalancing
			if (node->left == tmp)
				node->left = NULL;
			else
				node->right = NULL;
		}
		else if (node->left && node->right) // 2 children
		{
			// find infix successor
			if (node->balance_factor() == 1)
			{
				child = node->right;
				while (child->left)
					child = child->left;

				// infix node takes node's children
				child->left = node->left;
				node->left->parent = child;
				if (child->right && child->parent != node)
				{
					child->parent->left = child->right;
					child->right->parent = child->parent;
				}
				else
					child->parent->left = NULL; // removes infix node from his parent

				if (child != node->right)
				{
					child->right = node->right;
					node->right->parent = child;
				}
			}
			else // find infix predecessor
			{
				child = node->left;
				while (child->right)
					child = child->right;

				// infix node takes node's children
				child->right = node->right;
				node->right->parent = child;

				if (child->left && child->parent != node)
				{
					child->parent->right = child->left;
					child->left->parent = child->parent;
				}
				else
					child->parent->right = NULL; // removes infix node from his parent

				if (child != node->left)
				{
					child->left = node->left;
					node->left->parent = child;
				}
			}

			// node's parent now points to child
			_replace_node(node, child);

			// save starting node for later rebalancing
			if (child->parent != node)
				node = child->parent;
			else
				node = child;
			// infix node's parent is now node's parent
			child->parent = tmp->parent;
		}
		else // 1 child
		{
			if (node->left)
				child = node->left;
			else
				child = node->right;

			// node's parent now points to child
			_replace_node(node, child);

			node = node->parent; // save starting node for later rebalancing
		}

		// tree rotations in case of imbalance
		_rebalance(node);

		// in case of root deletion
		if (tmp == _root)
			_root = child;

		// destroy node
		node_alloc(_alloc).destroy(tmp);
		node_alloc(_alloc).deallocate(tmp, 1);
	}

	template <class Key, class T, class Compare, class Alloc>
	void
	map<Key, T, Compare, Alloc>::_rebalance(btree *node)
	{
		while (node) // X node (see https://en.wikipedia.org/wiki/AVL_tree#Rebalancing)
		{
			int balance = node->balance_factor();

			if (balance > 1) // Z is right child
			{
				balance = node->right->balance_factor();
				if (balance >= 0)
					_rotate_left(node);
				else if (balance < 0)
					_rotate_right_left(node);
			}
			else if (balance < -1) // Z is left child
			{
				balance = node->left->balance_factor();
				if (balance <= 0)
					_rotate_right(node);
				else if (balance > 0)
					_rotate_left_right(node);
			}
			node = node->parent; // next node
		}
	}

	template <class Key, class T, class Compare, class Alloc>
	void
	map<Key, T, Compare, Alloc>::_replace_node(btree *node, btree *child)
	{
		if (node->parent)
		{
			// make node's parent point to child
			if (node->parent->left == node) // node is a left child
				node->parent->left = child;
			else							// node is a right child
				node->parent->right = child;
		}		
	}

	template <class Key, class T, class Compare, class Alloc>
	void
	map<Key, T, Compare, Alloc>::_clear(btree *root)
	{
		if (!root)
			return;

		_clear(root->left);
		_clear(root->right);

		node_alloc(_alloc).destroy(root);
		node_alloc(_alloc).deallocate(root, 1);
	}
}