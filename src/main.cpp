#include <iostream>

#include "../inc/avl_tree.hpp"
#include <map>
int		main(void)
{
	ft::avl_tree<int, std::less<int> > tree;

	for (int i = 1; i < 200; ++i)
	{
		std::cout << "INSERT: " << i << "\n";
		tree.insert(i);
	}
	for (int i = 50; i < 100; ++i)
		tree.remove(i);
	for (int i = 75; i < 150; ++i)
		tree.insert(i);
	for (int i = 195; i < 205; ++i)
		tree.remove(i);
	// tree.print_tree();
	// tree.print_tree();
	tree.insert(6);
	for (int i = 1; i < 7; ++i)
	{
		tree.remove(i);
		// tree.print_tree();
	}
	for (int i = 1; i < 16; ++i)
	{
		tree.remove(i);
	}
	std::cout << tree.getSize() << std::endl;
	// tree.print_tree();

	std::cout << "FINISHED" << "\n";
	return (0);
}
