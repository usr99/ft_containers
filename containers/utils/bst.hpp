/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bst.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/07/09 02:16:09 by mamartin          #+#    #+#             */
/*   Updated: 2021/09/06 22:01:29 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BST_HPP
# define BST_HPP

# include "sort.hpp"
# include "../stack/stack.hpp"

namespace ft
{
	template <class T>
	class avl_tree
	{
		public:

			avl_tree(const T& val = T()) :
				parent(NULL), left(NULL), right(NULL), depth(1), data(val) {}

			avl_tree(avl_tree *parent, const T& val = T()) :
				parent(parent), left(NULL), right(NULL), depth(1), data(val) {}

			int balance_factor()
			{
				int left_depth	= 0;
				int right_depth	= 0;

				// refresh depth
				if (left)
					left_depth = left->depth;
				if (right)
					right_depth = right->depth;
				depth = max(left_depth, right_depth) + 1;

				return (right_depth - left_depth);
			}

			avl_tree	*parent;
			avl_tree	*left;
			avl_tree	*right;
			int			depth;
			T			data;
	};
}

#endif
