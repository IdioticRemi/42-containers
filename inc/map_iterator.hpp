#pragma once

#include <iterator_utils.hpp>
#include <avl_tree.hpp>

namespace ft
{
	template <typename T>
	class map_iterator
	{
	public:
		typedef	Node<T>												node_type;
		typedef typename iterator_traits<T *>::difference_type		difference_type;
		typedef typename iterator_traits<T *>::value_type			value_type;
		typedef typename iterator_traits<T *>::pointer				pointer;
		typedef typename iterator_traits<T *>::reference			reference;
		typedef typename ft::bidirectional_iterator_tag				iterator_category;

		map_iterator(void): _ptr_list(nullptr), _current(0), _size(0) {}
		map_iterator(const avl_tree &tree, bool end = false): _ptr_list(nullptr), _current(0), _size(tree.getSize())
		{
			_ptr_list = new pointer(_size);
			fill_ptr_list(tree.getRoot());
			_current = end ? _size : 0;
		}
		map_iterator(const map_iterator &cpy): _current(cpy._current), _size(cpy._size) { *this = cpy; }

		~map_iterator() { delete _ptr_list; }
	
	private:
		pointer 		*_ptr_list;
		difference_type	_current;
		difference_type	_size;

		void	fill_ptr_list(const node_type *node)
		{
			if (node->left)
				fill_ptr_list(node->left);
			_ptr_list[_current] = &node->value;
			if (node->right)
				fill_ptr_list(node->right);
		}

	public:
		template<U>
		bool compare(const map_iterator<U> &other)
		{
			if (_size != other._size || _current != other._current)
				return false;
			if (_size == _current)
				return true;
			if (_ptr_list[_current] != other._ptr_list[_current])
				return false;
			return true;
		}
		map_iterator &operator=(const map_iterator &rhs)
		{
			_ptr_list = new pointer(rhs._size);
			for (difference_type i = 0; i < rhs._size; i++)
				_ptr_list[i] = rhs._ptr_list[i];
			_current = rhs._current;
			_size = rhs._size;
		}
		map_iterator &operator++()
		{
			++_current;
			return (*this);
		}
		map_iterator operator++(int)
		{
			map_iterator cpy(*this);
			++_current;
			return (cpy);
		}
		map_iterator &operator--()
		{
			--_current;
			return (*this);
		}
		map_iterator operator--(int)
		{
			map_iterator cpy(this);
			--_current;
			return (cpy);
		}
		reference operator*() const
		{
			return (*_ptr_list[_current]);
		}
		pointer operator->() const
		{
			return (_ptr_list[_current]);
		}
	};
}

namespace ft {
	template <typename T>
	bool operator==(const ft::map_iterator<T> &rhs,	const ft::map_iterator<T> &lhs)		{ return (lhs.compare(rhs)); }
	template <typename U, typename V>
	bool operator==(const ft::map_iterator<U> &rhs, const ft::map_iterator<V> &lhs)		{ return (lhs.compare(rhs)); }

	template <typename T>
	bool operator!=(const ft::map_iterator<T> &rhs,	const ft::map_iterator<T> &lhs)		{ return (!lhs.compare(rhs)); }
	template <typename U, typename V>
	bool operator!=(const ft::map_iterator<U> &rhs, const ft::map_iterator<V> &lhs)		{ return (!lhs.compare(rhs)); }
}