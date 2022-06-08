#pragma once

#include "./iterator_utils.hpp"

namespace ft
{
	template <typename T>
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
		vector_iterator(const vector_iterator<T> &rhs): _addr(rhs._addr) {}
		~vector_iterator() {}
		
		T *base() const { return (_addr); }

		vector_iterator<T> &operator=(const vector_iterator<T> &rhs)
		{
			_addr = rhs._addr;
			return (*this);
		}
		vector_iterator<T> &operator++()
		{
			++_addr;
			return (*this);
		}
		vector_iterator<T> operator++(int)
		{
			vector_iterator<T> cpy(_addr++);
			return (cpy);
		}
		vector_iterator<T> &operator--()
		{
			--_addr;
			return (*this);
		}
		vector_iterator<T> operator--(int)
		{
			vector_iterator<T> cpy(_addr--);
			return (cpy);
		}
		reference operator*()
		{
			return (*_addr);
		}
		pointer operator->()
		{
			return (_addr);
		}
		vector_iterator<T> &operator+=(difference_type rhs)
		{
			_addr += rhs;
			return (*this);
		}
		vector_iterator<T> &operator-=(difference_type rhs)
		{
			_addr -= rhs;
			return (*this);
		}
		vector_iterator<T> &operator[](difference_type rhs)
		{
			return (vector_iterator<T *>(_addr - rhs - 1));
		}

		friend bool operator==(const vector_iterator<T> &rhs, const vector_iterator<T> &lhs)
		{
			return (lhs.base() == rhs.base());
		}
		friend bool operator!=(const vector_iterator<T> &rhs, const vector_iterator<T> &lhs)
		{
			return (lhs.base() != rhs.base());
		}
		friend bool operator>=(const vector_iterator<T> &rhs, const vector_iterator<T> &lhs)
		{
			return (lhs.base() <= rhs.base());
		}
		friend bool operator<=(const vector_iterator<T> &rhs, const vector_iterator<T> &lhs)
		{
			return (lhs.base() >= rhs.base());
		}
		friend bool operator>(const vector_iterator<T> &rhs, const vector_iterator<T> &lhs)
		{
			return (lhs.base() < rhs.base());
		}
		friend bool operator<(const vector_iterator<T> &rhs, const vector_iterator<T> &lhs)
		{
			return (lhs.base() > rhs.base());
		}
		friend vector_iterator<T> operator+(difference_type rhs, const vector_iterator<T> &lhs)
		{
			return (vector_iterator<T>(lhs.base() + rhs));
		}
		friend vector_iterator<T> operator+(const vector_iterator<T> &rhs, difference_type lhs)
		{
			return (vector_iterator<T>(rhs.base() + lhs));
		}
		friend vector_iterator<T> operator-(const vector_iterator<T> &rhs, difference_type lhs)
		{
			return (vector_iterator<T>(rhs.base() - lhs));
		}
		friend difference_type operator-(const vector_iterator<T> &rhs, const vector_iterator<T> &lhs)
		{
			return (rhs.base() - lhs.base());
		}

	private:
		pointer	_addr;
	};
}