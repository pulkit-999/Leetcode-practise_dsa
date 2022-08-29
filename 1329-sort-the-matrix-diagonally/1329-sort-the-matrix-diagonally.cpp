class Solution {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>>& mat) 
    {
        int m=mat.size();
        int n=mat[0].size();
        map<int,priority_queue<int,vector<int>,greater<int>>>ma; 
       
        vector<vector<int>>ans(m,vector<int>(n));
        for(int i=0;i<mat.size();i++)
        {
            for(int j=0;j<mat[0].size();j++)
            {
                ma[i-j].push(mat[i][j]);
            }
        }
        
            for(int i=0;i<m;i++)
            {
                for(int j=0;j<n;j++)
                {
                    ans[i][j]=ma[i-j].top();
                    ma[i-j].pop();
                }
                
            }
        
        return ans;
    }
};