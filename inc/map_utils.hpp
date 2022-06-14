#pragma once;

namespace ft {
	template <class Key, class T, class Compare, class Alloc>
	class map<Key,T,Compare,Alloc>::value_compare
	{
	protected:
		Compare comp;
		value_compare (Compare c) : comp(c) {}
	public:
		bool operator() (const value_type &x, const value_type &y) const { return comp(x.first, y.first); }
	}
}