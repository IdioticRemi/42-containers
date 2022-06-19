#pragma once

#include <iterator_utils.hpp>
#include <avl_tree.hpp>

namespace ft
{
	template <typename T>
	class avl_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
	{
	public :
		typedef typename T::value_type																	value_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type		difference_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer				pointer;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference			reference;

		avl_iterator(): _node(), _first_node(), _last_node() {}
		avl_iterator(T *node, T *first_node, T *last_node): _node(node), _first_node(first_node), _last_node(last_node) { if (_node == _last_node) _node = nullptr; }
		template <typename U>
		avl_iterator(const avl_iterator<U> &avl_it): _node(avl_it._node), _first_node(avl_it._last_node), _last_node(avl_it._last_node) {}
		~avl_iterator() {}

		avl_iterator &operator=(const avl_iterator &src)
		{
			this->_node = src._node;
			this->_first_node = src._first_node;
			this->_last_node = src._last_node;
			return (*this);
		}
		reference	operator*()		const			{ return this->_node->value; }
		pointer		operator->()	const			{ return &this->operator*(); }

		avl_iterator &operator++(void)
		{
			T	*tmp;

			if (!_node)
				return *this;
			if (!_node->right)
			{
				if (_node == _last_node)
				{
					_node = nullptr;
					return *this;
				}
				tmp = _node;
				_node = _node->parent;
				while (_node->right && tmp == _node->right)
				{
					tmp = _node;
					_node = _node->parent;
				}
				return *this;
			}
			_node = _node->right;
			while (_node->left)
				_node = _node->left;
			return *this;
		}
		avl_iterator operator++(int)
		{
			avl_iterator tmp(*this);
			++*this;
			return (tmp);
		}
		avl_iterator &operator--(void)
		{
			T	*tmp;

			if (!_node)
				return *this;
			if (!_node->left)
			{
				if (_node == _first_node)
				{
					_node = nullptr;
					return *this;
				}
				tmp = _node;
				_node = _node->parent;
				while (_node->left && tmp == _node->left)
				{
					tmp = _node;
					_node = _node->parent;
				}
				return *this;
			}
			_node = _node->left;
			while (_node->right)
				_node = _node->right;
			return *this;
		}
		avl_iterator operator--(int)
		{
			avl_iterator tmp(*this);
			--*this;
			return (tmp);
		}

		T			*_node;
		T			*_first_node;
		T			*_last_node;
	};
}

namespace ft {
	template <typename T>
	bool operator==(const ft::avl_iterator<T> &rhs,	const ft::avl_iterator<T> &lhs)		{ return rhs._node == lhs._node; }
	template <typename U, typename V>
	bool operator==(const ft::avl_iterator<U> &rhs, const ft::avl_iterator<V> &lhs)		{ return rhs._node == lhs._node; }

	template <typename T>
	bool operator!=(const ft::avl_iterator<T> &rhs,	const ft::avl_iterator<T> &lhs)		{ return rhs._node != lhs._node; }
	template <typename U, typename V>
	bool operator!=(const ft::avl_iterator<U> &rhs, const ft::avl_iterator<V> &lhs)		{ return rhs._node = lhs._node; }
}