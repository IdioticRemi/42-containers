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
		typedef typename ft::avl_tree<key_type, mapped_type>::iterator			iterator;
		typedef typename ft::avl_tree<key_type, mapped_type>::const_iterator	const_iterator;
		typedef typename ft::reverse_iterator<iterator>    						reverse_iterator;
		typedef typename ft::reverse_iterator<const_iterator> 					const_reverse_iterator;
		typedef typename ft::iterator_traits<iterator>::difference_type 		difference_type;
		typedef size_t															size_type;

		map (const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _comp(comp), _tree()
		{}

		template <class Iter>
		map (Iter first, Iter last, const key_compare& comp = key_compare(), const allocator_type& alloc = allocator_type())
			: _alloc(alloc), _comp(comp), _tree()
		{
			insert(first, last);
		}
		
		map(const map &cpy): _alloc(cpy._alloc), _comp(cpy._comp), _tree() { 
			// std::cout << "\033[1;31mCOPY CONSTRUCT\033[0m\n" << std::endl; 
			*this = cpy;
		}

		~map()	{ clear(); }

		map &operator=(const map &cpy)
		{
			// std::cout << "\033[1;31mWTF\033[0m\n";
			_tree.clear_tree();
			insert(cpy.begin(), cpy.end());
			return (*this);
		}

		iterator begin()									{ return _tree.begin(); }
		const_iterator begin()						const	{ return _tree.begin(); }

		iterator end()										{ return _tree.end(); }
		const_iterator end()						const	{ return _tree.end(); }

		reverse_iterator rbegin()							{ return (reverse_iterator(end())); }
		const_reverse_iterator rbegin()				const	{ return (const_reverse_iterator(end())); }

		reverse_iterator rend()								{ return (reverse_iterator(begin())); }
		const_reverse_iterator rend()				const	{ return (const_reverse_iterator(begin())); }

		bool empty()								const	{ return _tree.isEmpty(); }
		size_type size()							const	{ return _tree.getSize(); }
		size_type max_size()						const	{ return std::map<key_type, mapped_type>().max_size() ; }

		void swap(map &x)									{ _tree.swap(x._tree); }
		void clear()										{ _tree.clear_tree(); }

		key_compare		key_comp()					const	{ return (key_compare()); }
		value_compare	value_comp()				const	{ return (value_compare(key_compare())); }

		iterator		find(const key_type &key)			{ return _tree.getRoot() ? (iterator(_tree.find(ft::make_pair(key, mapped_type())), _tree.getRoot()->getMin(), _tree.getRoot()->getMax())) : end(); }
		const_iterator	find(const key_type& key)	const	{ return _tree.getRoot() ? (const_iterator(_tree.find(ft::make_pair(key, mapped_type())), _tree.getRoot()->getMin(), _tree.getRoot()->getMax())) : end(); }

		mapped_type &operator[](const key_type &key)
		{
			iterator tmp = find(key);

			if (tmp == end())
				insert(ft::make_pair(key, mapped_type()));
			tmp = find(key);
			return (tmp->second);
		}

		pair<iterator, bool>	insert(const value_type& val)
		{
			typename avl_tree<key_type, mapped_type>::size_type	before = _tree.getSize();
			_tree.insert(val);
			return ft::make_pair(find(val.first), before != _tree.getSize());
		}
		iterator				insert(iterator position, const value_type& val)
		{
			(void) position;
			return (insert(val).first);
		}
		template <class Iter>
		void					insert(Iter first, Iter last)
		{
			for (; first != last; first++)
				_tree.insert(ft::make_pair((key_type) (*first).first, (*first).second));
		}

		void		erase(iterator position)	{ erase((*position).first); }
		size_type	erase(const key_type &key)
		{
			if (find(key) == end())
				return 0;
			_tree.remove(*find(key));
			return 1;
		}
		void		erase(iterator first, iterator last)
		{
			while (first != last)
			{
				iterator next = first;
				++next;
				erase(first);
				first = next;
			}
		}

		size_type 		count(const key_type &key)	const	{ return find(key) == end() ? 0 : 1; }

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

		friend void		swap(map &x, map &y) { x.swap(y); }
		friend bool		operator==(const map &lhs, const map &rhs)
		{
			return lhs.size() == rhs.size() && ft::equal(lhs.begin(), lhs.end(), rhs.begin());
		}
		friend bool		operator!=(const map &lhs, const map &rhs)	{ return !(lhs == rhs); }
		friend bool 	operator<(const map &lhs, const map &rhs)
		{
			return ft::lexicographical_compare(lhs.begin(), lhs.end(), rhs.begin(), rhs.end());
		}	
		friend bool		operator<=(const map &lhs, const map &rhs)	{ return !(lhs > rhs); }
		friend bool		operator>(const map &lhs, const map &rhs)	{ return rhs < lhs; }
		friend bool		operator>=(const map &lhs, const map &rhs)	{ return !(lhs < rhs); }
	private:
		allocator_type					_alloc;
		key_compare						_comp;
		avl_tree<key_type, mapped_type>	_tree;

	};
}