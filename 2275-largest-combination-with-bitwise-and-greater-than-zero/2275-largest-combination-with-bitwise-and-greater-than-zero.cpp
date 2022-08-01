class Solution {
public:
    int largestCombination(vector<int>& candidates) 
    {
        int c=0,maxi=0;
         for(int i=0;i<32;i++)
    {
             c=0;
    for(int j=0;j<candidates.size();j++)
    {
        if(candidates[j]>>i&1)
        c++;
    }
              maxi=max(maxi,c);
        
    }
        
        return maxi;
    }
};