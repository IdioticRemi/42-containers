#pragma once

#include <memory>
#include <iostream>
#include <algorithm>
#include <cmath>
#include <iomanip>

#include "avl_iterator.hpp"

template <typename T>
class node
{
private:
	ssize_t	_height;

public:
	T		value;
	node	*left;
	node	*right;

	node(T value): value(value), left(nullptr), right(nullptr), _height(1) {}

	node	*getMax() { return (right ? right->getMax() : this); }
	node	*getMaxParent() { return ((right && right->right) ? right->getMaxParent() : this); }
	void	updateHeight()
	{
		_height = 1 + std::max( (right	?	right->height()	: 0),
								(left	?	left->height()	: 0));
	}
	ssize_t	height()		const { return _height; }
	ssize_t	balance()		const { return (left ? left->height() : 0) - (right ? right->height() : 0); }
};

namespace ft
{
	template <typename T, typename Compare, typename Alloc = std::allocator<node<T> > >
	class avl_tree
	{
	public:
		typedef	node<T>									node_type;
		typedef ft::avl_iterator<Node, Compare>			iterator;
		typedef ft::avl_iterator<const Node, Compare>	const_iterator;

	private:
		node_type	*_root;
		Alloc		_alloc;

		node_type	*insert(T value, node_type *node)
		{
			if (node == nullptr)
			{
				node_type *new_node = _alloc.allocate(1);
				_alloc.construct(new_node, node_type(value));
				return new_node;
			}
			if (node->value < value)
				node->right = insert(value, node->right);
			else if (node->value > value)
				node->left = insert(value, node->left);
			else
				return node;
			node->updateHeight();
			return applyRotation(node);
		}
		
		node_type	*applyRotation(node_type *node)
		{
			ssize_t	balanciaga = node->balance();
			if (balanciaga > 1)
			{
				if (node->left && node->left->balance() < 0)
					node->left = left_rotation(node->left);
				return right_rotation(node);
			}
			if (balanciaga < -1)
			{
				if (node->right && node->right->balance() > 0)
					node->right = right_rotation(node->right);
				return left_rotation(node);
			}
			return node;
		}

		node_type	*left_rotation(node_type *node)
		{
			node_type	*rightNode = node->right;
			node_type	*centerNode = rightNode->left;

			rightNode->left = node;
			node->right = centerNode;
			node->updateHeight();
			rightNode->updateHeight();
			return rightNode;
		}
		node_type	*right_rotation(node_type *node)
		{
			node_type	*leftNode = node->left;
			node_type	*centerNode = leftNode->right;

			leftNode->right = node;
			node->left = centerNode;
			node->updateHeight();
			leftNode->updateHeight();
			return leftNode;
		}

		node_type	*remove(T value, node_type *node)
		{
			if (node == nullptr)
				return nullptr;
			if (node->value > value)
				node->left = remove(value, node->left);
			else if (node->value < value)
				node->right = remove(value, node->right);
			else
			{
				node_type	*tmp;

				if (node->left == nullptr)
				{
					tmp = node->right;
					_alloc.destroy(node);
					_alloc.deallocate(node, 1);
					return tmp;
				}
				else if (node->right == nullptr)
				{
					tmp = node->left;
					_alloc.destroy(node);
					_alloc.deallocate(node, 1);
					return tmp;
				}
				node->value = node->left->getMax()->value;
				node->left = remove(node->value, node->left);
				// tmp = node;
				// node = node->left->getMax();
				// node->left = tmp->left;
				// node->right = tmp->right;
				// node->left->getMaxParent()->right = nullptr;
				// _alloc.destroy(tmp);
				// _alloc.deallocate(tmp, 1);
			}
			node->updateHeight();
			return applyRotation(node);
		}

	public:
		avl_tree(Alloc alloc = Alloc()): _root(nullptr), _alloc(alloc) {}

		void print_tree(const std::string& prefix, node_type* node, bool isLeft)
		{
		    if( node != nullptr )
		    {
		        std::cout << prefix;

		        std::cout << (isLeft ? "├─>" : "└─>" );
		        std::cout << node->value << std::endl;
		        print_tree( prefix + (isLeft ? "│   " : "    "), node->left, true);
		        print_tree( prefix + (isLeft ? "│   " : "    "), node->right, false);
		    }
		}
		void	print_tree()	{ print_tree("", _root, false); }
		void	insert(T value) { _root = insert(value, _root); }
		void	remove(T value) { _root = remove(value, _root); }
		bool	isEmpty(void)	{ return _root == nullptr; }
	};
}
