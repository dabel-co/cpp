#ifndef WHATEVER_HPP
# define WHATEVER_HPP

# include <iostream>
# include <string>
template <typename X>
void	swap(X &a, X &b)
{
	X temp = b;
	b = a;
	a = temp;
}
template <typename X>
X min(X &a, X &b)
{
	if (a < b)
		return a;
	return b;
}
template <typename X>
X max(X &a, X &b)
{
	if (a > b)
		return a;
	return b;
}
#endif