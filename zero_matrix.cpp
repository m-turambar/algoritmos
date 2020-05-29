#include <vector>
#include "util.h"

using namespace std;

void setZeroes(vector<vector<int>>& matrix) {
	auto& m = matrix;
	
	const int h = m.size();
	
	if(h == 0)
		return;
	
	const int w = m[0].size();
	
	for(int i=0; i<h; ++i)
		for(int j=0; j<w; ++j)
			if(m[i][j] == 0)
			{
				m[0][j] = 0;
				m[i][0] = 0;
			}
	
	for(int i=1; i<h; ++i)
		if(m[i][0] == 0)
			for(int j=0; j<w; ++j)
				m[i][j] = 0;
	
	for(int j=1; j<w; ++j)
		if(m[0][j] == 0)
			for(int i=0; i<h; ++i)
				m[i][j] = 0;
	if(m[0][0] == 0)
	{
		for(int i=0; i<h; ++i)
			m[i][0] = 0;
		for(int j=0; j<w; ++j)
			m[0][j] = 0;
	}
}

int main()
{
	vector<vector<int>> m = {{0,1,2,0}, {3,4,5,2}, {1,3,1,5}};
	setZeroes(m);
	cout << m;
}