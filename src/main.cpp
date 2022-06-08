#include <memory>
#include <iostream>
#include <algorithm>
#include "ft_containers.hpp"

// int	main( void ) {
// 	std::vector<int> t;

// 	for (int i = 0; i < 10; i++)
// 		t.push_back(-2);
	
// 	ft::reverse_iterator<std::vector<int>::iterator> rbegin(t.end());
// 	ft::reverse_iterator<std::vector<int>::iterator> rend(t.begin());

// 	std::cout << "====> REVERSE_ITERATOR <====" << std::endl << std::endl;
// 	std::cout << "Comparaisons" << std::endl;
// 	std::cout << "==" << std::endl;
// 	std::cout << (rbegin == rend) << std::endl;
// 	std::cout << (t.rbegin() == t.rend()) << std::endl;

// 	std::cout << "!=" << std::endl;
// 	std::cout << (rbegin != rend) << std::endl;
// 	std::cout << (t.rbegin() != t.rend()) << std::endl;

// 	std::cout << "<" << std::endl;
// 	std::cout << (rbegin < rend) << std::endl;
// 	std::cout << (t.rbegin() < t.rend()) << std::endl;

// 	std::cout << "<=" << std::endl;
// 	std::cout << (rbegin <= rend) << std::endl;
// 	std::cout << (t.rbegin() <= t.rend()) << std::endl;

// 	std::cout << ">" << std::endl;
// 	std::cout << (rbegin > rend) << std::endl;
// 	std::cout << (t.rbegin() > t.rend()) << std::endl;

// 	std::cout << ">=" << std::endl;
// 	std::cout << (rbegin >= rend) << std::endl;
// 	std::cout << (t.rbegin() >= t.rend()) << std::endl;

// 	std::cout << "* and +" << std::endl;
// 	std::cout << *(rbegin + 1) << std::endl;
// 	std::cout << *(t.rbegin() + 1) << std::endl;

// 	std::cout << "* and -" << std::endl;
// 	std::cout << *(rend - 1 - 1) << std::endl;
// 	std::cout << *(t.rend() - 1 - 1) << std::endl;

// 	std::cout << "riter - riter" << std::endl;
// 	std::cout << rend - rbegin << std::endl;
// 	std::cout << t.rend() - t.rbegin() << std::endl;

// 	ft::vector_iterator<int> begin(t.begin().base());
// 	ft::vector_iterator<int> end(t.end().base());

// 	std::cout << "====> VECTOR_ITERATOR <====" << std::endl << std::endl;
// 	std::cout << "Comparaisons" << std::endl;
// 	std::cout << "==" << std::endl;
// 	std::cout << (begin == end) << std::endl;
// 	std::cout << (t.begin() == t.end()) << std::endl;

// 	std::cout << "!=" << std::endl;
// 	std::cout << (begin != end) << std::endl;
// 	std::cout << (t.begin() != t.end()) << std::endl;

// 	std::cout << "<" << std::endl;
// 	std::cout << (begin < end) << std::endl;
// 	std::cout << (t.begin() < t.end()) << std::endl;

// 	std::cout << "<=" << std::endl;
// 	std::cout << (begin <= end) << std::endl;
// 	std::cout << (t.begin() <= t.end()) << std::endl;

// 	std::cout << ">" << std::endl;
// 	std::cout << (begin > end) << std::endl;
// 	std::cout << (t.begin() > t.end()) << std::endl;

// 	std::cout << ">=" << std::endl;
// 	std::cout << (begin >= end) << std::endl;
// 	std::cout << (t.begin() >= t.end()) << std::endl;

// 	std::cout << "* and +" << std::endl;
// 	std::cout << *(begin + 1) << std::endl;
// 	std::cout << *(t.begin() + 1) << std::endl;

// 	std::cout << "* and -" << std::endl;
// 	std::cout << *(end - 1 - 1) << std::endl;
// 	std::cout << *(t.end() - 1 - 1) << std::endl;

// 	std::cout << "iter - iter" << std::endl;
// 	std::cout << end - begin << std::endl;
// 	std::cout << t.end() - t.begin() << std::endl;

// 	std::cout << std::endl << "====> PAIR <====" << std::endl << std::endl;
// 	ft::pair<int, int>	p1(2, 2);
// 	ft::pair<int, int>	p2(42, 42);
// 	std::pair<int, int>	p3(2, 2);
// 	std::pair<int, int>	p4(42, 42);

// 	std::cout << "Comparaisons" << std::endl;
// 	std::cout << "==" << std::endl;
// 	std::cout << (p1 == p2) << std::endl;
// 	std::cout << (p3 == p4) << std::endl;

// 	std::cout << "!=" << std::endl;
// 	std::cout << (p1 != p2) << std::endl;
// 	std::cout << (p3 != p4) << std::endl;

// 	std::cout << "<" << std::endl;
// 	std::cout << (p1 < p2) << std::endl;
// 	std::cout << (p3 < p4) << std::endl;

// 	std::cout << "<=" << std::endl;
// 	std::cout << (p1 <= p2) << std::endl;
// 	std::cout << (p3 <= p4) << std::endl;

// 	std::cout << ">" << std::endl;
// 	std::cout << (p1 > p2) << std::endl;
// 	std::cout << (p3 > p4) << std::endl;

// 	std::cout << ">=" << std::endl;
// 	std::cout << (p1 >= p2) << std::endl;
// 	std::cout << (p3 >= p4) << std::endl;

// 	std::cout << std::endl << "====> VECTOR <====" << std::endl << std::endl;
// 	ft::vector<int> t2;
// 	std::vector<int> empty;
// 	std::cout << t.max_size() << std::endl;
// 	std::cout << t2.max_size() << std::endl;
// 	for (int i = 0; i < 5; i++)
// 		empty.push_back(-2);
	
// 	for (std::vector<int>::iterator it = empty.begin(); it != empty.end(); it++)
// 		std::cout << *it << ", ";
// 	std::cout << std::endl << (empty < t) << std::endl;
// 	std::cout << empty.capacity() << std::endl;
// 	empty.erase(empty.begin(), empty.end());
// 	for (std::vector<int>::iterator it = empty.begin(); it != empty.end(); it++)
// 		std::cout << *it << ", ";
// 	std::cout << std::endl << empty.capacity() << std::endl;
// 	// std::cout << empty.front() << std::endl;
// 	// std::cout << empty.back() << std::endl;
// 	// std::cout << t2.front() << std::endl;
// 	// std::cout << t2.back() << std::endl;
// }
