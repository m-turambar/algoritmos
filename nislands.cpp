#include <iostream>
#include <vector>

using namespace std;

void explore(vector<vector<int>>& island, vector<vector<int>>& visited, int i, int j, int id)
{
    if(i < 0 || i >= island.size() || j < 0 || j >= island[0].size())
        return;
    /* we already visited this node*/
    if(visited[i][j] != 0)
        return;
    
    /* mark as visited, and explore adjacent guys*/
    visited[i][j] = id;
    
    if(island[i][j] != 1)
        return;
    
    /* so here we know we're visiting a '1' value. */
    explore(island,visited, i-1, j);
    explore(island,visited, i+1, j);
    explore(island,visited, i, j-1);
    explore(island,visited, i, j+1);
}

int nislands(vector<vector<int>>& island)
{
    int cnt = 0; //our return value
    int id = 2;
    
    if(island.size() == 0)
        return 0;
        
    const int nrows = island.size();
    const int ncols = island[0].size();
    
    vector<vector<int>> visited(nrows);
    vector<int> zeros(ncols);
    for(int i; i<zeros.size(); ++i)
        zeros[i] = 0;
        
    for(int i=0; i<nrows; ++i)
        visited[i] = zeros;
        
    /* search the island. If we find a 1, we brute force search in all directions for extra 1's.
    We mark in our copy matrix that we have visited a node. */
    for(int i=0; i<nrows; ++i)
    {
        for(int j=0; j<ncols; ++j)
        {
            if(visited[i][j] != 0)
                continue;
                
            /* node value 0: we keep going*/
            if(island[i][j] == 0)
            {
                visited[i][j] = -1;
                continue;
            }
            /* we hit a 1: lets explore all adjacent nodes*/
            else
            {
                ++cnt;
                explore(island,visited, i, j, id);
                ++id;
            }
        }
    }
    return cnt;
}

std::pair<int,int> idx_flip(vector<vector<int>>& visited)
{
    int idx_i=0;
    int idx_j=0;
    for(int i=0; i<visited.size(); ++i)
    {
        for(int j=0; j<visited[0].size(); ++j)
        {
            
        }
    }
    
}

int main() {
    // you can write to stdout for debugging purposes, e.g.
    std::cout << "This is a debug message" << std::endl;

    return 0;
}