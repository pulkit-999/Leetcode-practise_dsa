class Solution {
public:
    vector<vector<int>> largestLocal(vector<vector<int>>& grid) 
    {
        vector<vector<int>>ans(grid.size()-2);
        for(int i=0;i<grid.size()-2;i++)
        {
            for(int j=0;j<grid.size()-2;j++)
        {
                int maxi=-1e9;
            for(int k=j;k<j+3;k++)
            {
                maxi=max(maxi,grid[i][k]);
                 maxi=max(maxi,grid[i+1][k]);
                 maxi=max(maxi,grid[i+2][k]);
            }
                ans[i].push_back(maxi);
        }
    }
       return ans; 
    }
};