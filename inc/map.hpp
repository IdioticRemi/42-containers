/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:10:56 by kbarbry           #+#    #+#             */
/*   Updated: 2022/06/17 15:08:26 by kbarbry          ###   ########.fr       */
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
#include "map_iterator.hpp"

namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = std::allocator<ft::pair<const Key,T> > >
	class map
	{
	public:
		typedef Key     									key_type;
		typedef T       									mapped_type;
		typedef ft::pair<const key_type, mapped_type> 		value_type;
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
		typedef typename ft::map_iterator<T>									iterator;
		typedef typename ft::map_iterator<const T>								const_iterator;
		typedef typename ft::reverse_iterator<iterator>							reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator>					const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type			difference_type;
		typedef size_t															size_type;

		map (const key_compare &comp = key_compare(), const allocator_type &alloc = allocator_type()): _alloc(alloc), _tree() {}
		template <class Iter>
		map (Iter first, Iter last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _alloc(alloc), _tree()
		{
			
		}
		map (const map& x)
		{
			
		}
		~map(void) { _tree->clear_tree(); }

		// Iterators
		iterator begin(void)				{ return map_iterator(_tree); }
		const_iterator begin(void) const	{ return map_iterator(_tree); }

		iterator end(void)					{ return map_iterator(_tree, true); }
		const_iterator end(void) const		{ return map_iterator(_tree, true); }

		reverse_iterator		rbegin(void)		{ return reverse_iterator(end()); }
		const_reverse_iterator	rbegin(void) const	{ return const_reverse_iterator(end()); }

		reverse_iterator		rend(void)			{ return reverse_iterator(begin()); }
		const_reverse_iterator	rend(void) const	{ return const_reverse_iterator(begin()); }

		// Capacity
		bool		empty(void) const	{ return _tree->isEmpty() }
		size_type	size(void) const	{ return _tree->getSize(); }
		size_type	max_size() const	{ return _alloc.max_size(); }

		// Element access
		mapped_type	&operator[](const key_type &key)
		{
			
		}

		// Modifiers
		pair<iterator,bool>	insert(const value_type &val)
		{

		}
		iterator			insert(iterator position, const value_type& val)
		{

		}
		template <class Iter>
		void				insert(Iter first, Iter last)
		{

		}

		void		erase(iterator position)
		{
			
		}
		size_type	erase(const key_type &key)
		{
			
		}
		void		erase(iterator first, iterator last)
		{
			
		}

		void	swap(map &x)
		{

		}
		void	clear(void) { _tree.clear_tree(); }

		// Observers
		key_compare		key_comp(void) const
		{
			
		}
		value_compare	value_comp(void) const
		{
			
		}

		// Operations
		iterator		find(const key_type &key)
		{

		}
		const_iterator	find(const key_type &key) const
		{
			
		}

		size_type		count(const key_type &key) const
		{
			
		}

		iterator		lower_bound(const key_type &key)
		{
			
		}
		const_iterator	lower_bound(const key_type& key) const
		{
			
		}
		
		iterator		upper_bound(const key_type &key)
		{

		}
		const_iterator	upper_bound(const key_type &key) const
		{
			
		}

		pair<const_iterator,const_iterator>	equal_range(const key_type &key) const
		{

		}
		pair<iterator,iterator>				equal_range(const key_type &key)
		{

		}

		allocator_type		get_allocator(void) const { return _alloc; }
	private:
		allocator_type							_alloc;
		ft::avl_tree<value_type, Compare>		_tree;
	};
}
