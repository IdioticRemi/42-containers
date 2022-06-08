#pragma once

#include "./iterator_utils.hpp"

namespace ft
{
	template <typename Iter>
	class reverse_iterator
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

		reverse_iterator(): _iter() {}
		reverse_iterator(Iter iter): _iter(iter) {}
		reverse_iterator(const reverse_iterator<Iter> &rhs): _iter(rhs._iter) {}
		~reverse_iterator() {}
		
		Iter base() const { return (_iter); }

		reverse_iterator<Iter> &operator=(const reverse_iterator<Iter> &rhs)
		{
			_iter = rhs._iter;
			return (*this);
		}
		reverse_iterator<Iter> &operator++()
		{
			--_iter;
			return (*this);
		}
		reverse_iterator<Iter> operator++(int)
		{
			reverse_iterator<Iter> cpy(_iter--);
			return (cpy);
		}
		reverse_iterator<Iter> &operator--()
		{
			++_iter;
			return (*this);
		}
		reverse_iterator<Iter> operator--(int)
		{
			reverse_iterator<Iter> cpy(_iter++);
			return (cpy);
		}
		reference operator*(void)
		{
			Iter cpy(_iter);
			--cpy;
			return (*cpy);
		}
		pointer operator->(void)
		{
			Iter cpy(_iter);
			--cpy;
			return (cpy.operator->());
		}
		reverse_iterator<Iter> &operator+=(difference_type rhs)
		{
			_iter -= rhs;
			return (*this);
		}
		reverse_iterator<Iter> &operator-=(difference_type rhs)
		{
			_iter += rhs;
			return (*this);
		}
		reverse_iterator<Iter> &operator[](difference_type rhs)
		{
			return (reverse_iterator<Iter>(_iter - rhs - 1));
		}

		friend bool operator==(const reverse_iterator<Iter> &rhs, const reverse_iterator<Iter> &lhs)
		{
			return (lhs.base() == rhs.base());
		}
		friend bool operator!=(const reverse_iterator<Iter> &rhs, const reverse_iterator<Iter> &lhs)
		{
			return (lhs.base() != rhs.base());
		}
		friend bool operator>=(const reverse_iterator<Iter> &rhs, const reverse_iterator<Iter> &lhs)
		{
			return (lhs.base() <= rhs.base());
		}
		friend bool operator<=(const reverse_iterator<Iter> &rhs, const reverse_iterator<Iter> &lhs)
		{
			return (lhs.base() >= rhs.base());
		}
		friend bool operator>(const reverse_iterator<Iter> &rhs, const reverse_iterator<Iter> &lhs)
		{
			return (lhs.base() < rhs.base());
		}
		friend bool operator<(const reverse_iterator<Iter> &rhs, const reverse_iterator<Iter> &lhs)
		{
			return (lhs.base() > rhs.base());
		}
		friend reverse_iterator<Iter> operator+(difference_type rhs, const reverse_iterator<Iter> &lhs)
		{
			return (reverse_iterator<Iter>(lhs.base() - rhs));
		}
		friend reverse_iterator<Iter> operator+(const reverse_iterator<Iter> &rhs, difference_type lhs)
		{
			return (reverse_iterator<Iter>(rhs.base() - lhs));
		}
		friend reverse_iterator<Iter> operator-(const reverse_iterator<Iter> &rhs, difference_type lhs)
		{
			return (reverse_iterator<Iter>(rhs.base() + lhs));
		}
		friend difference_type operator-(const reverse_iterator<Iter> &rhs, const reverse_iterator<Iter> &lhs)
		{
			return (lhs.base() - rhs.base());
		}
	};
}