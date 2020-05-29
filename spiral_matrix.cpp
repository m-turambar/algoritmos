#include "util.hpp"

using namespace std;

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        auto& m = matrix;
		if(m.size()==0)
            return std::vector<int>();
        int sz = matrix.size() * matrix[0].size();
        vector<int> res;
        int ii=0;
        int jj=0;
        int w = matrix[0].size();
        int h = matrix.size();
        //es importante que puedes encontrar condiciones de salida en cualquier dirección, dependiendo de
        //las dimensiones de la matriz.
        while(sz > 0) {
            for(int j=jj; j < w-jj; ++j, --sz)
                res.push_back(m[ii][j]);
            if(sz <= 0)
                break;
            
            //bajamos desde la esquina superior derecha
            for(int i=ii+1; i<h-ii; ++i, --sz)
                res.push_back(m[i][w-jj-1]);
            if(sz <= 0)
                break;
            
            for(int j=w-jj-2; j>=jj; --j, --sz)
                res.push_back(m[h-ii-1][j]);
            
            if(sz <= 0)
                break;
            
            //aquí cambia a > en lugar de >=
            for(int i=h-ii-2; i>ii; --i, --sz)
                res.push_back(m[i][jj]); //ahí está la simetría
            ++ii;
            ++jj;
        }
        return res;
    }
};

int main()
{
	vector<vector<int>> mat = {
		{1,2,3,4,5},
		{6,7,8,9,10},
		{11,12,13,14,15},
		{16,17,18,19,20},
		{21,22,23,24,25}
	};
	vector<vector<int>> m2 = {
		{1,2,3},
		{4,5,6},
		{7,8,9}
	};
	Solution sol;
	auto r = sol.spiralOrder(m2);
	cout << r << endl;
	return 0;
}