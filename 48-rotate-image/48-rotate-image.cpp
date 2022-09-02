class Solution {
public:
    void rotate(vector<vector<int>>& matrix) 
    {
        int n=matrix.size();
        vector<vector<int>>ans(n,vector<int>(n,0));
        int k=0;
        for(int i=0;i<matrix.size();i++)
        {
            k=0;
            for(int j=n-1;j>=0;j--)
            {
                ans[i][k++]=matrix[j][i];
            }
        }
        matrix.clear();
        matrix=ans;
    }
    
};