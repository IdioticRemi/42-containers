/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.hpp                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:10:56 by kbarbry           #+#    #+#             */
/*   Updated: 2022/06/14 15:50:57 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once


namespace ft
{
	template < class Key, class T, class Compare = std::less<Key>, class Alloc = allocator<pair<const Key,T> > >
	class map
	{
	public:
		typedef Key     									key_type;
		typedef T       									mapped_type;
		typedef ft::pair<key_type, mapped_type> 			value_type;
		typedef Compare     								key_compare;
		class												value_compare;
		typedef Alloc										allocator_type;
		typedef typename allocator_type::reference			reference;
		typedef typename allocator_type::const_reference	const_reference;
		typedef typename allocator_type::pointer			pointer;
		typedef typename allocator_type::const_pointer		const_pointer;
	private:
		allocator_type							_alloc;
		Compare									_cmp;
		Binary_search_tree<value_type, Compare>	_tree;
	};
}
