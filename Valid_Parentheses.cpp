// si llega un char que abre, siempre estamos validos
// si llega un char que cierra, solo seguimos validos si el char cierra al top()
#include <stack>
#include <iostream>

using namespace std;


class Solution {
public:
    bool isValid(string s) {
        
        stack<char> st;
        
        for(char c : s)
        {
            if(c == '(' || c == '{' || c == '[' )
            {
                st.push(c);
            }
            else
            {
                if(st.empty())
                    return false;
                char t = st.top();
                if(t == '{' && c == '}')
                    st.pop();
                else if(t == '[' && c == ']')
                    st.pop();
                else if(t == '(' && c == ')')
                    st.pop();
                else
                    return false;
            }
        }
        
        return st.empty();
    }
};

int main()
{
    Solution sol;

    string test = "()";

    return sol.isValid(test);
}