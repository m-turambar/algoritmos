#include <iostream>
#include <vector>
#include <limits>
#include <cmath>

using namespace std;

template<typename T>
ostream& operator<<(ostream& os, vector<T> vec)
{
	os << "{";
	for(auto& e : vec)
		os << e << " ";
	os << "}\n";
	return os;
}



int reverse(int x) {
	vector<int> v; //digits
	while(x != 0)
	{
		v.push_back(x % 10);
		x /= 10;
	}
	
	cout << v;
	
	long long l=0;
	int mul = v.size()-1;
	for(auto i : v)
	{
		l += i*std::pow(10, mul);
		--mul;
	}
	
	int max = std::numeric_limits<int>::max();
	bool b = abs(l) > abs(max);
	return b ? 0 : l;
}


int main(int argc, char** argv)
{
	int n = -2147483648;
	
	cout << reverse(n);
	
	
	
	return 0;
}