class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string>ans;
        unordered_map<string,int>mp;
        int j=0;
        string res="";
        while(j<s.size())
        {
            res+=s[j];
            if(res.size()==10)
            {
                mp[res]++;
                res.erase(0,1);
            }
          j++;
        } 
        for(auto x:mp)
        if(x.second>1)
        ans.push_back(x.first);
        return ans;      
    }
};