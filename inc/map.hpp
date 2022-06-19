#pragma once

#include <pair.hpp>
#include <utils.hpp>
#include <avl_tree.hpp>
#include <avl_iterator.hpp>
#include <reverse_iterator.hpp>
#include <map>

namespace ft
{
	template < class Key, class T, class Compare = ft::less<Key>, class Alloc = std::allocator<ft::pair<const Key, T> > >
	class map
	{
	public:
		typedef Key     						key_type;
		typedef T       						mapped_type;
		typedef pair<key_type, mapped_type>		value_type;
		typedef Compare     					key_compare;
		class value_compare : ft::compare_fct<value_type, value_type, bool>
		{
			friend class map<key_type, mapped_type, key_compare, Alloc>;

		protected:
			Compare			comp;

			value_compare	(Compare c) : comp(c) {}
		public:
			bool operator() (const value_type& x, const value_type& y) const { return (comp(x.first, y.first)); }
		};
		typedef Alloc  allocator_type;
		typedef typename allocator_type::reference   							reference;
		typedef typename allocator_type::const_reference 						const_reference;
		typedef typename allocator_type::pointer     							pointer;
		typedef typename allocator_type::const_pointer 							const_pointer;
		typedef typename ft::avl_tree<value_type, key_compare>::iterator		iterator;
		typedef typename ft::avl_tree<value_type, key_compare>::const_iterator	const_iterator;
		typedef typename ft::reverse_iterator<iterator>    						reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator> 					const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type 		difference_type;
		typedef size_t															size_type;

		map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _alloc(alloc), _comp(comp), _tree() {}
		template <class Iter>
		map (Iter first, Iter last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type()): _alloc(alloc), _comp(comp), _tree() { insert(first, last); }
		template <typename U, typename V>
		map(const map<U, V> &cpy): _alloc(cpy._alloc), _comp(cpy._comp), _tree() { *this = cpy; }

		~map()	{ clear(); }

		map& operator=(const map &cpy)
		{
			if (&cpy == this)
				return (*this);
			clear();
			insert(cpy.begin(), cpy.end());
			return (*this);
		}

		iterator begin()						{ return _tree.begin(); }
		const_iterator begin()			const	{ return _tree.begin(); }

		iterator end()							{ return _tree.end(); }
		const_iterator end()			const	{ return _tree.end(); }

		reverse_iterator rbegin()				{ return (reverse_iterator(end())); }
		const_reverse_iterator rbegin()	const	{ return (const_reverse_iterator(end())); }

		reverse_iterator rend()					{ return (reverse_iterator(begin())); }
		const_reverse_iterator rend()	const	{ return (const_reverse_iterator(begin())); }

		bool empty()					const	{ return _tree.isEmpty(); }
		size_type size()				const	{ return (_tree._last_node->value.first); }
		size_type max_size()			const	{ return std::map<Key, T>().max_size(); }

		void swap(map& x)									{ _tree.swap(x._tree); }
		void clear()										{ erase(begin(), end()); }

		key_compare		key_comp()					const	{ return (key_compare()); }
		value_compare	value_comp()				const	{ return (value_compare(key_compare())); }

		iterator		find(const key_type &key)			{ return (iterator(_tree.searchByKey(ft::make_pair(key, mapped_type())), _tree._last_node)); }
		const_iterator	find(const key_type& key)	const	{ return (const_iterator(_tree.searchByKey(ft::make_pair(key, mapped_type())), _tree._last_node)); }

		mapped_type& operator[](const key_type &key)
		{
			iterator tmp = find(key);

			if (tmp == end())
				insert(ft::make_pair(key, mapped_type()));
			tmp = find(key);
			return ((*tmp).second);
		}

		pair<iterator, bool>	insert(const value_type& val)	{ return _tree.insertPair(val); }
		iterator				insert(iterator position, const value_type& val)
		{
			(void) position;
			return (_tree.insertPair(val).first);
		}
		template <class Iter>
		void					insert(Iter first, Iter last)
		{
			for (; first != last; first++)
				_tree.insertPair(make_pair((key_type) (*first).first, (*first).second));
		}

		void		erase(iterator position)	{ erase((*position).first); }
		size_type	erase(const key_type& k)
		{
			if (find(k) == end())
				return (0);
			_tree.removeByKey(ft::make_pair(k, mapped_type()));
			return (1);
		}

		void		erase(iterator first, iterator last)
		{
			for (; first != last; first++)
				erase((*first).first);
		}

		size_type 		count(const key_type &key)	const
		{
			iterator first = begin();
			iterator last = end();

			while (first != last)
				if ((*(first++)).first == key)
					return (1);
			return (0);
		}

		iterator lower_bound(const key_type &key)
		{
			iterator first = begin();
			iterator last = end();

			while (first != last)
			{
				if (_comp((*first).first, key) == false)
					break;
				first++;
			}
			return (first);
		}

		const_iterator lower_bound(const key_type &key) const
		{
			const_iterator first = begin();
			const_iterator last = end();

			while (first != last)
			{
				if (_comp((*first).first, key) == false)
					break;
				first++;
			}
			return (first);
		}

		iterator upper_bound(const key_type& k)
		{
			iterator first = begin();
			iterator last = end();

			while (first != last)
			{
				if (_comp(k, (*first).first))
					break;
				first++;
			}
			return (first);
		}

		const_iterator upper_bound(const key_type& k) const
		{
			const_iterator first = begin();
			const_iterator last = end();

			while (first != last)
			{
				if (_comp(k, (*first).first))
					break;
				first++;
			}
			return (first);
		}

		ft::pair<const_iterator, const_iterator>	equal_range(const key_type &key)	const	{ return ft::make_pair(lower_bound(key), upper_bound(key)); }
		ft::pair<iterator, iterator>				equal_range(const key_type &key)			{ return ft::make_pair(lower_bound(key), upper_bound(key)); }
	private:
		allocator_type					_alloc;
		key_compare						_comp;
		avl_tree<value_type, Compare>	_tree;

	};
}