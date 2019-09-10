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

int removeElement(vector<int>& nums, int val) 
{
	int sz=nums.size();
	
	for(int i=0; i<sz; )
	{
		if(nums[i] == val)
		{
			nums.erase(nums.begin()+i);
			continue;
		}
		++i;
	}
	
	return nums.size();
}

int main()
{
	vector<int> vec = {3,2,2,3};
	
	int res = removeElement(vec, 2);
	
	cout << res;
	
	
	return 0;
}