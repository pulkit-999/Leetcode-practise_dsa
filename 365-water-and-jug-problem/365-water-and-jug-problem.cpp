class Solution {
    
public:
    
    bool bfs(int x,int y,int z,vector<int>&vis,int src)
    {
        queue<int>q;
        int k=x+y;
        int d[4]={x,-x,-y,y};
        q.push(0);
        vis[0]=1;
        while(!q.empty())
        {
            int el=q.front();
            q.pop();
            if(el==z)
                return true;
        for(int i=0;i<4;i++)
        {
            int ans=el+d[i];
            if(ans==z)
                return true;
             if(ans<0 ||ans>k)
                continue;
            if(vis[ans]!=1)
            {
                q.push(ans);
                vis[ans]=1;
            }
        }
            }
        return false;
    }
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity)
    {
        int n=jug1Capacity+jug2Capacity;
        vector<int>vis( n+1,0);
        
        //for(int i=0;i<n;i++)
   return bfs(jug1Capacity,jug2Capacity,targetCapacity,vis,0); 
        // if(jug1Capacity+jug2Capacity<targetCapacity)
        return false;
        
    }
};