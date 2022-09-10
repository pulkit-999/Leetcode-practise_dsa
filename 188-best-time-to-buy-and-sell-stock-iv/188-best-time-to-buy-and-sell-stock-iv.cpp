class Solution {
public:
    int maxProfit(int k, vector<int>& prices) 
    {
        int n=prices.size();
        vector<int>ahead(2*k+1,0);
          vector<int>cur(2*k+1,0);
        int j=2*k;
        for(int ind=n-1;ind>=0;ind--)
        {
            for(int trans=j-1;trans>=0;trans--)
            {
                if(trans%2==0)
                {
                    cur[trans]=max(-prices[ind]+ahead[trans+1],0+ahead[trans]);
                }
                else
                {
                    {
                    cur[trans]=max(prices[ind]+ahead[trans+1],0+ahead[trans]);
                } 
                }
            }
        ahead=cur;
        }
        return ahead[0];
    }
};