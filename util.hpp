#include <iostream>
#include <vector>
#include <array>

template<class T>
std::ostream& operator << (std::ostream& os, const std::vector<T>& v)
{
	os << "{";
	for(auto& e : v)
		os << e << " ";
	os << "}";
	return os;
}

template<typename T, const size_t N>
std::ostream& operator<<(std::ostream& os, const std::array<T,N> a)
{
	os << '[';
	for(auto& e : a)
		os << e << " ";
	os << ']';
	return os;
}