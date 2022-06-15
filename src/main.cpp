#include <iostream>

#include "../inc/avl_tree.hpp"

int		main(void)
{
	ft::avl_tree<int, std::less<int> > tree;

	for (int i = 1; i < 200; ++i)
	{
		// std::cout << "INSERT: " << i << "\n";
		tree.insert(i);
	}
	for (int i = 50; i < 100; ++i)
		tree.remove(i);
	for (int i = 75; i < 150; ++i)
		tree.insert(i);
	for (int i = 195; i < 205; ++i)
		tree.remove(i);
	tree.print_tree();
	for (int i = -5; i < 200; ++i)
		tree.remove(i);
	// tree.print_tree();
	// tree.insert(6);
	// for (int i = 1; i < 7; ++i)
	// {
	// 	tree.remove(i);
	// 	tree.print_tree();
	// }
	// for (int i = 1; i < 16; ++i)
	// {
	// 	tree.remove(i);
	// }
	// tree.print_tree();

	// ft::avl_tree<int, std::less<int> > tree2;
	// for (int i = 150; i > 0; --i)
	// {
	// 	// std::cout << "INSERT: " << i << "\n";
	// 	tree2.insert(i);
	// 	// tree2.print2();
	// }
	// // tree2.print2();
	// std::cout << "FINISHED\n";
	// tree2.print_tree();
	return (0);
}
