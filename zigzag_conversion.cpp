#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:
    string convert(string s, int numRows) {
        vector<string> v(numRows);
        int idx = 0;
        int add = 1;
        int cnt = 0;
        
        
        for(char c : s)
        {
            cout <<  c << ", idx:" << idx << " cnt:" << cnt << endl;
            v[idx] += c;
            ++cnt;
            idx += add;
            if(cnt + 1 == numRows)
            {
                cnt = 0;
                add = add*-1;
            }
            
        }
        string res;
        for(auto& s : v)
        {
            cout << s << endl;
            res += s;
        }
           
        return res;
    }
};

int main()
{
    string test = "PAYPALISHIRING";
    Solution sol;
    string res = sol.convert(test, 3);
    cout << res << endl;
    return 0;
}