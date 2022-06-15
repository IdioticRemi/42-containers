#include <memory>
#include <iostream>
#include <algorithm>
#include "ft_containers.hpp"

int		main(void)
{
	ft::avl_tree<int, std::less<int> > tree;

	for (int i = 0; i < 10; ++i)
		tree.insert(i);
	tree.print_l_to_r();
	return (0);
}
