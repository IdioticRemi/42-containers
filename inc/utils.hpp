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

	template<bool Cond, class T = void> struct enable_if {};
    template<class T> struct enable_if<true, T> { typedef T type; };

	template <bool is_integral, typename T>
	class is_integral_res
	{
	public:
		typedef T type;
		static const bool value = is_integral;
	};

	template <typename>
	class is_integral_type : public is_integral_res<false, bool> {};
	template <>
	struct is_integral_type<bool> : public is_integral_res<true, bool> {};
	template <>
	struct is_integral_type<char> : public is_integral_res<true, char> {};
	template <>
	struct is_integral_type<signed char> : public is_integral_res<true, signed char> {};
	template <>
	struct is_integral_type<short int> : public is_integral_res<true, short int> {};
	template <>
	struct is_integral_type<int> : public is_integral_res<true, int> {};
	template <>
	struct is_integral_type<long int> : public is_integral_res<true, long int> {};
	template <>
	struct is_integral_type<long long int> : public is_integral_res<true, long long int> {};
	template <>
	struct is_integral_type<unsigned char> : public is_integral_res<true, unsigned char> {};
	template <>
	struct is_integral_type<unsigned short int> : public is_integral_res<true, unsigned short int> {};
	template <>
	struct is_integral_type<unsigned int> : public is_integral_res<true, unsigned int> {};
	template <>
	struct is_integral_type<unsigned long int> : public is_integral_res<true, unsigned long int> {};
	template <>
	struct is_integral_type<unsigned long long int> : public is_integral_res<true, unsigned long long int> {};

	template <typename T>
    class is_integral : public is_integral_type<T> {};

	template<typename, typename>
	class is_same
	{
	public:
		enum { value = 0 };
		typedef std::false_type type;
	};
	
	template<typename _Tp>
	class is_same<_Tp, _Tp>
	{
	public:
		enum { value = 1 };
		typedef std::true_type type;
	};
}
