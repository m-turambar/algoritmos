#include <vector>
#include <set>
#include <iostream>

using namespace std;

class Solution {
public:
    bool canJump(vector<int>& nums) {
        auto& v = nums;
        const int last = v.size() - 1;
        if(last <= 0)
            return true;
        
        set<int> valid;
        for(int i=last-1; i>=0; --i)
        {
            int val = v[i];
            if(i + val >= last) {
                valid.insert(i);
                continue;
            }
            else if(val == 0) {
                continue;
            }
            else 
            {  
                //if(any_of(valid.begin(), valid.end(), greater(i + val))
                for(int e : valid)
                {
                    if(i + val >= e)   
                    {
                        valid.insert(i);
                        break;
                    }
                }
            }
        }
        
        return valid.find(0) != valid.end();
    }
};

int main()
{
    vector<int> v = {0, 2, 3};
    Solution s;
    bool b = s.canJump(v);
    cout << b;
    return 0;
}