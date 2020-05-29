#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
  int searchInsert(vector<int>& nums, int target) {
    int r=nums.size()-1;
    int l = 0;
    if(target < nums[l])
      return 0;
    if(target > nums[r])
      return r+1;
    int idx=0;
    while(l <= r)
    {
      idx = (l + r)/2;
      int val = nums[idx];
      if(val == target)
        return idx;
      else if(val < target)
      {
        l = idx+1;
      }

      else
      {
        r = idx-1;
      }

    }
    return idx;
  }
};

int main()
{
  Solution sol;
  vector<int> asdf = {1,3,5,6};
  sol.searchInsert(asdf, 2);

  return 0;
}
