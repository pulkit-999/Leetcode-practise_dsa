class Solution {
public:
   void bfs(vector<vector<char>> grid,vector<vector<int>>&vis,int row,int col)
{
       int d[4][2] = {{1, 0}, {-1, 0}, {0, 1}, {0, -1}};
    vis[row][col]=1;
    queue<pair<int,int>>q;
    q.push({row,col});
    while(!q.empty())
    {
        int r=q.front().first;
        int c=q.front().second;
           q.pop();
      for(int k=0;k<4;k++)
      {
        
                int nr=r+d[k][0];
                int nc=c+d[k][1];
                if(nr>=0&&nr<grid.size()&&nc>=0&&nc<grid[0].size()&&grid[nr][nc]=='1' && !(vis[nr][nc]))
                {
                    vis[nr][nc]=1;
                    q.push({nr,nc});
                }
            }
        }
        
    
}

int numIslands(vector<vector<char>> grid)
{
    int n=grid.size();
    int m=grid[0].size();
 vector<vector<int>>vis(n,vector<int>(m,0));
 int count=0;
 for(int i=0;i<n;i++)
 {
     for(int j=0;j<grid[0].size();j++)
     {
         if(!vis[i][j]&&grid[i][j]=='1')
     {
         count++;
         bfs(grid,vis,i,j);
         
     }
     }
 }
 return count;
}
};