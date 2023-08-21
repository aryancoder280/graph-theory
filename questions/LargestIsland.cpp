#include<bits/stdc++.h>
using namespace std;

int dfs(int i,int j,vector<vector<int>>grid,int n,int m,set<pair<int,int>>&visited) {

        int up = 0,down= 0,left = 0,right = 0;
        if(i-1>=0 && grid[i-1][j] == 1 && visited.find({i-1,j}) == visited.end()) {
            visited.insert({i-1,j});
            up = dfs(i-1,j,grid,n,m,visited);
        }
        if(i+1<n && grid[i+1][j] == 1 && visited.find({i+1,j}) == visited.end()) {
            visited.insert({i+1,j});
            down = dfs(i+1,j,grid,n,m,visited);
        }
        if(j-1>=0 && grid[i][j-1] == 1 && visited.find({i,j-1}) == visited.end()) {
            visited.insert({i,j-1});
            left = dfs(i,j-1,grid,n,m,visited);
        }
        if(j+1<m && grid[i][j+1] == 1 && visited.find({i,j+1}) == visited.end()) {
            visited.insert({i,j+1});
            right = dfs(i,j+1,grid,n,m,visited);
        }
        return up+left+right+down+1;
}

int maxAreaOfIsland(vector<vector<int>> grid)
{
    int n = grid.size();
    int m = grid[0].size();
    int ans = 0;
    set<pair<int,int>>visited;
    for(int i=0;i<n;i++) {
        for(int j=0;j<m;j++) {
            if(grid[i][j]) {
                visited.insert({i,j});
                ans = max(ans,dfs(i,j,grid,n,m,visited));
            }
        }
    }
    return ans;
}

int main() {
    vector<vector<int>>grid = {
  {0, 0, 0, 1, 0},
  {0, 0, 0, 1, 0},
  {0, 0, 0, 1, 0},
  {0, 0, 0, 1, 0},
  {0, 0, 0, 1, 0}
};
cout<<maxAreaOfIsland(grid);
}
