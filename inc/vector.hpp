/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector.hpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:11:06 by kbarbry           #+#    #+#             */
/*   Updated: 2022/06/20 18:51:09 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <memory>
#include <iostream>
#include <algorithm>

#include <reverse_iterator.hpp>
#include <vector_iterator.hpp>
#include <utils.hpp>

namespace ft {
	template<class T, class Alloc = std::allocator<T> >
	class vector {
		public:
			typedef T															value_type;
			typedef Alloc														allocator_type;
			typedef typename allocator_type::reference							reference;
			typedef typename allocator_type::const_reference					const_reference;
			typedef typename allocator_type::pointer							pointer;
			typedef typename allocator_type::const_pointer						const_pointer;
			typedef ft::vector_iterator<value_type, vector>						iterator;
			typedef ft::vector_iterator<const value_type, vector>				const_iterator;
			typedef ft::reverse_iterator<iterator>								reverse_iterator;
			typedef ft::reverse_iterator<const_iterator>						const_reverse_iterator;
			typedef typename ft::iterator_traits<iterator>::difference_type		difference_type;
			typedef typename allocator_type::size_type							size_type;

			vector(const allocator_type& alloc = allocator_type()): _alloc(alloc), _addr(nullptr), _len(0), _cap(0) {}
			vector(size_type n, const value_type& val = value_type(), const allocator_type& alloc = allocator_type()): _alloc(alloc), _addr(nullptr), _len(0), _cap(0) { assign(n, val); }
			template <class Iter>
			vector(Iter first, Iter last, const allocator_type& alloc = allocator_type(), typename ft::enable_if<!ft::is_integral<Iter>::value, Iter>::type* = nullptr): _alloc(alloc), _addr(nullptr), _len(0), _cap(0) { assign(first, last); }
			vector(const vector &cpy): _addr(nullptr), _len(0), _cap(0) { *this = cpy; }
			~vector(void)
			{
				for (size_type i = 0; i < _len; i++)
					_alloc.destroy(&_addr[i]);
				_alloc.deallocate(_addr, _cap);
			}
			vector	&operator=(const vector &cpy)
			{
				_alloc = cpy._alloc;
				assign(cpy.begin(), cpy.end());
				return *this;
			}

		private:
			allocator_type	_alloc;

			pointer		_addr;
			size_type	_len;
			size_type	_cap;

		public:
			// Iterators
			iterator		begin(void)			{ return iterator(_addr); }
			iterator		end(void)			{ return iterator(_addr + _len); }
			const_iterator	begin(void) const	{ return const_iterator(_addr); }
			const_iterator	end(void)	const	{ return const_iterator(_addr + _len); }
			
			reverse_iterator		rbegin(void)			{ return reverse_iterator(end()); }
			reverse_iterator		rend(void)				{ return reverse_iterator(begin()); }
			const_reverse_iterator	rbegin(void)	const	{ return const_reverse_iterator(end()); }
			const_reverse_iterator	rend(void)		const	{ return const_reverse_iterator(begin()); }
	
			// Capacity
			size_type		size(void)		const	{ return _len; }
			size_type		max_size(void)	const	{ return _alloc.max_size(); }
			size_type		capacity(void)	const	{ return _cap; }
			bool			empty(void)		const	{ return _len == 0; }
			void			resize(size_type n, value_type val = value_type())
			{
				if (n == _len)
					return ;
				if (n > _len)
					insert(end(), n - _len, val);
				else
					erase(begin() + n, end());
			}
			void			reserve(size_type new_cap)
			{
				if (!new_cap || new_cap <= _cap)
					return ;
				value_type	*new_addr = _alloc.allocate(new_cap);
				for (size_type i = 0; i < _len; i++)
				{
					_alloc.construct(&new_addr[i], _addr[i]);
					_alloc.destroy(&_addr[i]);
				}
				_alloc.deallocate(_addr, _cap);
				_cap = new_cap;
				_addr = new_addr;
			}

			// Element access
			reference		operator[](size_type n)			{ return *(begin() + n); }
			const_reference	operator[](size_type n)	const	{ return *(begin() + n); }
			
			reference		front(void)				{ return *begin(); }
			reference		back(void)				{ return *(end() - (_len > 0)); }
			const_reference	front(void)		const	{ return *begin(); }
			const_reference	back(void)		const	{ return *(end() - (_len > 0)); }
			
			reference		at(size_type n)
			{
				if (n >= _len || n < 0)
					throw std::out_of_range("index out of range.");
				return _addr[n];
			}
			const_reference at(size_type n) const
			{
				if (n >= _len || n < 0)
					throw std::out_of_range("index out of range.");
				return _addr[n];
			}
			allocator_type	get_allocator(void)	const	{ return _alloc; }

			// Modifiers
			iterator erase (iterator position)			{ return erase(position, position + 1); }
			iterator erase (iterator first, iterator last)
			{
				size_type	erased = ft::distance(first, last);
				if (erased <= 0)
					return last;
				for (iterator it = first; it != last; it++)
					_alloc.destroy(&(*it));
				if (last == end())
				{
					_len -= erased;
					return end();
				}
				for (iterator it = last; it != end(); it++)
				{
					_alloc.construct(&(*(it - erased)), *it);
					_alloc.destroy(&(*it));
				}
				_len -= erased;
				return first;
			}

			iterator insert(iterator position, const value_type &val)
			{
				typename iterator_traits<iterator>::difference_type	index = position - begin();
				insert(position, 1, val);
				return (begin() + index);
			}
			void insert(iterator position, size_type n, const value_type &val)
			{
				size_type	qty = n;
				size_type	index = position - begin();
				if (qty <= 0)
					return ;
				while (_len + qty > _cap)
					reserve(_cap == 0 ? 1 : _cap * 2);
				if (_len > 0)
				{
					for (size_type i = _len - 1; i >= index && i != std::numeric_limits<size_type>::max(); i--)
					{
						_alloc.construct(&_addr[i + qty], _addr[i]);
						_alloc.destroy(&_addr[i]);
					}
				}
				for (size_type i = index; i < index + qty; i++)
					_alloc.construct(&_addr[i], val);
				_len += qty;
			}
			template <class Iter>
			void insert(iterator position, Iter first, Iter last, typename ft::enable_if<!ft::is_integral<Iter>::value, Iter>::type* = nullptr)
			{
				size_type	qty = ft::distance(first, last);
				size_type	index = position - begin();
				if (qty <= 0)
					return ;
				while (_len + qty > _cap)
					reserve(_cap == 0 ? 1 : _cap * 2);
				if (_len > 0)
				{
					for (size_type i = _len - 1; i >= index && i != std::numeric_limits<size_type>::max(); i--)
					{
						_alloc.construct(&_addr[i + qty], _addr[i]);
						_alloc.destroy(&_addr[i]);
					}
				}
				for (Iter it = first; it != last; it++)
					_alloc.construct(&_addr[index++], *it);
				_len += qty;
			}

			void	swap(vector &y)
			{
				std::swap(_alloc, y._alloc);
				std::swap(_addr, y._addr);
				std::swap(_len, y._len);
				std::swap(_cap, y._cap);
			}

			template <class Iter>
			void	assign (Iter first, Iter last, typename ft::enable_if<!ft::is_integral<Iter>::value, Iter>::type* = nullptr)
			{
				clear();
				insert(begin(), first, last);
			}
			void	assign (size_type n, const value_type &val)
			{
				clear();
				insert(begin(), n, val);
			}

			void	push_back(const value_type& val)	{ insert(end(), val); }
			void	pop_back(void)						{ erase(end() - 1); }
			void	clear(void)							{ erase(begin(), end()); }

			// Non-member function overloads
			friend void		swap(vector &x, vector &y) { x.swap(y); }
			friend bool		operator==(const vector &lhs, const vector &rhs)
			{
				if (lhs.size() != rhs.size())
					return false;
				return ft::equal(lhs.begin(), lhs.end(), rhs.begin());
			}
			friend bool		operator!=(const vector<T> &lhs, const vector<T> &rhs)	{ return !(lhs == rhs); }
			friend bool 	operator<(const vector<T> &lhs, const vector<T> &rhs)
			{
				return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
			}
			friend bool		operator<=(const vector<T> &lhs, const vector<T> &rhs)	{ return !(lhs > rhs); }
			friend bool		operator>(const vector<T> &lhs, const vector<T> &rhs)	{ return rhs < lhs; }
			friend bool		operator>=(const vector<T> &lhs, const vector<T> &rhs)	{ return !(lhs < rhs); }
	};
}
