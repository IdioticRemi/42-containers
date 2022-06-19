#pragma once

#include <avl_iterator.hpp>
#include <map.hpp>

namespace ft
{
	template <typename U, typename V>
	class AVLNode
	{
	private:
		ssize_t	_height;

	public:
		typedef ft::pair<U, V>	value_type;

		value_type	value;
		AVLNode		*parent;
		AVLNode		*left;
		AVLNode		*right;

		AVLNode(const value_type &value): _height(1), value(value), left(nullptr), right(nullptr) {}

		AVLNode	*getMax()				{ return (right ? right->getMax() : this); }
		AVLNode	*getMin()				{ return (left ? left->getMin() : this); }
		void	updateHeight()
		{
			_height = 1 + std::max( (right	?	right->height()	: 0),
									(left	?	left->height()	: 0));
		}
		ssize_t	height()		const	{ return _height; }
		ssize_t	balance()		const	{ return (left ? left->height() : 0) - (right ? right->height() : 0); }
	};

	template <typename U, typename V, class Node = AVLNode<U, V>, class Node_Alloc = std::allocator<Node> >
	class avl_tree
	{
	public :
		typedef ft::pair<U, V>										value_type;
		typedef Node												node_type;
		typedef Node												*node_pointer;
		typedef Node_Alloc											node_alloc;
		typedef ft::avl_iterator<Node>								iterator;
		typedef ft::avl_iterator<Node>								const_iterator;
		typedef typename node_alloc::size_type						size_type;

		avl_tree(const node_alloc& _node_alloc = node_alloc()) : _root(nullptr), _alloc(_node_alloc), _size(0)	{}

		~avl_tree(void)	{ clear_tree(_root); }

		void		insert(value_type value)	{ _root = insert(value, _root); reset_parents(); }
		void		remove(value_type value)	{ _root = remove(value, _root); reset_parents(); }
		bool		isEmpty(void) 		const	{ return _root == nullptr; }
		size_type	getSize(void)		const	{ return _size; }
		size_type	max_size(void)		const	{ return _alloc.max_size(); }
		node_type	*find(value_type value)		{ return find(value, _root); }
		node_type	*getRoot(void) 		const	{ return _root; }

		iterator begin()						{ return _root ? iterator(_root->getMin(), _root->getMin(), _root->getMax()) : iterator(); }
		const_iterator begin()			const	{ return _root ? const_iterator(_root->getMin(), _root->getMin(), _root->getMax()) : const_iterator(); }

		iterator end()							{ return _root ? iterator(_root->getMax(), _root->getMin(), _root->getMax()) : iterator(); }
		const_iterator end()			const	{ return _root ? const_iterator(_root->getMax(), _root->getMin(), _root->getMax()) : const_iterator(); }
	private:
		node_type	*_root;
		node_alloc 	_alloc;
		size_t		_size;

		node_type	*find(value_type value, node_type *node)
		{
			if (node == nullptr)
				return nullptr;
			if (node->value.first < value.first)
				return find(value, node->right);
			else if (node->value.first > value.first)
				return find(value, node->left);
			else
				return node;
		}
		node_type	*insert(value_type value, node_type *node)
		{
			if (node == nullptr)
			{
				node_type *new_node = _alloc.allocate(1);
				_alloc.construct(new_node, node_type(value));
				_size++;
				return new_node;
			}
			if (node->value.first < value.first)
				node->right = insert(value, node->right);
			else if (node->value.first > value.first)
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

		node_type	*remove(value_type value, node_type *node)
		{
			if (node == nullptr)
				return nullptr;
			if (node->value.first > value.first)
				node->left = remove(value, node->left);
			else if (node->value.first < value.first)
				node->right = remove(value, node->right);
			else
			{
				node_type	*tmp;

				if (node->left == nullptr)
				{
					tmp = node->right;
					_alloc.destroy(node);
					_alloc.deallocate(node, 1);
					_size--;
					return tmp;
				}
				else if (node->right == nullptr)
				{
					tmp = node->left;
					_alloc.destroy(node);
					_alloc.deallocate(node, 1);
					_size--;
					return tmp;
				}
				node->value = node->left->getMax()->value;
				node->left = remove(node->value, node->left);
			}
			node->updateHeight();
			return applyRotation(node);
		}
		void	reset_parents()
		{
			_root->parent = nullptr;
			reset_parents(_root);
		}
		void	reset_parents(node_type *node)
		{
			if (node == nullptr)
				return ;
			if (node->left)
				node->left->parent = node;
			if (node->right)
				node->right->parent = node;
			reset_parents(node->left);
			reset_parents(node->right);
		}
		void	clear_tree(node_type *node)
		{
			if (node == nullptr)
				return ;
			clear_tree(node->left);
			clear_tree(node->right);
			_alloc.destroy(node);
			_alloc.deallocate(node, 1);
			_size = 0;
		}
	};
};