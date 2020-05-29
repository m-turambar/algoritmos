#include <iostream>
#include <vector>
#include <map>
#include <set>
#include <sstream>
#include <cmath>

using namespace std;

ostream& operator<<(ostream& os, set<string> mset)
{
    os << "{\n";
    for(auto& s : mset)
        cout << "\t" << s << '\n';
    os << "}\n";
    return os;
}

template<typename T>
ostream& operator<<(ostream& os, map<string, T> mapa)
{
    os << " {\n";
    for(auto& p : mapa)
        cout << "\t" << p.first << ":" << p.second << '\n';
    os << "}\n";
    return os;
}

int main()
{
    

}