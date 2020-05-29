#include <cmath>
#include <iostream>

class Solution {
public:
    int divide(int dividend, int divisor) {
        int cociente = 0;
        
        if(dividend > 0 && divisor > 0)
        for(int d = divisor; d < dividend; d += divisor)
            cociente++;
        
        if(dividend < 0 && divisor > 0)
        for(int d = divisor; d < abs(dividend); d += divisor)
            cociente--;
        
        if(dividend > 0 && divisor < 0)
        for(int d = divisor; d < abs(dividend); d += divisor)
            cociente--;
        
        if(dividend < 0 && divisor < 0)
        for(int d = divisor; d < abs(dividend); d += divisor)
            cociente++;
        
        return cociente;
    }
};

int main()
{
	Solution s;
	int d = s.divide(7,-3);
	std::cout << d;
	return 0;
}