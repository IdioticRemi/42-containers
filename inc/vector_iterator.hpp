#pragma once

#include "iterator_utils.hpp"

namespace ft
{
	template <typename T, typename Container>
	class vector_iterator
	{
	public:
		typedef typename iterator_traits<T *>::difference_type		difference_type;
		typedef typename iterator_traits<T *>::value_type			value_type;
		typedef typename iterator_traits<T *>::pointer				pointer;
		typedef typename iterator_traits<T *>::reference			reference;
		typedef typename ft::random_access_iterator_tag				iterator_category;

		vector_iterator(): _addr(nullptr) {}
		vector_iterator(T *addr): _addr(addr) {}
		template <typename U>
		vector_iterator(const vector_iterator<U, Container> &cpy): _addr(cpy.base()) {}
		~vector_iterator() {}

		pointer base() const { return (_addr); }

		vector_iterator &operator=(const vector_iterator &rhs)
		{
			_addr = rhs._addr;
			return (*this);
		}
		vector_iterator &operator++()
		{
			++_addr;
			return (*this);
		}
		vector_iterator operator++(int)
		{
			vector_iterator cpy(_addr++);
			return (cpy);
		}
		vector_iterator &operator--()
		{
			--_addr;
			return (*this);
		}
		vector_iterator operator--(int)
		{
			vector_iterator cpy(_addr--);
			return (cpy);
		}
		reference operator*() const
		{
			return (*_addr);
		}
		pointer operator->() const
		{
			return (_addr);
		}
		vector_iterator &operator+=(difference_type rhs)
		{
			_addr += rhs;
			return (*this);
		}
		vector_iterator &operator-=(difference_type rhs)
		{
			_addr -= rhs;
			return (*this);
		}
		reference	operator[](difference_type rhs) const
		{
			return *(_addr + rhs);
		}

	private:
		pointer	_addr;
	};
}

namespace ft {
	template <typename T, typename Container>
	bool operator==(const ft::vector_iterator<T, Container> &rhs,		const ft::vector_iterator<T, Container> &lhs)		{ return (lhs.base() == rhs.base()); }
	template <typename U, typename V, typename Container>
	bool operator==(const ft::vector_iterator<U, Container> &rhs, const ft::vector_iterator<V, Container> &lhs)		{ return (lhs.base() == rhs.base()); }

	template <typename T, typename Container>
	bool operator!=(const ft::vector_iterator<T, Container> &rhs,		const ft::vector_iterator<T, Container> &lhs)		{ return (lhs.base() != rhs.base()); }
	template <typename U, typename V, typename Container>
	bool operator!=(const ft::vector_iterator<U, Container> &rhs, const ft::vector_iterator<V, Container> &lhs)		{ return (lhs.base() != rhs.base()); }

	template <typename T, typename Container>
	bool operator>=(const ft::vector_iterator<T, Container> &rhs,		const ft::vector_iterator<T, Container> &lhs)		{ return (lhs.base() <= rhs.base()); }
	template <typename U, typename V, typename Container>
	bool operator>=(const ft::vector_iterator<U, Container> &rhs, const ft::vector_iterator<V, Container> &lhs)		{ return (lhs.base() <= rhs.base()); }

	template <typename T, typename Container>
	bool operator<=(const ft::vector_iterator<T, Container> &rhs, 		const ft::vector_iterator<T, Container> &lhs)		{ return (lhs.base() >= rhs.base()); }
	template <typename U, typename V, typename Container>
	bool operator<=(const ft::vector_iterator<U, Container> &rhs,	const ft::vector_iterator<V, Container> &lhs)		{ return (lhs.base() >= rhs.base()); }

	template <typename T, typename Container>
	bool operator>(const ft::vector_iterator<T, Container> &rhs,		const ft::vector_iterator<T, Container> &lhs)		{ return (lhs.base() < rhs.base()); }
	template <typename U, typename V, typename Container>
	bool operator>(const ft::vector_iterator<U, Container> &rhs,	const ft::vector_iterator<V, Container> &lhs)		{ return (lhs.base() < rhs.base()); }

	template <typename T, typename Container>
	bool operator<(const ft::vector_iterator<T, Container> &rhs, 		const ft::vector_iterator<T, Container> &lhs)		{ return (lhs.base() > rhs.base()); }
	template <typename U, typename V, typename Container>
	bool operator<(const ft::vector_iterator<U, Container> &rhs,	const ft::vector_iterator<V, Container> &lhs)		{ return (lhs.base() > rhs.base()); }

	template <typename T, typename Container>
	ft::vector_iterator<T, Container> operator+(typename ft::vector_iterator<T, Container>::difference_type rhs, const ft::vector_iterator<T, Container> &lhs)						{ return (lhs.base() + rhs); }
	
	template <typename T, typename Container>
	ft::vector_iterator<T, Container> operator+(const ft::vector_iterator<T, Container> &rhs, typename ft::vector_iterator<T, Container>::difference_type lhs)						{ return (rhs.base() + lhs); }

	template <typename T, typename Container>
	ft::vector_iterator<T, Container> operator-(const ft::vector_iterator<T, Container> &rhs, typename ft::vector_iterator<T, Container>::difference_type lhs)						{ return (rhs.base() - lhs); }

	template <typename T, typename Container>
	typename ft::vector_iterator<T, Container>::difference_type operator-(const ft::vector_iterator<T, Container> &rhs, const ft::vector_iterator<T, Container> &lhs)				{ return (rhs.base() - lhs.base()); }
	template <typename U, typename V, typename Container>
	typename ft::vector_iterator<U, Container>::difference_type operator-(const ft::vector_iterator<V, Container> &rhs, const ft::vector_iterator<U, Container> &lhs)	{ return (rhs.base() - lhs.base()); }
}