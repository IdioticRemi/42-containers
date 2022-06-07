#include <memory>
#include <iostream>
#include <algorithm>
#include "../inc/TStack.hpp"

int	main( void ) {
	ft::stack<int>	vect;

	std::cout << "Stack Part" << std::endl;
	vect.push(12);
	vect.pop();
	vect.push(12);
	vect.push(13);
	std::cout << vect.size() << std::endl;
	std::cout << vect.top() << std::endl;
	std::cout << vect.empty() << std::endl;
	std::cout << vect.size() << std::endl;

}
