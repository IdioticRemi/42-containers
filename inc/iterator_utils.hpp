#pragma once

#include <cstddef>

namespace ft
{
	class output_iterator_tag {};
	class input_iterator_tag {};
	class forward_iterator_tag : public input_iterator_tag {};
	class bidirectional_iterator_tag : public forward_iterator_tag {};
	class random_access_iterator_tag : public bidirectional_iterator_tag {};

	template <class Category, class T, class Distance = ptrdiff_t, class Pointer = T *, class Reference = T &>
	class iterator
	{
	public:
		typedef Distance	difference_type;
		typedef T			value_type;
		typedef Pointer		pointer;
		typedef Reference	reference;
		typedef Category	iterator_category;
	};

	template <typename Iter>
	class iterator_traits
	{
	public:
		typedef typename Iter::difference_type		difference_type;
		typedef typename Iter::value_type			value_type;
		typedef typename Iter::pointer				pointer;
		typedef typename Iter::reference			reference;
		typedef typename Iter::iterator_category	iterator_category;
	};

	template <typename T>
	class iterator_traits<T*>
	{
	public:
		typedef ptrdiff_t					difference_type;
		typedef T							value_type;
		typedef T							*pointer;
		typedef T							&reference;
		typedef random_access_iterator_tag	iterator_category;
	};

	template <typename T>
	class iterator_traits<const T*>
	{
	public:
		typedef ptrdiff_t					difference_type;
		typedef T							value_type;
		typedef const T						*pointer;
		typedef const T						&reference;
		typedef random_access_iterator_tag	iterator_category;
	};

	template <typename Iter>
	typename iterator_traits<Iter>::difference_type	distance(Iter start, Iter end, random_access_iterator_tag)
	{
		return (end - start);
	}
	template <typename Iter>
	typename iterator_traits<Iter>::difference_type	distance(Iter start, Iter end, typename iterator_traits<Iter>::iterator_category)
	{
		typename iterator_traits<Iter>::difference_type dist = 0;

		for (; start != end; ++start)
			dist++;
		return (dist);
	}
	template <typename Iter>
	typename iterator_traits<Iter>::difference_type	distance(Iter start, Iter end)
	{
		return distance(start, end, typename iterator_traits<Iter>::iterator_category());
	}

	template <class Iter, class Distance>
	void	advance(Iter start, Distance dist, random_access_iterator_tag)
	{
		start += dist;
	}
	template <class Iter, class Distance>
	void	advance(Iter start, Distance dist, typename iterator_traits<Iter>::iterator_category)
	{
		typename iterator_traits<Iter>::difference_type	i = 0;

		for (; i < dist; ++i)
			start++;
	}
	template <class Iter, class Distance>
	void	advance(Iter start, Distance dist)
	{
		return advance(start, dist, typename iterator_traits<Iter>::iterator_category());
	}
}