#pragma once

#include "pair.hpp"

template <typename T>
class node
{
private:
	int		_weight;
public:
	T		value;
	node	*left;
	node	*right;
	node	*parent;

	node(T value): value(value), parent(nullptr), left(nullptr), right(nullptr), _weight(0) {}
	node(T value, node *parent): value(value), parent(parent), left(nullptr), right(nullptr), _weight(0) {}

	bool	is_root()		const { return parent == nullptr; }

	void	recalcWeight()	{ _weight = (right ? right->weight() : 0) - (left ? left->weight() : 0); }
	size_t	weight()		const { return _weight; }
};

namespace ft
{
	template <typename T, typename Compare, typename Alloc = std::allocator<node<T> > >
	class avl_tree
	{
	private:
		node<T>	*_root;
		Alloc	_alloc;
	public:
		avl_tree(Alloc alloc = Alloc()): _root(nullptr), _alloc(alloc) {}

		void	print_l_to_r(node<T> *n)
		{
			if (n->left)
				print_l_to_r(n->left);
			std::cout << n->value << ", ";
			if (n->right)
				print_l_to_r(n->right);
		}
		void	print_l_to_r() { print_l_to_r(_root); }
		void	insert(T value, node<T> *n)
		{
			if (n->value < value)
			{
				if (n->right == nullptr)
				{
					n->right = _alloc.allocate(1);
					_alloc.construct(n->right, node<T>(value, n));
					n->recalcWeight();
					return ;
				}
				insert(value, n->right);
			}
			else
			{
				if (n->left == nullptr)
				{
					n->left = _alloc.allocate(1);
					_alloc.construct(n->left, node<T>(value, n));
					n->recalcWeight();
					return ;
				}
				insert(value, n->left);
			}
			n->recalcWeight();
			if (n->weight() > 1)
			{	// rotate left
				node<T>	*A = n;
				node<T>	*B = n->right;
				node<T>	*D = n->right->left;

				A->right = D;
				A->left = A;
				A = B;
			}
			if (n->weight() < -1)
			{	// rotate right
				node<T>	*A = n;
				node<T>	*B = n->left;
				node<T>	*D = n->left->right;

				A->left = D;
				A->right = A;
				A = B;
			}
		}
		void	insert(T value)
		{
			if (_root == nullptr)
			{
				_root = (node<T> *) _alloc.allocate(sizeof(node<T>));
				_alloc.construct(_root, node<T>(value));
				return ;
			}
			insert(value, _root);
		}
	};
}
