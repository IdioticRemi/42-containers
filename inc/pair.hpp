#pragma once

namespace ft
{
	template <typename U, typename V>
	class pair
	{
	public:
		typedef U	first_type;
		typedef V	second_type;

		U	first;
		V	second;

		pair(): first(), second() {}
		pair(const U &u, const V &v): first(u), second(v) {}
		pair(const pair<U, V> &cpy): first(cpy.first), second(cpy.second) {}
		~pair() {}

		pair<U, V> &operator=(const pair<U, V> &rhs)
		{
			first = rhs.first;
			second = rhs.second;
			return (*this);
		}
		friend bool operator==(const pair<U, V> &lhs, const pair<U, V> &rhs)
		{
			return (lhs.first == rhs.first && lhs.second == rhs.second);
		}
		friend bool operator!=(const pair<U, V> &lhs, const pair<U, V> &rhs)
		{
			return !(lhs == rhs);
		}
		friend bool operator<(const pair<U, V> &lhs, const pair<U, V> &rhs)
		{
			return (lhs.first < rhs.first || (!(rhs.first < lhs.first) && lhs.second < rhs.second));
		}
		friend bool operator<=(const pair<U, V> &lhs, const pair<U, V> &rhs)
		{
			return !(rhs < lhs);
		}
		friend bool operator>(const pair<U, V> &lhs, const pair<U, V> &rhs)
		{
			return (rhs < lhs);
		}
		friend bool operator>=(const pair<U, V> &lhs, const pair<U, V> &rhs)
		{
			return !(lhs < rhs);
		}
	};

	template <typename U, typename V>
	pair<U, V> make_pair(U u, V v)
	{
		return (pair<U, V>(u, v));
	}
}