/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   node.hpp                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mamartin <mamartin@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/18 18:50:19 by mamartin          #+#    #+#             */
/*   Updated: 2021/06/18 21:57:11 by mamartin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef NODE_HPP
# define NODE_HPP

namespace ft
{
	// node structure for ft::list =============================================
	template <class T>
	struct listNode
	{

		listNode();
		listNode(listNode *prev, listNode *next);
		listNode(const T& val, listNode *prev, listNode *next);
		listNode(const listNode& rhs);
		
		listNode&	operator=(const listNode& rhs);
		
		T			data;
		listNode	*prev;
		listNode	*next;
	};
	// =========================================================================
}

# include "node.ipp"

#endif
