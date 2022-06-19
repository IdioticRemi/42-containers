#pragma once

#include <iterator_utils.hpp>
#include <avl_tree.hpp>

namespace ft
{
	template <typename T, class Compare >
	class avl_iterator : ft::iterator<ft::bidirectional_iterator_tag, T>
	{
	public :
		typedef typename T::value_type																	value_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::iterator_category	iterator_category;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::difference_type		difference_type;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::pointer				pointer;
		typedef typename ft::iterator<ft::bidirectional_iterator_tag, value_type>::reference			reference;

		avl_iterator(const Compare& comp = Compare()): _node(), _last_node(), _comp(comp) {}
		avl_iterator(T * node_p, T * last_node, const Compare& comp = Compare()): _node(node_p), _last_node(last_node), _comp(comp) {}
		template <typename U, typename CompareOther>
		avl_iterator(const avl_iterator<U, CompareOther>& avl_it): _node(avl_it._node), _last_node(avl_it._last_node), _comp() {}
		~avl_iterator() {}

		avl_iterator &operator=(const avl_iterator &avl_it)
		{
			if (*this == avl_it)
				return (*this);
			this->_node = avl_it._node;
			this->_last_node = avl_it._last_node;
			this->_comp = avl_it._comp;
			return (*this);
		}
		reference	operator*()		const			{ return (this->_node->value); }
		pointer		operator->()	const			{ return (&this->_node->value); }

		avl_iterator &operator++(void)
		{
			T* cursor = _node;

			if (!_node)
				return *this;
			if (_node->right == _last_node)
			{
				cursor = _node->parent;
				while (cursor != _last_node
					   && _comp(cursor->value.first, _node->value.first))
					cursor = cursor->parent;
				_node = cursor;
			}
			else if (cursor == _last_node)
				_node = _last_node->right;
			else
			{
				cursor = _node->right;
				if (cursor == _last_node->parent
					&& cursor->right == _last_node)
					_node = cursor;
				else
				{
					while (cursor->left != _last_node)
						cursor = cursor->left;
				}
				_node = cursor;
			}
			return (*this);
		}
		avl_iterator operator++(int)
		{
			avl_iterator tmp(*this);
			++*this;
			return (tmp);
		}
		avl_iterator &operator--(void)
		{
			T* cursor = _node;

			if (_node->left == _last_node)
			{
				cursor = _node->parent;
				while (cursor != _last_node
					   && !_comp(cursor->value.first, _node->value.first))
					cursor = cursor->parent;
				_node = cursor;
			}
			else if (cursor == _last_node)
				_node = _last_node->right;
			else
			{
				cursor = _node->left;
				if (cursor == _last_node->parent
					&& cursor->left == _last_node)
					_node = cursor;
				else
				{
					while (cursor->right != _last_node)
						cursor = cursor->right;
				}
				_node = cursor;
			}
			return (*this);
		}
		avl_iterator operator--(int)
		{
			avl_iterator tmp(*this);
			--*this;
			return (tmp);
		}

		T			*_node;
		T			*_last_node;
		Compare     _comp;
	};
}

namespace ft {
	template <typename T, typename Compare>
	bool operator==(const ft::avl_iterator<T, Compare> &rhs,	const ft::avl_iterator<T, Compare> &lhs)	{ return rhs._node == lhs._node; }
	template <typename U, typename V, typename Compare>
	bool operator==(const ft::avl_iterator<U, Compare> &rhs, const ft::avl_iterator<V, Compare> &lhs)		{ return rhs._node == lhs._node; }

	template <typename T, typename Compare>
	bool operator!=(const ft::avl_iterator<T, Compare> &rhs,	const ft::avl_iterator<T, Compare> &lhs)	{ return rhs._node != lhs._node; }
	template <typename U, typename V, typename Compare>
	bool operator!=(const ft::avl_iterator<U, Compare> &rhs, const ft::avl_iterator<V, Compare> &lhs)		{ return rhs._node = lhs._node; }
}