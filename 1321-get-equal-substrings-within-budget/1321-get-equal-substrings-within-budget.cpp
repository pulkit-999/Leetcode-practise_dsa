class Solution {
public:
    int equalSubstring(string s, string t, int maxCost) {
        int cnt=0;
        int n=s.size();
        int i=0,j=0;
        int maxi=0;
        while(j<n)
        {
            maxCost=maxCost-abs(s[j]-t[j]);
            if(maxCost>=0)
            maxi=max(maxi,j-i+1);
            while(maxCost<0)
            {
                maxCost+=abs(s[i]-t[i]);
                i++;
            }
            j++;
        }
        return maxi;
    }
};