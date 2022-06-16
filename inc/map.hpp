/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:10:56 by kbarbry           #+#    #+#             */
/*   Updated: 2022/06/15 12:35:13 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>
#include <iostream>
#include <algorithm>

#include "reverse_iterator.hpp"
#include "pair.hpp"
#include "iterator_utils.hpp"
#include "avl_tree.hpp"

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map
	{
	public:
		typedef Key     									key_type;
		typedef T       									mapped_type;
		typedef ft::pair<key_type, mapped_type> 			value_type;
		typedef Compare     								key_compare;
		class												value_compare
		{
		protected:
			Compare cmp;
			value_compare (Compare c) : cmp(c) {}
		public:
			bool operator()(const T &x, const T &y) const { return cmp(x, y); }
		};
		typedef Alloc															allocator_type;
		typedef typename allocator_type::reference								reference;
		typedef typename allocator_type::const_reference						const_reference;
		typedef typename allocator_type::pointer								pointer;
		typedef typename allocator_type::const_pointer							const_pointer;
		typedef typename ft::avl_tree<value_type, key_compare>::iterator		iterator;
		typedef typename ft::avl_tree<value_type, key_compare>::const_iterator	const_iterator;
		typedef typename ft::reverse_iterator<iterator>							reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>					const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type			difference_type;
		typedef size_t															size_type;

		explicit map (const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()): _alloc(alloc), _tree() {}
		template <class Iter>
		map (Iter first, Iter last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _alloc(alloc), _tree()
		{
			
		}

	private:
		allocator_type							_alloc;
		ft::avl_tree<value_type, Compare>		_tree;
	};
}
