#include <iostream>
#include <map>
#include <vector>

using namespace std;

class Solution {
public:
    int jump(vector<int>& nums) {
		if(nums.size() <= 1)
			return 0;
        return brincar(nums, 0);
    }
    
    int brincar(vector<int>& v, int ii)
    {
        static std::map<int,int> cache;
        if(cache.find(ii) != cache.end())
            return cache[ii];
        
        const int sz = v.size();
        int j = v[ii];
        
		// -1 porque el problema quiere en llegar al último índice. 
		// En pocas palabras el valor del último índice no importa
        int costo = (j >= sz - ii - 1) ? 1 : INT_MAX;
        
        if(costo == 1) {
            cache[ii] = 1;
            return costo;
        }
        
        for(int i=j; i>0; --i)
        {
            costo = std::min(brincar(v, ii+i), costo);
			if(costo == 1)
				break;
        }
        
		costo = (costo == INT_MAX) ? INT_MAX : costo + 1;
        cache[ii] = costo;
        return costo;
    }
};

int main()
{
	vector<int> test = {1,2};
	Solution sol;
	cout << sol.jump(test);
	
	return 0;
}