class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid)
    {
        if(grid.empty())
            return 0;
     int total=0,count=0;
        queue<pair<int,int>>q;
        for(int i=0;i<grid.size();i++)
        {
         for(int j=0;j<grid[0].size();j++)
        {   
             if(grid[i][j]!=0)
                 total++;
             if(grid[i][j]==2)
             {
                 q.push({i,j});
             }
        }
            
    }
        int dx[4]={0,1,0,-1};
        int dy[4]={1,0,-1,0};
        int days=0;
        while(!q.empty())
        {
            int k=q.size();
            count=count+k;
            while(k--)
            {
            int x=q.front().first;
            int y=q.front().second;
            q.pop();
            for(int d=0;d<4;d++)
            {
                int i=x+dx[d];
                int j=y+dy[d];
                if(i>=0 &&j>=0 &&i<grid.size()&&j<grid[0].size())
                {
                    if(grid[i][j]==1)
                    {
                    grid[i][j]=2;
                    q.push({i,j});
                    }
                }
            }
                }
            if(!q.empty())
                days++;
            }
        if(count==total)
            return days;
        else return -1;
    }
};