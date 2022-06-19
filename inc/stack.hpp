/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack.hpp                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbarbry <kbarbry@student.42lyon.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/11 10:10:38 by kbarbry           #+#    #+#             */
/*   Updated: 2022/06/15 12:43:32 by kbarbry          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#pragma once

#include <vector.hpp>

namespace ft
{
	template <class T, class Container = ft::vector<T> >
	class stack
	{
	public:
		typedef T			value_type;
		typedef Container	container_type;
		typedef size_t		size_type;

		explicit stack(const container_type &container_t = container_type()) : container(container_t){};
		~stack(void){};

		bool empty(void) const
		{
			return (this->container.empty());
		}

		size_type size(void) const
		{
			return (this->container.size());
		}

		value_type &top(void)
		{
			return (this->container.back());
		}

		const value_type &top(void) const
		{
			return (this->container.back());
		}

		void push(const value_type &val)
		{
			this->container.push_back(val);
		}

		void pop(void)
		{
			this->container.pop_back();
		}

		template <class TCompare, class ContainerCompare>
		friend bool operator==(const ft::stack<TCompare, ContainerCompare> &lhs, const ft::stack<TCompare, ContainerCompare> &rhs) { return (lhs.container == rhs.container); };

		template <class TCompare, class ContainerCompare>
		friend bool operator!=(const ft::stack<TCompare, ContainerCompare> &lhs, const ft::stack<TCompare, ContainerCompare> &rhs) { return (lhs.container != rhs.container); };

		template <class TCompare, class ContainerCompare>
		friend bool operator<(const ft::stack<TCompare, ContainerCompare> &lhs, const ft::stack<TCompare, ContainerCompare> &rhs) { return (lhs.container < rhs.container); };

		template <class TCompare, class ContainerCompare>
		friend bool operator<=(const ft::stack<TCompare, ContainerCompare> &lhs, const ft::stack<TCompare, ContainerCompare> &rhs) { return (lhs.container <= rhs.container); };

		template <class TCompare, class ContainerCompare>
		friend bool operator>(const ft::stack<TCompare, ContainerCompare> &lhs, const ft::stack<TCompare, ContainerCompare> &rhs) { return (lhs.container > rhs.container); };

		template <class TCompare, class ContainerCompare>
		friend bool operator>=(const ft::stack<TCompare, ContainerCompare> &lhs, const ft::stack<TCompare, ContainerCompare> &rhs) { return (lhs.container >= rhs.container); };

	protected:
		container_type container;
	};
}