#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

template<typename T>
ostream& operator<<(ostream& os, vector<T> vec)
{
	cout << '[';
	bool first = true;
	for(auto& e : vec)
	{
		if(!first)
			cout << ','; 
		cout << e;
		first = false;
	}
	cout << ']';
	return os;
}

class Solution {
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> solutions;
        
        for(int i=0; i<candidates.size(); ++i)
        {
            if(candidates[i] > target)
                break;
            vector<int> v;
            helper(candidates, solutions, v, target, i);    
        }
        return solutions;
    }
    
    void helper(vector<int>& candidates, vector<vector<int>>& sols, vector<int>& v, int target, int k)
    {
        for(int i=k; i<candidates.size(); ++i)
        {
            if(target < candidates[i])
            {
                break;
            }
            else if(target == candidates[i])
            {
                v.push_back(candidates[i]);
                sols.push_back(v);
                v.pop_back();
                break;
            }
            else
            {
                v.push_back(candidates[i]);
                helper(candidates, sols, v, target - candidates[i], i);
                v.pop_back();
            }
        }
    }
};

int main()
{
	Solution sol;
	vector<int> candidates {2,3,6,7};
	int target = 9;
	auto vv = sol.combinationSum(candidates, target);
	cout << vv << endl;
	return 0;
}