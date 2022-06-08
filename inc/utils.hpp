#pragma once

namespace ft
{
	template <class T>
	void	swap(T &x, T &y)
	{
		T tmp = x;
		x = y;
		y = tmp;
	}
	template <class Iter1, class Iter2>
	bool	equal(Iter1 first1, Iter1 last1, Iter2 first2)
	{
		while (first1!=last1) {
		if (!(*first1 == *first2))
			return false;
		++first1; ++first2;
		}
		return true;
	}
	template <class Iter1, class Iter2, class BinaryPredicate>
	bool	equal(Iter1 first1, Iter1 last1,  Iter2 first2,  BinaryPredicate pred)
	{
		while (first1!=last1) {
		if (!pred(*first1, *first2))
			return false;
		++first1; ++first2;
		}
		return true;
	}
	template <class Iter1, class Iter2>
	bool	lexicographical_compare(Iter1 first1, Iter1 last1, Iter2 first2, Iter2 last2)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || *first2 < *first1)
				return false;
			else if (*first1 < *first2)
				return true;
			first1++;
			first2++;
		}
		return (first2 != last2);
	}
	template <class Iter1, class Iter2, class Compare>
	bool	lexicographical_compare(Iter1 first1, Iter1 last1,  Iter2 first2, Iter2 last2,  Compare cmp)
	{
		while (first1 != last1)
		{
			if (first2 == last2 || cmp(*first2, *first1))
				return false;
			else if (cmp(*first1, *first2))
				return true;
			first1++;
			first2++;
		}
		return (first2 != last2);
	}
}
