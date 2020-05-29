#include <iostream>
#include <vector>
#include "util.h"

using namespace std;

vector<vector<int>> create_matrix(vector<int> ver, vector<int> hor)
{
    int w = hor.size();
    int h = ver.size();
    
    vector<vector<int>> res(h);
    for(int i=0; i<h; ++i)
        res[i].resize(w);
    
    res[0][0] = 0;
    
    /* leftmost col*/
    for(int i=1; i<h; ++i)
        res[i][0] = abs(ver[i] - hor[0]) + res[i-1][0];
    
    /* bottom row*/
    for(int i=1; i<w; ++i)
        res[0][i] = abs(ver[0] - hor[i]) + res[0][i-1];
    
    for(int i=1; i<h; ++i)
    {
        for(int j=1; j<w; ++j)
        {
            int val = abs(ver[i] - hor[j]);
            int left = res[i][j-1];
            int down = res[i-1][j];
            int dia = res[i-1][j-1];
            int sum = min(left, down);
            sum = min(sum, dia);
            
            res[i][j] = val + sum;
        }
    }
    return res;
}

vector<vector<int>> flip_vertically(vector<vector<int>>& m)
{
    vector<vector<int>> f;
    for(int i=m.size()-1; i>=0; --i)
        f.push_back(m[i]);
    return f;
}

int main()
{
    vector<int> unk = {7,15,15,18,10,10,10,1,1};
    vector<int> george = {7,5,15,18,18,7,7,3};
    vector<int> georgia = {7,5,15,18,18,7,7,9,1};
    //vector<int> exh = {1,6,2,3,0,9,4,3,6,3};
    //vector<int> exv = {1,3,4,9,8,2,1,5,7,3};
    auto res = create_matrix(unk, georgia);
    //auto res = create_matrix(exv, exh);
    
    
    auto f = flip_vertically(res);
    cout << "\n\n\n";
    for(auto& v : f)
        cout << v;
    
    return 0;
}