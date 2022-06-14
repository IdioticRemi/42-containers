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
		template <typename U>
		reverse_iterator(const reverse_iterator<U> &rhs): _iter(rhs.base()) {}
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
			return (cpy.base());
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
		reference operator[](difference_type rhs)
		{
			return *(_iter.base() - rhs - 1);
		}
	};
}

namespace ft {
	template <typename T>
	bool operator==(const ft::reverse_iterator<T> &rhs,		const ft::reverse_iterator<T> &lhs)			{ return (lhs.base() == rhs.base()); }

	template <typename T>
	bool operator!=(const ft::reverse_iterator<T> &rhs,		const ft::reverse_iterator<T> &lhs)			{ return (lhs.base() != rhs.base()); }
	
	template <typename T>
	bool operator>=(const ft::reverse_iterator<T> &rhs,		const ft::reverse_iterator<T> &lhs)			{ return (lhs.base() >= rhs.base()); }

	template <typename T>
	bool operator<=(const ft::reverse_iterator<T> &rhs, 		const ft::reverse_iterator<T> &lhs)		{ return (lhs.base() <= rhs.base()); }

	template <typename T>
	bool operator>(const ft::reverse_iterator<T> &rhs,		const ft::reverse_iterator<T> &lhs)			{ return (lhs.base() > rhs.base()); }

	template <typename T>
	bool operator<(const ft::reverse_iterator<T> &rhs, 		const ft::reverse_iterator<T> &lhs)			{ return (lhs.base() < rhs.base()); }

	template <typename T>
	ft::reverse_iterator<T> operator+(typename ft::reverse_iterator<T>::difference_type rhs, const ft::reverse_iterator<T> &lhs)						{ return (lhs.base() - rhs); }
	
	template <typename T>
	ft::reverse_iterator<T> operator+(const ft::reverse_iterator<T> &rhs, typename ft::reverse_iterator<T>::difference_type lhs)						{ return (rhs.base() - lhs); }

	template <typename T>
	ft::reverse_iterator<T> operator-(const ft::reverse_iterator<T> &rhs, typename ft::reverse_iterator<T>::difference_type lhs)						{ return (rhs.base() + lhs); }
}