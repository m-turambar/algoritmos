#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> solution(int N) {
    vector<int> res;
    
    /* we insert n/2 pairs of negative/positive numbers, and if N is odd, we add a 0. 
     all the numbers will be unique this way. This is the same problem that was assigned to me last time. */
    for(int i=0; i<N/2; ++i)
    {
        res.push_back(-(i+1));
        res.push_back((i+1));
    }
    
    if(N % 2 == 1)
    {
        res.push_back(0);   
    }
    
    return res;
}

int main(int argc, char **argv)
{
    int N = atoi(argv[1]);
    vector<char> v(N);
    
    for(char i : v)
        cout << i << " ";

    return 0;
}
