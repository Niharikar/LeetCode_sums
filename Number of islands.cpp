#include<iostream>
using namespace std;

void fun(vector< vector<char> >& grid,int x,int y)
{
    grid[x][y] = -1;
    
    if(x-1 >=0 && grid[x-1][y]=='1')
      fun(grid,x-1,y);
    if(x+1 < grid.size() && grid[x+1][y]=='1')
      fun(grid,x+1,y);
    if(y-1 >= 0 && grid[x][y-1]=='1')
      fun(grid,x,y-1);
    if(y+1 < grid.size() && grid[x][y+1]=='1')
      fun(grid,x,y+1);
}

int numIslands(vector< vector<char> >& grid)
{
  int count = 0;
  for(int i = 0;i<grid.size;i++)
  {
    for(int j = 0;j<grid[0].size();j++)
    {
        if(grid[i][j]=='1')
        {
          count++;
          fun(grid,i,j);
        }
    }
  }
}
