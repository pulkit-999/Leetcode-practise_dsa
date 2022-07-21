class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) 
    {
        int n=gas.size();
      int total_gas=0,total_cost=0;
        for(int i=0;i<n;i++)
        {
            total_gas+=gas[i];
                total_cost+=cost[i];
        }
        if(total_gas<total_cost)
        return -1;
        int net=0;int index=0;
        for(int i=0;i<n;i++)
        {
            net=net+gas[i]-cost[i];
            if(net<0)
            {
             index=i+1;
                net=0;
            }
        }
        return index;
     
    }
};