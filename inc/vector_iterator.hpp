#pragma once

#include "./iterator_utils.hpp"

namespace ft
{
	template <typename Iter>
	class vector_iterator
	{
	private:
		Iter _iter;

	public:
		typedef Iter												iterator_type;
		typedef typename iterator_traits<Iter>::difference_type		difference_type;
		typedef typename iterator_traits<Iter>::value_type			value_type;
		typedef typename iterator_traits<Iter>::pointer				pointer;
		typedef typename iterator_traits<Iter>::reference			reference;
		typedef typename iterator_traits<Iter>::iterator_category	iterator_category;

		vector_iterator(): _iter() {}
		vector_iterator(Iter iter): _iter(iter) {}
		vector_iterator(const vector_iterator<Iter> &rhs): _iter(rhs._iter) {}
		~vector_iterator() {}
		
		Iter base() const { return (_iter); }

		vector_iterator<Iter> &operator=(const vector_iterator<Iter> &rhs)
		{
			_iter = rhs._iter;
			return (*this);
		}
		vector_iterator<Iter> &operator++()
		{
			++_iter;
			return (*this);
		}
		vector_iterator<Iter> operator++(int)
		{
			vector_iterator<Iter> cpy(_iter++);
			return (cpy);
		}
		vector_iterator<Iter> &operator--()
		{
			--_iter;
			return (*this);
		}
		vector_iterator<Iter> operator--(int)
		{
			vector_iterator<Iter> cpy(_iter--);
			return (cpy);
		}
		reference &operator*()
		{
			return (*_iter);
		}
		pointer &operator->()
		{
			return (_iter.operator->());
		}
		vector_iterator<Iter> &operator+=(difference_type rhs)
		{
			_iter += rhs;
			return (*this);
		}
		vector_iterator<Iter> &operator-=(difference_type rhs)
		{
			_iter -= rhs;
			return (*this);
		}
		vector_iterator<Iter> &operator[](difference_type rhs)
		{
			return (vector_iterator<Iter>(_iter - rhs - 1));
		}

		friend bool operator==(const vector_iterator<Iter> &rhs, const vector_iterator<Iter> &lhs)
		{
			return (lhs.base() == rhs.base());
		}
		friend bool operator!=(const vector_iterator<Iter> &rhs, const vector_iterator<Iter> &lhs)
		{
			return (lhs.base() != rhs.base());
		}
		friend bool operator>=(const vector_iterator<Iter> &rhs, const vector_iterator<Iter> &lhs)
		{
			return (lhs.base() <= rhs.base());
		}
		friend bool operator<=(const vector_iterator<Iter> &rhs, const vector_iterator<Iter> &lhs)
		{
			return (lhs.base() >= rhs.base());
		}
		friend bool operator>(const vector_iterator<Iter> &rhs, const vector_iterator<Iter> &lhs)
		{
			return (lhs.base() < rhs.base());
		}
		friend bool operator<(const vector_iterator<Iter> &rhs, const vector_iterator<Iter> &lhs)
		{
			return (lhs.base() > rhs.base());
		}
		friend vector_iterator<Iter> operator+(difference_type rhs, const vector_iterator<Iter> &lhs)
		{
			return (vector_iterator<Iter>(lhs.base() + rhs));
		}
		friend vector_iterator<Iter> operator+(const vector_iterator<Iter> &rhs, difference_type lhs)
		{
			return (vector_iterator<Iter>(rhs.base() + lhs));
		}
		friend vector_iterator<Iter> operator-(const vector_iterator<Iter> &rhs, difference_type lhs)
		{
			return (vector_iterator<Iter>(rhs.base() - lhs));
		}
		friend difference_type operator-(const vector_iterator<Iter> &rhs, const vector_iterator<Iter> &lhs)
		{
			return (rhs.base() - lhs.base());
		}
	};
}