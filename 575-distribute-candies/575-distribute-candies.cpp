class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
       int count=0;
        int n = candyType.size();
        unordered_map<int,int> mp;
        for(int i=0;i<n;i++)
        {
            mp[candyType[i]]++;
        }
        int k = n/2;
        if(k<mp.size())
        {
            return k;
        }
        else
        {
            return mp.size();
        }
    }
};